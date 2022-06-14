/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "positions.h"
#include "game.h"
#include "preferences.h"






int main(int argc, char* argv[])
{
    int game_continue = 1;
    int level = 0;
    char buffer = '0';

    int playground_width = PLAYGROUND_X;
    int playground_height = PLAYGROUND_Y;

    printf("\n\n");
    printf("\x1B[36mWelcome in Cnake !!\033[0m\t\t");
    printf("\n\n");
    while (game_continue) {
        printf("- (1) Start a new game\n");
        printf("- (2) Preferences\n");
        printf("- (k) Quit\n");
        printf(">");

        scanf("%c", &buffer);
        flushBuffer();

        switch (buffer) {
            case '1':
                game(&level, playground_width, playground_height, &game_continue);
                break;
        
            case '2':
                preferences(&level, &playground_width, &playground_height);
                break;
        
            case 'k':
                quit(3);
            
            default:
                continue;
        }
    } 
}