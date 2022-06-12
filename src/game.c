/*

game.c

structure of a game and game related functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "init.h"
#include "game.h"
#include "entries.h"
#include "preferences.h"




void flushBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}




void pauseLoop(char *command)
{
    while (*command == 'p') {
        getEvent(command);
    }
}




void incrLength(int (*positions)[2][100], int *length, int length_diff, int head_position)
{   
    for (int i = 0; i < ((*length) - head_position - 1); i++) {
        (*positions)[0][(*length) - i - 1 + length_diff] = (*positions)[0][(*length) - i - 1];
        (*positions)[1][(*length) - i - 1 + length_diff] = (*positions)[1][(*length) - i - 1];
    }
    (*length) += length_diff;
}




void game(int *level, int playground_width, int playground_height, int *game_continue)
{
    int orientation = 0;

    char command = 'a';


    int length = *level + DEFAULT_LENGTH;
    int positions[2][100];
    int head_position = length - 1;

    for (int i = 0; i < 100; i++) {
        positions[0][i] = -1;    
        positions[1][i] = -1; 
    }

    for (int i = 0; i < length; i++) {
        positions[0][i] = playground_width/2;
        positions[1][i] = playground_height/2;
        positions[1][i] -= length/2;
        positions[1][i] += i;      
    }

     
    //speed set up
    int last_clock = clock();
    int move_time = 300 - (*level * 10);

    srand(time(0));
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);  


    while (command != 'x') {
        
        getEvent(&command);
        testEvents(&orientation, &command);

        if (last_clock + move_time <= clock()) {
            
            newPos(&head_position, &positions, orientation, length);
            
            //if on fruit
            if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
                
                fruit_x = rand() % (playground_width);
                fruit_y = rand() % (playground_height);
                 
                incrLength(&positions, &length, 1, head_position);
                *level += 1;
                move_time -= 10;
            }

            last_clock = clock();
        }


        system("cls");
        
        for (int i = playground_height - 1; i >= 0; i--) {
            for (int j = 0; j < playground_width; j++) {
                
                for (int k = 0; k < length; k++) {
                    if (j == positions[0][k] && i == positions[1][k]) {
                        printf("o");
                        goto hell;
                    }
                    // could be better to check only one time instead of two if on or not
                }
                if (j == fruit_x && i == fruit_y) {
                    printf("z");
                }
                else {
                    printf(" ");
                }
                hell:
            }
            printf("\n");
        }
        printf("\npoints: %d\n", *level);
    }
    printf("\n");
}