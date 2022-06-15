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
        switch (extapp_scanKeyboard()) {
            case SCANCODE_Up:
                *command = UP;
                break;

            case SCANCODE_Left:
                *command = LEFT;
                break;

            case SCANCODE_Down:
                *command = DOWN;
                break;

            case SCANCODE_Right:
                *command = RIGHT;
                break;
            
            case SCANCODE_OK:
                *command = PAUSE;
                break;
            
            case SCANCODE_Back:
                *command = ENDGAME;
                break;
            
            case SCANCODE_Home:
                quit(3);
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




    uint64_t numworksFiguresInput()
    {
        switch ((uint64_t) extapp_scanKeyboard) {
            case SCANCODE_Zero:
                return 0;

            case SCANCODE_One:
                return 1;

            case SCANCODE_Two:
                return 2;
                
            case SCANCODE_Three:
                return 3;

            case SCANCODE_Four:
                return 4;
                
            case SCANCODE_Five:
                return 5;

            case SCANCODE_Six:
                return 6;

            case SCANCODE_Seven:
                return 7;
                
            case SCANCODE_Eight:
                return 8;

            case SCANCODE_Nine:
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
