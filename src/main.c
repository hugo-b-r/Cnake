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

#if defined(WIN32)
    #include "windows_controls.h"
/*#elif defined (linux)
    #include "controls/linux_controls.h"
#elif defined (NUMWORKS)
    #include "controls/numworks_controls.h"*/
#endif

#if defined(CLI)
    #include "cli_menu.h"
#endif




int main(int argc, char* argv[])
{
    int game_continue = 1;
    int level = 0;

    int playground_width = PLAYGROUND_X;
    int playground_height = PLAYGROUND_Y;

    welcomeMessage();

    while (game_continue) {
        
        switch (defaultMenu()) {
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