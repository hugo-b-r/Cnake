/*

windows_gfx.h

file for windows gfx

*/

#ifndef _WINDOWS_GFX_H_
#define _WINDOWS_GFX_H_

void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level);

void welcomeMessage();

char defaultMenu();

char preferencesMenu();

int askLevel();

int askPlaygroundWidth();

int askPlaygroundHeight();

#endif
