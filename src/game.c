/*

game.c

structure of a game and game related functions

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "init.h"
#include "buffer.h"
#include "game.h"
#include "entries.h"




void incrLength(int (*positions)[2][100], int *length, int length_diff, int head_position)
{   
    for (int i = 0; i < ((*length) - head_position - 1); i++) {
        (*positions)[0][(*length) - i - 1 + length_diff] = (*positions)[0][(*length) - i - 1];
        (*positions)[1][(*length) - i - 1 + length_diff] = (*positions)[1][(*length) - i - 1];
    }
    (*length) += length_diff;
}




void game(int level, int playground_width, int playground_height)
{
    srand(time(0));
   
    char command = 'a';
    
    int level = 0;
    
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);

    char buffer[playground_width][playground_height];   
    
    int length = LENGTH;
    int positions[2][100];
    int head_position = LENGTH-1;
     
    //speed set up
    int last_clock = clock();
    int move_time = 300;

    int orientation = 0;
    
    initVar(&positions, &orientation, &buffer);

    while (command != 'x') {
        
        getKeyboardEntry(&command);
        testEvents(&orientation, &command);

        if (last_clock + move_time <= clock()) {
            
            newPos(&head_position, &positions, orientation, length);
            
            //if on fruit
            if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
                
                fruit_x = rand() % (playground_width);
                fruit_y = rand() % (playground_height);
                 
                incrLength(&positions, &length, 1, head_position);
                level += 1;
                move_time -= 10;
            }

            last_clock = clock();
            
        }

        clearBuffer(&buffer);

        for (int i = 0; i < length; i++) {
            if (!((positions[0][i] == -1) && (positions[1][i] == -1))) {
                buffer[positions[0][i]][positions[1][i]] = 'o';
            }
        }

        buffer[fruit_x][fruit_y] = 'z';

        system("cls");

        printBuffer(&buffer);
        printf("\npoints: %d\n", level);

    }
}