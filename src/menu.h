/*

controls.h

file for controls functions

*/

#ifndef _MENU_H_
#define _MENU_H_

void deathMsg(char *msg);

void firstImage(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level);

void drawPoint(int x, int y, int playground_height, int type);

void updateScore(int playground_height, int *level);    

void welcomeMessage();

int defaultMenu();

int preferencesMenu();

int askLevel();

#if defined(WIN32) || defined(__linux__)

    int askPlaygroundWidth();

    int askPlaygroundHeight();

#endif

#endif
