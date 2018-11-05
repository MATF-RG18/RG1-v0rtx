/**
 * @file draw.c
 * @brief 
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-05
 */

/* need to see how to link these seperate header files */
#include "draw.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
/* defining a helper flag, which will help us draw stuff(used only in debugging mode) */
unsigned char helper_flag = 0;

void draw_coordinate_system()
{

  glLineWidth(5.0f);
  glEnable(GL_LINE_SMOOTH);
  /* using arrays cause they are faster on some systems */
  const GLfloat coord_start[] = {0.0f, 0.0f, 0.0f};
  const GLfloat x_axis[]      = {1.0f, 0.0f, 0.0f};
  const GLfloat y_axis[]      = {0.0f, 1.0f, 0.0f};
  const GLfloat z_axis[]      = {0.0f, 0.0f, 1.0f};
  const GLfloat red_color[]   = {1.0f, 0.0f, 0.0f};
  const GLfloat green_color[] = {0.0f, 1.0f, 0.0f};
  const GLfloat blue_color[]  = {0.0f, 0.0f, 1.0f};
  
  glColor3fv(red_color);
  glBegin(GL_LINES);
    glVertex3fv(coord_start);
    glVertex3fv(x_axis);
  glEnd();
  
  glColor3fv(green_color);
  glBegin(GL_LINES);
    glVertex3fv(coord_start);
    glVertex3fv(y_axis);
  glEnd();

  glColor3fv(blue_color);
  glBegin(GL_LINES);
    glVertex3fv(coord_start);
    glVertex3fv(z_axis);
  glEnd();
  glLineWidth(1.0f);
}


void draw_grid_xz(int number)
{
  glLineWidth(3.0f);
  const GLfloat grayish_color[] = {0.75f, 0.75f, 0.75f};
  for(float i = -number; i < number; i+= 2.0f){
    glBegin(GL_LINES);
      glColor3fv(grayish_color);
      glVertex3f(-number, 0.0f, i);
      glVertex3f(number, 0.0f, i);
      glVertex3f(i, 0.0f, -number);
      glVertex3f(i, 0.0f, number);
    glEnd();
    }
  glLineWidth(1.0f);
}
void draw_grid_yz(int number)
{
  glLineWidth(3.0f);
  const GLfloat grayish_color[] = {0.75f, 0.75f, 0.75f};
  for(float i = -number; i < number; i+= 2.0f){
    glBegin(GL_LINES);
      glColor3fv(grayish_color);
      glVertex3f(0.0f, -number, i);
      glVertex3f(0.0f, number, i);
      glVertex3f(0.0f, i, -number);
      glVertex3f(0.0f, i, number);
    glEnd();
  } 
  glLineWidth(1.0f);
}
void draw_grid_xy(int number)
{
  glLineWidth(3.0f);
  const GLfloat grayish_color[] = {0.75f, 0.75f, 0.75f};
  for(float i = -number; i < number; i+= 2.0f){
    glBegin(GL_LINES);
      glColor3fv(grayish_color);
      glVertex3f(i, -number, 0.0f);
      glVertex3f(i, number, 0.0f);
      glVertex3f(-number, i, 0.0f);
      glVertex3f(number, i, 0.0f);
    glEnd();
  } 
 glLineWidth(1.0f);
}

