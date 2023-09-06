/*

    positions.c
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "main.h"
#include "positions.h"

#ifdef WINDOWS
    #include "windows.h"
#elif defined LINUX
    #include "linux.h"
#elif defined NUMWORKS || defined EPSILON_VERSION
    #include "numworks.h"
#endif



void new_position_storage(int *head_position, int current_length, int (*positions)[2][100], int x, int y) {
    (*positions)[0][tail_position(*head_position, current_length)] = x;
    (*positions)[1][tail_position(*head_position, current_length)] = y;
    // Replace the tail coordinates by the ones of the new head
}


void increase_position(int *head_position, int current_length)
// Sets the head_position index in the array
{
    (*head_position)++;
    if (*head_position >= current_length) {
        *head_position = 0;
    }
}
