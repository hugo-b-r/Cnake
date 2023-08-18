/*

init.c

function for init and deinit

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void init_platform() {
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

	/*init_pair(NORMAL_PAIR, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(NORMAL_PAIR));

	init_pair(WELCOME_PAIR, COLOR_BLACK, COLOR_GREEN);*/
}



void gracefully_shutdown(char* message)
{
	endwin();
	printf("%s", message);
    exit(0);
}
