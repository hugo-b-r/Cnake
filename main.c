/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/init.h"
#include "inc/positions.h"
#include "inc/game.h"
#include "inc/preferences.h"
#include "inc/controls.h"
#include "inc/menu.h"




int mainFunction()
{
    int game_continue = 1;
    int level = 0;

    int playground_width = PLAYGROUND_X;
    int playground_height = PLAYGROUND_Y;

    welcomeMessage();

    while (game_continue) {
        
        switch (defaultMenu()) {
            case 0:
                game(&level, playground_width, playground_height, &game_continue);
                break;
        
            case 1:
                preferences(&level, &playground_width, &playground_height);
                break;
        
            case 2:
                return 0;
            
            default:
                continue;
        }
    }
    return 0; 
}



#if defined(WIN32)

int main()
{
    return mainFunction();
}

#endif

#if defined(NUMWORKS)

#include "extapp_api.h"

int extapp_main()
{
    return mainFunction();
}

#endif
