/*

    game.h
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"



int tailPosition(int head_position, int current_length);


void pauseLoop(Control *command);


void incrLength(
    int (*positions)[2][100],
    int *length,
    int length_diff,
    int head_position
);


void game(
    int playground_width,
    int playground_height,
    int *game_continue
);



#endif
