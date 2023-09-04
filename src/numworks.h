/*
 *
 * platform.h
 *
 * */

#ifndef NUMWORKS_H
#define NUMWORKS_H

#include "main.h"
#include <unistd.h>

#define PLAYGROUND_X 32
#define PLAYGROUND_Y 20 //18px top border, 20 * 10 playground and 22 px ottom border = 18 + 22 + 200 = 240
#define DEFAULT_SPEED 100
#define DEFAULT_MOVE_TIME 1
#define DEFAULT_LENGTH 5

// EVERY FUNCTION OF THIS FILE MUSTE BE DEFINED
void init_platform();
void gracefully_shutdown(char* message);


void print_at(int x, int y, char * text);
void draw_sth(int x, int y, DrawObject draw_object);
// to get a character but non blocking
Control get_control_non_blocking();
// To get a character but blocking
Control get_control_blocking();
void clear_screen();
int screen_x();
int screen_y();
void uni_sleep(int time_ms);
void draw_top_separator(int x);

#endif
