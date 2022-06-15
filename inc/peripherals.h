#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

#if defined(NUMWORKS)

#include <stdint.h>

extern long long unsigned int keymappings[16];
extern int keymappings_await[16];

void init_display();

void waitForKeyPressed();

void waitForKeyReleased();

void waitForKeyReleasedTimeout(int timeout);

#endif

#endif
