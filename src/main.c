/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "positions.h"
#include "game.h"

#ifdef WINDOWS
    #include "windows.h"
#elif defined LINUX
    #include "linux.h"
#elif defined NUMWORKS || defined EPSILON_VERSION
    #include "numworks.h"
#endif


int mainFunction()
{	
	init_platform();

    int game_continue = 1;

    int playground_width = screen_x();
    int playground_height = screen_y()-1;   // Minus 1 for the score line
    print_at(0, 0, "Welcome in Cnake!");    // Welcome the player
    uni_sleep(1000);                       // The message lasts 1 second
    while (game_continue) {
        // Display options
        print_at(0, 1, "0 - Play!");
        print_at(0, 2, "1 - Exit");
        switch (get_control_blocking()) {
            case zero:
                // Start a new game
                game(playground_width, playground_height, &game_continue);
                break;
        
            case quit:
                gracefully_shutdown("Aloa...");
                game_continue = 0;
                break;
            case one:
                gracefully_shutdown("Aloa...");
                game_continue = 0;
                break;
            default:
                clear_screen();
                print_at(0, 0, "Not a good answer !");
                print_at(0, 1, "Please choose between");
                print_at(0, 2, "0 or 1.");
                uni_sleep(1000);
                clear_screen();
                break;

        }
    }
    gracefully_shutdown("Bye, bye...");
    return 0; 
}



#if defined(WINDOWS)

    int main()
    {
        return mainFunction();
    }

#elif defined NUMWORKS || defined EPSILON_VERSION

    #include "extapp_api.h"

    int extapp_main()
    {
        return mainFunction();
    }

#elif defined LINUX

    #include <ncurses.h>


    int main() {
            // the game
        return mainFunction();
    }



#endif
