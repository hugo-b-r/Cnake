/*

entries.c

entry functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "init.h"
#include "buffer.h"
#include "game.h"




void getKeyboardEntry(char *command)
{
    if (KEYBOARDHIT) {
        *command = GETCHAR;
    }
}




void testEvents(int *orientation, char *command)
{ 
    switch (*command) {
    case 'z':
        if (*orientation != 180) {
            *orientation = 0;
        }
        break;

    case 'q':
        if (*orientation != 90) {
            *orientation = 270;
        }
        break;

    case 's':
        if (*orientation != 0) {
            *orientation = 180;
        }
       break;
 
    case 'd':
        if (*orientation != 270) {
            *orientation = 90;
        }
        break;

    case 'x':
        quit(3);
        break;
        
    case 'p':
        pauseLoop(command);
        break;
    }
}