/*

game.H

structure of a game and game related functions

*/

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"

int tailPosition(int head_position, int current_length);

void pauseLoop(Control *command);

void incrLength(int (*positions)[2][100], int *length, int length_diff, int head_position);

void game(int playground_width, int playground_height, int *game_continue);
/*
struct fruit
{
    int x;
    int y;
};

struct game
{
    int score;
    int 
    struct fruit Fruit;
    
};*/

#endif
