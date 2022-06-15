/*

preferences.c

functions for preferences

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "game.h"
#include "preferences.h"
#include "controls.h"
#include "menu.h"





void preferences(int *level, int *playground_width, int *playground_height) {
        
    switch (preferencesMenu()) {
        case 0:
            *level = askLevel();
            break;
        #if defined(WIN32) || defined(__linux__)
        case 1:
            *playground_width = askPlaygroundWidth();
            break;

        case 2:
            *playground_height = askPlaygroundHeight();
            break;
        #endif

        case 3:
            return;   
        
        case 4:
            quit(3);
    }
    printf("\n");
}