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





void pauseLoop(int *command)
{
    while (*command == PAUSE) {
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

    int command = -1;


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
    int last_clock = TIME;
    int move_time = DEFAULT_SPEED - (*level * DEFAULT_MOVE_TIME);

    srand(time(0));
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);

    #if defined(NUMWORKS)

    extapp_waitForVBlank();
    extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);

    for (int i = 0; i < length; i++) {
        extapp_pushRectUniform(positions[0][i]*10, 208 - (positions[1][i]*10), 10, 10, 0x0F00);
    }
    extapp_waitForVBlank();

    extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0xF000);
    extapp_pushRectUniform(0, 218, 320, 22, 0x0000);
    extapp_drawTextLarge("Points:", 0, 222, 0xFFFF, 0x0000, false);
    extapp_waitForVBlank();

    #endif

    while (command != ENDGAME && command != QUIT) {
        
        getEvent(&command);
        translateControl(&orientation, &command);

        if (last_clock + move_time <= TIME) {
            
            newPos(&head_position, &positions, orientation, length, &command, playground_width, playground_height);
            
            //if on fruit
            if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
                
                extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0x0F00); //snake is on the fruit in this case
                fruit_x = rand() % (playground_width);
                fruit_y = rand() % (playground_height);
                extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0xF000);

                incrLength(&positions, &length, 1, head_position);
                *level += 1;
                move_time -= DEFAULT_MOVE_TIME;
            }

            last_clock = TIME;

            reDraw(playground_width, playground_height, length, positions, fruit_x, fruit_y, level);
        }
    }
    printf("\n");

    *level = 0;

    if (command == QUIT) *game_continue = 0;
}