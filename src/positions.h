/*

positions.h

functions for positions matrix manipulations

*/

#ifndef _POSITIONS_H_
#define _POSITIONS_H_

void incrPos(int *tail_position, int *head_position, int length);

void newPos(int *tail_position, int *head_position, int (*positions)[2][100], int orientation, int length);

#endif
