/*

game.c

structure of a game and game related functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "game.h"
#include "positions.h"
#include "preferences.h"
#include "controls.h"
#include "menu.h"

#if defined(NUMWORKS)
    #include "extapp_api.h"
#endif


int tailPosition(int head_position, int current_length)
{
    if (head_position == current_length - 1) {
        return 0;
    } else {
        return head_position + 1;
    }
}




void pauseLoop(int *command)
{
    while (*command == PAUSE) getEvent(command);
}




void incrLength(int (*positions)[2][100], int *current_length, int length_diff, int head_position)
{   
    for (int i = 0; i < ((*current_length) - head_position - 1); i++) {
        (*positions)[0][(*current_length) - i - 1 + length_diff] = (*positions)[0][(*current_length) - i - 1];
        (*positions)[1][(*current_length) - i - 1 + length_diff] = (*positions)[1][(*current_length) - i - 1];
    }
    (*current_length) += length_diff;
}




void game(int *level, int playground_width, int playground_height, int *game_continue)
{
    int orientation = 0;

    int command = -1;


    int current_length = DEFAULT_LENGTH;
    int positions[2][100];
    int head_position = current_length - 1;
    int assumed_length = *level + DEFAULT_LENGTH;

    for (int i = 0; i < 100; i++) {
        positions[0][i] = -1;    
        positions[1][i] = -1; 
    }

    for (int i = 0; i < current_length; i++) {
        positions[0][i] = playground_width/2;
        positions[1][i] = playground_height/2;
        positions[1][i] -= current_length/2;
        positions[1][i] += i;      
    }

     
    //speed set up
    int last_clock = TIME;
    int move_time;
    if (*level <= 10) move_time = DEFAULT_SPEED + *level * DEFAULT_MOVE_TIME;
    else move_time = DEFAULT_SPEED + DEFAULT_MOVE_TIME*10;

    srand(time(0));
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);

    firstImage(playground_width, playground_height, current_length, positions, fruit_x, fruit_y, level);


    while (command != ENDGAME && command != QUIT) {
        
        getEvent(&command);
        translateControl(&orientation, &command);

        if (last_clock + move_time <= TIME) {
            if (head_position == current_length-1) {
                if (fruit_x == positions[0][0] && fruit_y == positions[1][0]) {
                    addNewFruit(fruit_x, fruit_y, playground_height);
                } else {
                    removeTail(&head_position, current_length, &positions, playground_height);
                }
            } else {
                if (fruit_x == positions[0][head_position+1] && fruit_y == positions[1][head_position+1]) {
                    addNewFruit(fruit_x, fruit_y, playground_height);
                } else {
                    removeTail(&head_position, current_length, &positions, playground_height);
                }
            }
            removeTail(&head_position, current_length, &positions, playground_height);
            addNewFruit(fruit_x, fruit_y, playground_height);
              
            newPos(&head_position, &positions, orientation, current_length, &command, playground_width, playground_height);
            addNewHead(head_position, &positions, playground_height);
                 
            //if on fruit
            if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
                removeFruit(fruit_x, fruit_y, playground_height);
                fruit_x = rand() % (playground_width);
                fruit_y = rand() % (playground_height);
                addNewFruit(fruit_x, fruit_y, playground_height);
                assumed_length++;
                incrLength(&positions, &current_length, 1, head_position);
                *level += 1;
                
                if (move_time == 5 * DEFAULT_MOVE_TIME) move_time -= DEFAULT_MOVE_TIME;

            } else if (assumed_length > current_length) {
                incrLength(&positions, &current_length, 1, head_position);
            }

            last_clock = TIME;

            reDraw(playground_width, playground_height, current_length, positions, fruit_x, fruit_y, level);
        }
    }
    printf("\n");

    *level = 0;

    if (command == QUIT) *game_continue = 0;
}
