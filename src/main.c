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
#include "menu.h"
#include "platform.h"




int mainFunction()
{	
	init_platform();

    int game_continue = 1;
    int level = 0;

    int playground_width = screen_x();
    int playground_height = screen_y();



    welcomeMessage();
    while (game_continue) {
        
        switch (defaultMenu()) {
            case 0:
                game(&level, playground_width, playground_height, &game_continue);
                break;
        
            case 1:
                preferences(&level, &playground_width, &playground_height);
                break;
        
            case 2:
                level = 0;
                break;
            
            case 3:
               gracefully_shutdown("Aloa...");
            default:
                continue;

        }
    }
    gracefully_shutdown("Bye, bye...");
    return 0; 
}



#if defined(WIN32)

int main()
{
    return mainFunction();
}

#endif

#if defined(NUMWORKS)

#include "extapp_api.h"

int extapp_main()
{
    return mainFunction();
}

#endif

#if defined(__linux__)
#include <ncurses.h>


int main() {
		// the game
	return mainFunction();
}



#endif
