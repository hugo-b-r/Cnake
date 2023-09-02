/*
 *
 * platform.c
 *
 * */
#include "main.h"
#include "windows.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

void init_platform() { ; }

void gracefully_shutdown(char *message) {
  printf("%s", message);
  exit(0);
}

void print_at(int x, int y, char *text) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%s", text);
}

// to get a character but non blocking
Control get_control() {
    if (kbhit()) {
        char event = getch();
        switch (event) {
        case 'z':
            return up;
        case 'q':
            return left;
        case 's':
            return down;
        case 'd':
            return right;
        case 'p':
            return holdon;
        case 'x':
            return end_game;
        case 'k':
            return quit;
        }
    }
}

void clear_screen() { system("cls"); }

int screen_x() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

int screen_y() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return rows;
}

void uni_sleep(int time_ms) { sleep(time_ms); }

void draw_top_separator(int x, int y) {
    print_at(x, y, "_");
}

                                              
