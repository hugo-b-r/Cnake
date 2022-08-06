/*

controls.h

file for controls functions

*/

#ifndef _CONTROLS_H_
#define _CONTROLS_H_

void getEvent(int *command);

void translateControl(int *orientation, int *command);

#if defined(NUMWORKS)

    int numworksFiguresInput(int key);

#endif

#endif
