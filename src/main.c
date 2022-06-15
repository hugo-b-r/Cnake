/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "positions.h"
#include "game.h"
#include "preferences.h"
#include "controls.h"
#include "menu.h"



#if defined(NUMWORKS)

#include "extapp_api.h"

int extapp_main()
{

#elif defined(WIN32) || defined(__linux__)

int main(int argc, char* argv[])
{

#endif

    int game_continue = 1;
    int level = 0;

    int playground_width = PLAYGROUND_X;
    int playground_height = PLAYGROUND_Y;

    welcomeMessage();
    #if defined (NUMWORKS)
        waitForKeyPressed();
        extapp_msleep(1000);
    #endif

    while (game_continue) {
        
        switch (defaultMenu()) {
            case 0:
                game(&level, playground_width, playground_height, &game_continue);
                break;
        
            case 1:
                preferences(&level, &playground_width, &playground_height);
                break;
        
            case 2:
                quit(3);
            
            default:
                continue;
        }
    } 
}