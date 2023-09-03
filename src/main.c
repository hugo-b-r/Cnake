/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "game.h"

#ifdef WIN32
    #include "windows.h"
#elif defined __linux__
    #include "linux.h"
#elif defined NUMWORKS
    #include "numworks.h"
#endif



int mainFunction()
{	
	init_platform();

    int game_continue = 1;
    int level = 0;

    int playground_width = screen_x();
    int playground_height = screen_y()-1;   // Minus 1 for the score line
    print_at(0, 0, "Welcome in Cnake!");    // Welcome the player
    uni_sleep(1000);                       // The message lasts 1 second
    while (game_continue) {
        // Display options
        print_at(0, 1, "0 - Play!");
        print_at(0, 2, "1 - Exit");
        switch (get_control()) {
            case zero:
                // Start a new game
                game(&level, playground_width, playground_height, &game_continue);
                break;
        
            case one:
                gracefully_shutdown("Aloa...");
                break;
            default:
                clear_screen();
                print_at(0, 0, "Not a good answer !");
                print_at(0, 1, "Please choose between");
                print_at(0, 2, "0 or 1.");
                uni_sleep(1000);
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
