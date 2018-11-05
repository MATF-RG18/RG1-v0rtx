/**
 * @file main.c
 * @brief 
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-05
 */
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "draw.h"


#define ESC_KEY (27u)


static void gl_initalize(void);
static void callback_initalize(void);

static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int, int);

int main(int argc, char **argv){
 
  /* init glut*/
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);

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
 */
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
  gluLookAt(0.0, 2.0, -1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
  
  if(helper_flag){
    draw_coordinate_system();
    draw_grid_xz(1000);
  }
  glColor3f(1.0f, 1.0f, 1.0f);
  glutWireCube(0.1);
  glutSwapBuffers();
  glFlush();
}
