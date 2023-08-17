/*

init.h

function for init and deinit

*/


#ifndef _INIT_H_
#define _INIT_H_


#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define DEFAULT_SPEED 100
#define TIME clock()
#define DEFAULT_MOVE_TIME 5
#include <ncurses.h>

#define DEFAULT_LENGTH 5

#define UP 0
#define LEFT 270
#define DOWN 180
#define RIGHT 90
#define PAUSE 361
#define ENDGAME 362
#define QUIT 363

// colors pairs
#define NORMAL_PAIR 1
#define WELCOME_PAIR 2

#define SNAKE 0
#define FRUIT 1
#define NOTHING 2

void init_platform();

void gracefully_shutdown(char* message);

#endif
