/**
 * @file window.h
 * @brief 
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-05
 */


#ifndef WINDOW_H
#define WINDOW_H

struct window_info{
  int is_fullscreen;
  int width, height;
  int pos_x, pos_y;
};

static struct window_info my_window;
/* initalize */
void window_init(struct window_info *w);
/* getters */
int query_fullscreen(struct window_info *w);
int query_width(struct window_info *w);
int query_height(struct window_info *w);
int query_pos_x(struct window_info *w);
int query_pos_y(struct window_info *w);
/* setters */
void set_pos_x(struct window_info *w, int pos_x);
void set_pos_y(struct window_info *w, int pos_y);
void set_fullscreen(struct window_info *w, int mode);
void set_width(struct window_info *w, int width);
void set_height(struct window_info *w, int height);
/* dump info */
void print_window_info(struct window_info *w);







#endif /*WINDOW_H*/
