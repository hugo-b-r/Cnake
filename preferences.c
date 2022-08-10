/*

preferences.c

functions for preferences

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/init.h"
#include "inc/game.h"
#include "inc/preferences.h"
#include "inc/controls.h"
#include "inc/menu.h"





void preferences(int *level, int *playground_width, int *playground_height) {
        
    switch (preferencesMenu()) {
        case 0:
            *level = askLevel();
            break;
        #if defined(WIN32)
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
