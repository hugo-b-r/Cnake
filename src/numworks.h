/*

    numworks.h
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#ifndef NUMWORKS_H
#define NUMWORKS_H

#include "main.h"
#include <unistd.h>

#define DEFAULT_SPEED 150 // The higher the slower
#define DEFAULT_MOVE_TIME 1
#define DEFAULT_LENGTH 5



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
