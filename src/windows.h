/*
 *
 * platform.h
 *
 * */

#ifndef WINDOWS_H
#define WINDOWS_H

#include "main.h"
#include <unistd.h>

#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define DEFAULT_SPEED 100
#define TIME clock()
#define DEFAULT_MOVE_TIME 5
#define DEFAULT_LENGTH 5


void init_platform();
void gracefully_shutdown(char* message);


void print_at(int x, int y, char * text);
void draw_sth(int x, int y, DrawObject draw_object);
// to get a character but non blocking
Control get_control();
void clear_screen();
int screen_x();
int screen_y();
void uni_sleep(int time_ms);
void draw_top_separator(int x);

#endif
