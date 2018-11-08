/**
 * @file window.c
 * @brief 
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-08
 */

#include "window.h"
#include <stdio.h>
#include "error_handler.h"


static struct window_info my_window;

void window_init(struct window_info *w)
{
  w->is_fullscreen = 0;
  w->width         = 0;
  w->height        = 0;
  w->pos_x         = 0;
  w->pos_y         = 0;
}
int query_fullscreen(struct window_info *w)
{
  return w->is_fullscreen;
}
int  query_width(struct window_info *w)
{
  return w->width;
}
int query_height(struct window_info *w)
{
  return w->height;
}

int query_pos_x(struct window_info *w)
{
  return w->pos_x;
}

int query_pos_y(struct window_info *w)
{
  return w->pos_y;
}    

void set_pos_x(struct window_info *w, int pos_x)
{
  error_handler(pos_x >= 0, "Position x that you want to set must be positive!");
  w->pos_x = pos_x;
}

void set_pos_y(struct window_info *w, int pos_y)
{
  error_handler(pos_y >= 0, "Position y that you want to set must be positive!");
  w->pos_y = pos_y;
}
void set_fullscreen(struct window_info *w, int mode)
{
  /* just in case someone wants to be really smart and enter a number higher than 1 */
  error_handler(mode >= 0, "Fulscreen mode must be positive!");
  w->is_fullscreen = mode % 2;  
}
void set_width(struct window_info *w, int width)
{
  error_handler(width >=0, "Window with that you want to update must be positive!");
  w->width = width;
}
void set_height(struct window_info *w, int height)
{
  error_handler(height >= 0, "Window height that you want to update must be positive!");
  w->height = height;
}
void print_window_info(struct window_info *w)
{
  fprintf(stdout, "window_info dump: %d %d %d %d %d\n", w->is_fullscreen, w->width, w->height, w->pos_x, w->pos_y);
}



