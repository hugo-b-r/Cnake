/*

positions.c

functions for positions matrix manipulations

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"



void incrPos(int *tail_position, int *head_position, int length)
{
    (*head_position)++;
    if (*head_position >= length) {
        *head_position = 0;
    }
    (*tail_position)++;
    if (*tail_position >= length) {
        *tail_position = 0;
    }
}



void newPos(int *tail_position, int *head_position, int (*positions)[2][100], int orientation, int length)
{
    int x = (*positions)[0][*head_position];
    int y = (*positions)[1][*head_position];

    switch (orientation) {
    case 0:
        y += 1;
        break;
    case 90:
        x += 1;
        break;
    case 180:
        y -= 1;
        break;
    case 270:
        x -= 1;
        break;
    }


    //if on itself
    for (int i = 0; i < length+1; i++) {
        if (x == (*positions)[0][i] && y == (*positions)[1][i]) {
            quit(1);
        }
    }

    // if border
    if ( (x > PLAYGROUND_X-1) || (y > PLAYGROUND_Y-1) || (x < 0) || (y < 0) ) {
        quit(1); 
    }

    (*positions)[0][*tail_position] = x;
    (*positions)[1][*tail_position] = y;

    incrPos(tail_position, head_position, length);

}



