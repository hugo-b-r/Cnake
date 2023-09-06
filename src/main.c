/*

    main.c
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
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



int main_function()
{	
	init_platform();

    int game_continue = 1;

    int playground_width = screen_x();
    int playground_height = screen_y()-1;   // Minus 1 for the score line
    print_at(playground_width/2-8, playground_height/2-3, "Welcome in Cnake!");    // Welcome the player
    uni_sleep(1000);                       // The message lasts 1 second
    while (game_continue) {
        // Display options
        print_at(playground_width/2-4, playground_height/2-1, "0 - Play!");
        print_at(playground_width/2-4, playground_height/2+1, "1 - Exit");
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
                print_at(playground_width/2-9, playground_height/2-2, "Not a good answer !");
                print_at(playground_width/2-10, playground_height/2, "Please choose between");
                print_at(playground_width/2-3, playground_height/2+2, "0 or 1.");
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
        return main_function();
    }

#elif defined NUMWORKS || defined EPSILON_VERSION

    #include "extapp_api.h"

    int extapp_main()
    {
        return main_function();
    }

#elif defined LINUX

    #include <ncurses.h>


    int main() {
            // the game
        return main_function();
    }

#endif
