/*

positions.c

functions for positions matrix manipulations

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "positions.h"




void newPosStorage(int *head_position, int length, int (*positions)[2][100], int x, int y) {
    
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




void newPos(int *head_position, int (*positions)[2][100], int orientation, int length, int *command, int playground_width, int playground_height)
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
            newPosStorage(head_position, length, positions, x, y);
            printf("\nOuch. You diedaeting yourself.\n");
            *command = ENDGAME;
        }
    }

    // if border
    if ( (x > (playground_width-1)) || (y > (playground_height)) || (x < 0) || (y < 0) ) {
        newPosStorage(head_position, length, positions, x, y);
        printf("\nYou died crushed against the wall.\n");
        *command = ENDGAME;
        return;
    } else {

        newPosStorage(head_position, length, positions, x, y);

        incrPos(head_position, length);

    }

}



