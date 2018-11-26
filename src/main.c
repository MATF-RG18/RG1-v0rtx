/**
sa:* @file main.c
 * @brief
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-05
 */
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "draw.h"
#include "window.h"
#include "error_handler.h"

#define ESC_KEY (27u)
#define TIMER_ID (0)
#define TIMER_INTERVAL (20)

static const char *game_name = "v0rtX";

static float jump_factor = 0.0;
static int animation_ongoing = 0;
static float translation_animation = 0.0f;
static float spin_animation = 0.0f;
static void gl_initalize(void);
static void callback_initalize(void);

static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int, int);
static void on_timer(int);
static void on_special(int, int, int);
int main(int argc, char **argv){
  /* todo: implement basic inits that this code wont be here */
  window_init(&my_window);
  set_width(&my_window, 800);
  set_height(&my_window, 600);
  set_pos_x(&my_window, 100);
  set_pos_y(&my_window, 100);
  /* init glut*/
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(my_window.width, my_window.height);
  glutInitWindowPosition(my_window.pos_x, my_window.pos_y);
  glutCreateWindow(game_name);
  /* register callback functions */
  callback_initalize();
  gl_initalize();

  glutMainLoop();

  return 0;
}

static void callback_initalize(void)
{
  glutDisplayFunc(on_display);
  glutKeyboardFunc(on_keyboard);
  glutReshapeFunc(on_reshape);
  glutSpecialFunc(on_special);
}
static void gl_initalize()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST | GL_LINE_SMOOTH);
  glLineWidth(1.0f);
  glPointSize(1.0f);
}
/* TODO:
 * 1) implement other key functions, like starting the game, and controls
 * 2) implement on_keyboard_up func
 */

 static void on_special(int key, int x, int y)
 {
   switch(key){
     case GLUT_KEY_F5:
       /* enter fullscreen mode if pressed once if not in fullscreen */
       if(!query_fullscreen(&my_window)){
          glutFullScreen();
          }
       // else{
       //  glutReshapeWindow(query_width(&my_window), query_height(&my_window));
       //  glutPositionWindow(query_pos_x(&my_window), query_pos_y(&my_window));
       //
       // }
       break;
   }


 }

static void on_timer(int value)
{
  if(value != TIMER_ID)
    return;

  spin_animation += 1.0f;
  translation_animation += 0.1f;
  jump_factor += 0.1;
  glutPostRedisplay();

  if(animation_ongoing)
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);


}
static void on_keyboard(unsigned char key, int x, int y)
{
  switch(key){
    case ESC_KEY:
       fprintf(stdout, "Exiting the game.\n");
       exit(EXIT_SUCCESS);
       break;
   case 'p':
   case 'P':
       if(!helper_flag){
         fprintf(stdout, "Enter debug mode!\n");
         glutPostRedisplay();
         helper_flag = 1;
       }
       break;
   case 'o':
   case 'O':
       if(helper_flag){
         fprintf(stdout, "Exit Debug mode!\n");
         glutPostRedisplay();
         helper_flag = 0;
       }
       break;
    case 'w':
      if(!animation_ongoing){
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        animation_ongoing = 1;
      }
      break;
    case 's':
      animation_ongoing = 0;
      break;
  }
}
/* done */
static void on_reshape(int width, int height)
{
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, width / (GLdouble)height, 0.1, 1000);
}

static void on_display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(1.0f, 2.0f, -2.5f + translation_animation, 0.0f, 0.0f, 1.0f + translation_animation, 0.0f, 1.0f, 0.0f);

  if(helper_flag){
    draw_coordinate_system();
    draw_grid_xz(1000);
  }

  /* implement function draw map */

  glPushMatrix();
      glScalef(1.0f,0.1f,1.0f);
      glTranslatef(0.0,-0.1,0.0);
      glColor3f(1.0,0.0,1.0);

      glutWireCube(1.0);
      for(int i = 0; i < 100; i++){
        glTranslatef(0.0, 0.0, 1.01);
        glutWireCube(1.0);
      }
  glPopMatrix();
  /* this one is player logic */
  /* player can move only left and right the rest is on timer */
  glPushMatrix();
    glTranslatef(0.0,0.2 + fabs(sin(jump_factor)),0.0 + translation_animation);
    glRotatef(spin_animation, 1.0, 0.0, 0.0);
    glColor3f(1.0,1.0,0.0);
    glutWireSphere(0.2, 30, 30);

  glPopMatrix();
  glutSwapBuffers();
  glFlush();
}
