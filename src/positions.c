/*

positions.c

functions for positions matrix manipulations

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"




void newPosInjection(int *head_position, int length, int (*positions)[2][100], int x, int y) {
    
    if ( *head_position + 1 == length) {
        (*positions)[0][0] = x;
        (*positions)[1][0] = y;
    } else {
        (*positions)[0][*head_position + 1] = x;
        (*positions)[1][*head_position + 1] = y;
    }
}




void incrPos(int *head_position, int length)
{
    (*head_position)++;
    if (*head_position >= length) {
        *head_position = 0;
    }
}




void newPos(int *head_position, int (*positions)[2][100], int orientation, int length)
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
    for (int i = 0; i < length; i++) {
        if ( (x == (*positions)[0][i]) && (y == (*positions)[1][i]) ) {
            newPosInjection(head_position, length, positions, x, y);
            printf("\nYou can't go on yourself");
            quit(1);
        }
    }

    // if border
    if ( (x > (PLAYGROUND_X-1)) || (y > (PLAYGROUND_Y)) || (x < 0) || (y < 0) ) {
        newPosInjection(head_position, length, positions, x, y);
        printf("\nYou have touched border.");
        quit(1); 
    } else {

        newPosInjection(head_position, length, positions, x, y);

        incrPos(head_position, length);

    }

}



