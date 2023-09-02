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
#include "menu.h"
#include "main.h"


int tailPosition(int head_position, int current_length)
{
    if (head_position == current_length - 1) {
        return 0;
    } else {
        return head_position + 1;
    }
}




void pauseLoop(Control *control)
{
    while (*control == pause) {
        *control = get_control();
        uni_sleep(20);
    }
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
    Orientation orientation = north;

    Control control = up;


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

     
    srand(time(0));
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);

    firstImage(playground_width, playground_height, current_length, positions, fruit_x, fruit_y, level);


    while (control != end_game && control != quit) {
        
		control = get_control();
		switch(control) {
			case up:
				orientation = north;
			case left:
				orientation = west;
			case down:
				orientation = south;
			case right:
				orientation = east;
			default:
				;
		};

        if (fruit_x == positions[0][tailPosition(head_position, current_length)] && fruit_y == positions[1][tailPosition(head_position, current_length)]) {
            drawPoint(fruit_x, fruit_y, playground_height, FRUIT);
        } else {
            drawPoint(positions[0][tailPosition(head_position, current_length)], positions[1][tailPosition(head_position, current_length)], playground_height, NOTHING);
        }

        newPos(&head_position, &positions, orientation, current_length, &control, playground_width, playground_height);
        drawPoint(positions[0][head_position], positions[1][head_position], playground_height, SNAKE);

        //if on fruit
        if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
            drawPoint(fruit_x, fruit_y, playground_height, SNAKE);
            fruit_x = rand() % (playground_width);
            fruit_y = rand() % (playground_height);
            drawPoint(fruit_x, fruit_y, playground_height, FRUIT);
            assumed_length++;
            incrLength(&positions, &current_length, 1, head_position);
            *level += 1;
            updateScore(playground_height, level);
    


        } else if (assumed_length > current_length) {
            incrLength(&positions, &current_length, 1, head_position);
        }

        uni_sleep(DEFAULT_SPEED);

    }

    if (control == end_game) *game_continue = 0;
}
