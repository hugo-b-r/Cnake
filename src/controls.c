/*

controls.c

file for controls functions

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#if defined(NUMWORKS)
    #include "extapp_api.h"
#endif

#include "init.h"
#include "game.h"


#if defined(NUMWORKS)

    void getEvent(int *command)
    {
        int key = extapp_getKey(true, NULL);
        switch (key) {
            case KEY_CTRL_UP:
                *command = UP;
                break;

            case KEY_CTRL_LEFT:
                *command = LEFT;
                break;

            case KEY_CTRL_DOWN:
                *command = DOWN;
                break;

            case KEY_CTRL_RIGHT:
                *command = RIGHT;
                break;
            
            case KEY_CTRL_OK:
                *command = PAUSE;
                break;
            
            case KEY_CTRL_EXIT:
                *command = ENDGAME;
                break;
            
            case KEY_CTRL_MENU:
                *command = QUIT;
        }
    }




    void translateControl(int *orientation, int *command)
    {
        switch (*command) {
            case UP:
                if (*orientation != 180) *orientation = 0;
                break;

            case LEFT:
                if (*orientation != 90) *orientation = 270;
                break;

            case DOWN:
                if (*orientation != 0) *orientation = 180;
                break;
    
            case RIGHT:
                if (*orientation != 270) *orientation = 90;
                break;
            
            case PAUSE:
                pauseLoop(command);
                break;
        }
    }




    int numworksFiguresInput()
    {
        int key = extapp_getKey(true, NULL);
        switch (key) {
            case KEY_CHAR_0:
                return 0;

            case KEY_CHAR_1:
                return 1;

            case KEY_CHAR_2:
                return 2;
                
            case KEY_CHAR_3:
                return 3;

            case KEY_CHAR_4:
                return 4;
                
            case KEY_CHAR_5:
                return 5;

            case KEY_CHAR_6:
                return 6;

            case KEY_CHAR_7:
                return 7;
                
            case KEY_CHAR_8:
                return 8;

            case KEY_CHAR_9:
                return 9; 
        }
    }
#endif


#if defined(WIN32)
    #include <conio.h>
    
    #define KEYBOARDHIT kbhit()
    #define GETCHAR getch()

    void getEvent(int *command)
    {
        if (KEYBOARDHIT) {
            char event = GETCHAR;
                switch (event) {
                case 'z':
                    *command = UP;
                    break;
                
                case 'q':
                    *command = LEFT;
                    break;
                
                case 's':
                    *command = DOWN;
                    break;

                case 'd':
                    *command = RIGHT;
                    break;
                
                case 'p':
                    *command = PAUSE;
                    break;
                
                case 'x':
                    *command = ENDGAME;
                    break;

                case 'k':
                    quit(3);
            }
        }  
    }




    void translateControl(int *orientation, int *command)
    {
        switch (*command) {
            case UP:
                if (*orientation != 180) *orientation = 0;
                break;

            case LEFT:
                if (*orientation != 90) *orientation = 270;
                break;

            case DOWN:
                if (*orientation != 0) *orientation = 180;
                break;
    
            case RIGHT:
                if (*orientation != 270) *orientation = 90;
                break;
            
            case PAUSE:
                pauseLoop(command);
                break;
        }
    }

#endif
