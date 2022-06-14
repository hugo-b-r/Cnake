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

#if defined(WIN32)
    #include "windows_controls.h"
/*#elif defined (linux)
    #include "controls/linux_controls.h"
*/
#endif

#if defined(CLI)
    #include "cli_menu.h"
#elif defined (NUMWORKS)
    #include "numworks_menu.h"*/
#endif







void preferences(int *level, int *playground_width, int *playground_height) {
        
    switch (preferencesMenu()) {
        case '1':
            *level = askLevel();
            break;

        case '2':
            *playground_width = askPlaygroundWidth();
            break;

        case '3':
            *playground_height = askPlaygroundHeight();
            break;

        case 'x':
            return;   
        
        case 'k':
            quit(3);
    }
    printf("\n");
}