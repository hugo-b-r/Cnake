/*

controls.h

file for controls functions

*/

#ifndef _MENU_H_
#define _MENU_H_

void removeFruit(int fruit_x, int fruit_y) ;

void addNewFruit(int fruit_x, int fruit_y);

void removeTail(int *head_position, int length, int (*positions)[2][100]);

void addNewHead(int head_position, int (*positions)[2][100]);

void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level);

void welcomeMessage();

int defaultMenu();

int preferencesMenu();

int askLevel();

#if defined(WIN32) || defined(__linux__)

    int askPlaygroundWidth();

    int askPlaygroundHeight();

#endif

#endif