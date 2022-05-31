/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "init.h"
#include "game.h"
#include "entries.h"










int main(int argc, char* argv[])
{
    char command_buffer = '1';
    int level = 0;

    printf("\n\n");
    printf("\x1B[36mWelcome in Cnake !!\033[0m\t\t");
    printf("\n\n");
    printf("Start a new game (0)");
    printf("Preferences (1)");
    command_buffer = getchar();

    switch(command_buffer) {
        case ('1'):
            game(&level, PLAYGROUND_X, PLAYGROUND_Y);
            break;
        case ('2'):
            preferences();
    }
}