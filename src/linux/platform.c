/*
 *
 * platform.c
 *
 * */
#include "main.h"
#include <ncurses.h>
#include <unistd.h>


void print_at(int x, int y, char * text) {
    move(x, y);
    printw("%s", text);
}

// to get a character but non blocking
Control get_control() {

	int choice = getch();
    if (choice != ERR) {
        switch(choice) {
			case 122: return up;
			case 113: return left;
			case 115: return down;
			case 100: return right;
            case 48:  return zero;
			case 49:  return one;
			case 50:  return two;
			case 51:  return three;
        }
    }
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
    sleep(time_ms);
}


