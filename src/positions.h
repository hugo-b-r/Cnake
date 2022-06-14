/*

positions.h

functions for positions matrix manipulations

*/

#ifndef _POSITIONS_H_
#define _POSITIONS_H_

void newPosStorage(int *head_position, int length, int (*positions)[2][100], int x, int y);

void incrPos(int *head_position, int length);

void newPos(int *head_position, int (*positions)[2][100], int orientation, int length, int *command, int playground_width, int playground_height);

#endif
