/*
 * main.h
 *
 * */

#ifndef MAIN_H
#define MAIN_H

typedef enum {
	up,
	left,
	down,
	right,
	pause,
	quit,
	new_game,
	end_game
} Control;

typedef enum {
	north,
	west,
	south,
	east
} Orientation;

#endif
