/*
 *
 * platform.h
 *
 * */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "main.h"
#include <ncurses.h>
#include <unistd.h>


void print_at(int x, int y, char * text);
// to get a character but non blocking
Control get_control();
void clear_screen();
int screen_x();
int screen_y();
void uni_sleep(int time_ms);

#endif
