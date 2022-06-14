/*

windows_controls.c

entry functions for windows

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "positions.h"
#include "init.h"
#include "game.h"

#define KEYBOARDHIT kbhit()
#define GETCHAR getch()





void getEvent(int *command)
{
    if (KEYBOARDHIT) {
        char event = GETCHAR;
            switch (event) {
            case 'z':
                *command = UP;
                break;
            
            case 'q':
                *command = LEFT;
                break;
            
            case 's':
                *command = DOWN;
                break;

            case 'd':
                *command = RIGHT;
                break;
            
            case 'p':
                *command = PAUSE;
                break;
            
            case 'x':
                *command = ENDGAME;
                break;

            case 'k':
                quit(3);
        }
    }  
}




void translateControl(int *orientation, int *command)
{
    switch (*command) {
        case UP:
            if (*orientation != 180) *orientation = 0;
            break;

        case LEFT:
            if (*orientation != 90) *orientation = 270;
            break;

        case DOWN:
            if (*orientation != 0) *orientation = 180;
            break;
 
        case RIGHT:
            if (*orientation != 270) *orientation = 90;
            break;
        
        case PAUSE:
            pauseLoop(command);
            break;
    }
}