/*

    positions.h
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#ifndef _POSITIONS_H_
#define _POSITIONS_H_

#include "main.h"



void new_position_storage(
    int *head_position,
    int current_length,
    int (*positions)[2][100],
    int x,
    int y
);


void increase_position(int *head_position, int current_length);



#endif
