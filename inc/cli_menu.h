/*

cli_menu.h

file for cli menus

*/

#ifndef _CLI_MENU_H_
#define _CLI_MENU_H_

void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level);

void welcomeMessage();

char defaultMenu();

char preferencesMenu();

int askLevel();

int askPlaygroundWidth();

int askPlaygroundHeight();

#endif
