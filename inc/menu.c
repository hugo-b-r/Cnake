/*

controls.h

file for controls functions

*/


#if defined(NUMWORKS)
    #include "extapp_api.h"
    #include "peripherals.h"
#endif

#include "controls.h"



#if defined(NUMWORKS)

    #include <stdint.h>

    void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level) {

        init_display();
        extapp_pushRectUniform(0, 210, 12, 320, 0x0000);
        
        for (int i = 0; i < 100; i++) {
            extapp_pushRectUniform(positions[0][i]*10, positions[0][i]*10, 10, 10, 0x00F0);
        }

        extapp_pushRectUniform(fruit_x, 22 - fruit_y, 10, 10, 0xF000);

        extapp_drawTextSmall("Points:", 0, 222, 0xFFFF, 0x0000, false);
    }




    void welcomeMessage() {
        extapp_drawTextLarge("Welcome in Cnake !", 0, 20 * 1, 0x00F0, 0xFFFF, false);
    }




    int defaultMenu() {

        init_display();
        int choice = 10;
        
        extapp_drawTextSmall("(1) Start a new game", 0, 20 * 1, 0x0F00, 0xFFFF, false);
        extapp_drawTextSmall("(2) Preferences", 0, 20 * 2, 0x0F00, 0xFFFF, false);
        extapp_drawTextSmall("(3) Quit", 0, 20 * 3, 0x0F00, 0xFFFF, false);
        
        while (choice == 10) {
            if (numworksFiguresInput()) {
                choice = numworksFiguresInput();
            }
        }
        return choice;  
    }




    int preferencesMenu() {
        init_display();
        int choice = 10;
        
        extapp_drawTextSmall("(0) Level", 0, 20 * 1, 0x0F00, 0xFFFF, false);
        extapp_drawTextSmall("(1) Return to main menu", 0, 20 * 4, 0x0F00, 0xFFFF, false);
        extapp_drawTextSmall("(2) Quit", 0, 20 * 5, 0x0F00, 0xFFFF, false);
        
        while (choice == 10) {
            if (numworksFiguresInput()) {
                choice = numworksFiguresInput();
            }
        }

        if (choice == 1) choice = 3;
        if (choice == 2) choice = 4;
        
        return choice; 
    }




    int askLevel() {
        int level = 0;

        extapp_drawTextSmall("Enter level:", 0, 20 * 1, 0x0F00, 0xFFFF, false);
        //find a way to draw numbers
        if (numworksFiguresInput()) {
            level *= 10;
            level += numworksFiguresInput();
        }
        while (1) {
            switch ((uint64_t) extapp_scanKeyboard) {
                
                case SCANCODE_Backspace:
                    level /= 10;
                    break;
                
                case SCANCODE_OK:
                    return level;
                
                case SCANCODE_EXE:
                    return level;
            }
        }
    }
#endif

#if defined(WIN32) || defined(__linux__)

    #include <stdio.h>
    #include <stdlib.h>




    void flushBuffer() {
        int c = 0;
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }
    }




    void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level) {

        system("cls");
        
        for (int i = 0; i <= playground_width+1; i++) {
            printf("#");
        }
        printf("\n");

        for (int i = playground_height - 1; i >= 0; i--) {
            printf("#");
            for (int j = 0; j < playground_width; j++) {
                for (int k = 0; k < length; k++) {
                    if (j == positions[0][k] && i == positions[1][k]) {
                        printf("o");
                        goto hell;
                    }
                    // could be better to check only one time instead of two if on or not
                }
                if (j == fruit_x && i == fruit_y) {
                    printf("z");
                }
                else {
                    printf(" ");
                }
                hell:
            }
            printf("#\n");
        }
        for (int i = 0; i <= playground_width+1; i++) {
            printf("#");
        }
        printf("\n");

        printf("\npoints: %d\n", *level);
    }




    void welcomeMessage() {
        printf("\n\n");
        printf("\x1B[36mWelcome in Cnake !!\033[0m\t\t");
        printf("\n\n");
    }




    int defaultMenu() {
        int choice = 0;
        
        printf("- (0) Start a new game\n");
        printf("- (1) Preferences\n");
        printf("- (2) Quit\n");
        printf(">");

        scanf("%d", &choice);
        flushBuffer();

        return choice;
    }




    int preferencesMenu() {
        int choice = 0;
        
        printf("\n");
        printf("- (0) Level\n");
        printf("- (1) Width of the playground\n");
        printf("- (2) Height of the playground\n");
        printf("- (3) Return to main menu\n");
        printf("- (4) Quit\n");
        printf(">");

        scanf("%d", &choice);
        flushBuffer();

        return choice;
    }




    int askLevel() {
        int level = 0;

        printf("\nWhat level do you want to start with ? \n");
        printf(">");

        scanf("%d", &level);
        flushBuffer();

        return level;
    }




    int askPlaygroundWidth() {
        int playground_width = 0;

        printf("\nWhat width do you want to play with ? \n");
        printf(">");

        scanf("%d", &playground_width);
        flushBuffer();

        return playground_width;
    }




    int askPlaygroundHeight() {
        int playground_height = 0;

        printf("\nWhat height do you want to play with ? \n");
        printf(">");

        scanf("%d", &playground_height);
        flushBuffer();

        return playground_height;
    }

#endif
