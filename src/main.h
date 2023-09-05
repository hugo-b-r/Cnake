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
	holdon, 	// Pause.
	quit, 		// Entirely exit the program.
	end_game,	// End the game but continue to the menu.
	zero,
	one,
	two,
	three,
	four,
	nullissime
} Control;

typedef enum {
	north,
	west,
	south,
	east
} Orientation;

typedef enum {
  snake_body,
  fruit_dr,
  nothing_dr
} DrawObject;

#endif
