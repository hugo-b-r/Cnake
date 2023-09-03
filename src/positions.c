/*

positions.c

functions for positions matrix manipulations

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "main.h"
#include "positions.h"

#ifdef WIN32
    #include "windows.h"
#elif defined __linux__
    #include "linux.h"
#elif defined NUMWORKS
    #include "numworks.h"
#endif




void newPosStorage(int *head_position, int current_length, int (*positions)[2][100], int x, int y) {
    (*positions)[0][tailPosition(*head_position, current_length)] = x;
    (*positions)[1][tailPosition(*head_position, current_length)] = y;
}




void incrPos(int *head_position, int current_length)
{
    (*head_position)++;
    if (*head_position >= current_length) {
        *head_position = 0;
    }
}




void newPos(int *head_position, int (*positions)[2][100], Orientation orientation, int current_length, Control *command, int playground_width, int playground_height)
{
    int x = (*positions)[0][*head_position];
    int y = (*positions)[1][*head_position];

    switch (orientation) {
    case north:
        y -= 1; // Remember coordinates are "reversed"
        break;
    case west:
        x -= 1; // i.e.
        break;
    case south:
        y += 1; // i.e.
        break;
    case east:
        x += 1; // i.e.
        break;
    }

    //if on itself
    for (int i = 0; i < current_length; i++) {
        if ( (x == (*positions)[0][i]) && (y == (*positions)[1][i]) ) {
            newPosStorage(head_position, current_length, positions, x, y);
            clear_screen();
            print_at(0, 0, "Ouch. You died eating yourself.");
            *command = end_game;
        }
    }

    // if border
    if ( (x > (playground_width-1)) || (y > (playground_height-1)) || (x < 0) || (y < 0) ) {
        newPosStorage(head_position, current_length, positions, x, y);
        clear_screen();
        print_at(0, 0, "You died crushed against the wall.");
        *command = end_game;
        return;
    } else {

        newPosStorage(head_position, current_length, positions, x, y);

        incrPos(head_position, current_length);

    }
}




