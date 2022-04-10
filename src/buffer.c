/*

buffer.c

buffer operations

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"




void clearBuffer(char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y])
{
    for (int i = PLAYGROUND_Y - 1; i >= 0; i--) {

        for (int j = 0; j < PLAYGROUND_X; j++) {
            (*buffer)[j][i] = ' ';
        }
    }
}




void printBuffer(char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y])
{
    //print top border   
    for (int i = 0; i < PLAYGROUND_X + 2; i++) {
        printf("#");
    }
    printf("\n");
    
    for (int i = PLAYGROUND_Y - 1; i >= 0; i--) {
        
        printf("#");
        for (int j = 0; j < PLAYGROUND_X; j++) {
            printf("%c", (*buffer)[j][i]);
        }

        printf("#\n");
    }
    //printf bottom border
    for (int i = 0; i < PLAYGROUND_X + 2; i++) {
        printf("#");
    }
    printf("\n");
}


