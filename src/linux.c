/*
 *
 * linux.c
 *
 * */
#include "main.h"
#include "linux.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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




void print_at(int x, int y, char * text) {
    move(y, x);
    printw("%s", text);
    refresh();
}

// To get a character but non blocking
Control get_control_non_blocking() {
	int choice = getch();
    if (choice != ERR) {
        switch(choice) {
			case 122: return up;
			case 113: return left;
			case 115: return down;
			case 100: return right;
            case 48:  return zero; // To choose in the menu
			case 49:  return one;
			case 50:  return two;
			case 51:  return three;
            case 52:  return four;
            case 112: return holdon;  // 'p' to pause
            case 101: return end_game; // 'e' to end a game
            case 120: return quit;    // 'x' to quit
        }
    }
}

// To get a character but blocking
Control get_control_blocking() {
	nodelay(stdscr, FALSE);
    Control control =  get_control_non_blocking();
    nodelay(stdscr, TRUE);
    return control;
}

void clear_screen() {
    clear();
	refresh();
}

int screen_x() {
	return getmaxx(stdscr);
}

int screen_y() {
	return getmaxy(stdscr);
}


void uni_sleep(int time_ms) {
    struct timespec ts;
    ts.tv_sec = time_ms / 1000;
    ts.tv_nsec = (time_ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
}


void draw_sth(int x, int y, DrawObject draw_object) {
    switch(draw_object) {
        case snake_body:
            print_at(x, y, "o");
            break;
        case fruit_dr:
            print_at(x, y, "f");
            break;
        case nothing_dr:
            print_at(x, y, " ");
            break;
    }
}


void draw_top_separator(int x) {
    print_at(x, 0, "_");
}


