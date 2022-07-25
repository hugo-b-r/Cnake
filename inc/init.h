/*

init.h

function for init and deinit

*/


#ifndef _INIT_H_
#define _INIT_H_

#if defined(WIN32)
    #define PLAYGROUND_X 35
    #define PLAYGROUND_Y 20
    #define DEFAULT_SPEED 100
    #define TIME clock()
    #define DEFAULT_MOVE_TIME 5
#elif defined(NUMWORKS)
    #define PLAYGROUND_X 32 
    #define PLAYGROUND_Y 19
    #define DEFAULT_SPEED 100
    #define TIME extapp_millis()
    #define DEFAULT_MOVE_TIME 1
#endif
#define DEFAULT_LENGTH 5

#define UP 0
#define LEFT 270
#define DOWN 180
#define RIGHT 90
#define PAUSE 361
#define ENDGAME 362
#define QUIT 363

#define SNAKE 0
#define FRUIT 1
#define NOTHING 2

void quit(int type);

#endif
