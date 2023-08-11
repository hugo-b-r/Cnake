/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/init.h"
#include "inc/positions.h"
#include "inc/game.h"
#include "inc/preferences.h"
#include "inc/controls.h"
#include "inc/menu.h"




int mainFunction()
{	
	#if defined(__linux__)
		#include <ncurses.h>

		// init ncurses
		initscr();
		noecho();
		raw();
		curs_set(FALSE);
		nodelay(stdscr, TRUE);
		if (has_colors() == FALSE) {
			endwin();
			printf("Your terminal does not support color.\n");
			exit(1);
		}
		start_color();

		init_pair(NORMAL_PAIR, COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR(NORMAL_PAIR));

		init_pair(WELCOME_PAIR, COLOR_BLACK, COLOR_GREEN);

	#endif

    int game_continue = 1;
    int level = 0;

    int playground_width = PLAYGROUND_X;
    int playground_height = PLAYGROUND_Y;

	getmaxyx(stdscr, playground_height, playground_width);

    welcomeMessage();
	int value = defaultMenu();
	printw("%d", value);
    while (game_continue) {
        
        switch (value) {
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
                return 0;
            default:
                continue;

        }
    }
	#if defined(__linux__)
		endwin();
	#endif
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
