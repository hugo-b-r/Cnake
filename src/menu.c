/*

controls.h

file for controls functions

*/



#include "controls.h"



#if defined(NUMWORKS)

    #include <stdint.h>
    
    #include "extapp_api.h"
    #include "peripherals.h"



    void removeFruit(int fruit_x, int fruit_y) {
        extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0x0F00);
    }




    void addNewFruit(int fruit_x, int fruit_y) {
        extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0xF000);
    }




    void removeTail(int *head_position, int length, int (*positions)[2][100]) {

        extapp_waitForVBlank();
        if (*head_position == (length - 1)) {
            extapp_pushRectUniform((*positions)[0][0]*10, 208 - ((*positions)[1][0]*10), 10, 10, 0xFFFF);
        } 
        else {
            extapp_pushRectUniform((*positions)[0][*head_position + 1]*10, 208 - ((*positions)[1][*head_position + 1]*10), 10, 10, 0xFFFF);
        }
    }




    void addNewHead(int head_position, int (*positions)[2][100]) {

        extapp_pushRectUniform(positions[0][head_position]*10, 208 - (positions[1][head_position]*10), 10, 10, 0x0F00);
    
    }




    void reDraw(int playground_width, int playground_height, int length, int (*positions)[2][100], int fruit_x, int fruit_y, int *level) {
        
        extapp_pushRectUniform(70, 218, 100, 22, 0x0000);

    }




    void welcomeMessage() {
        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);
        /*extapp_drawTextLarge("Welcome in Cnake !", 0, 20 * 1, 0x00F0, 0xFFFF, false);
        extapp_waitForVBlank();
        extapp_msleep(1000);*/
    }




    int defaultMenu() {

        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);
        int choice = 10;
        
        extapp_drawTextSmall("(0) Start a new game", 0, 20 * 1, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(1) Preferences", 0, 20 * 2, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(2) Quit", 0, 20 * 3, 0x0000, 0xFFFF, false);

        extapp_waitForVBlank();

        waitForKeyPressed();
        if (extapp_isKeydown(KEY_CTRL_QUIT)) {
            choice = 2;
            return choice;
        }

        choice = numworksFiguresInput();

        return choice;  
    }




    int preferencesMenu() {
        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);
        int choice = 10;
        
        extapp_drawTextSmall("(0) Level", 0, 20 * 1, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(1) Return to main menu", 0, 20 * 2, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(2) Quit", 0, 20 * 3, 0x0000, 0xFFFF, false);

        extapp_waitForVBlank();
        
       waitForKeyPressed();
        choice = numworksFiguresInput();

        if (choice == 1) choice = 3;
        if (choice == 2) choice = 4;
        
        return choice; 
    }




    int askLevel() {

        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);

        int level = 0;

        extapp_drawTextSmall("Enter level:", 0, 20 * 1, 0x0000, 0xFFFF, false);

        extapp_waitForVBlank();
        //find a way to draw numbers
        if (numworksFiguresInput()) {
            level *= 10;
            level += numworksFiguresInput();
        }
        while (1) {
            switch (extapp_getKey(true, NULL)) {
                
                case KEY_CTRL_DEL:
                    level /= 10;
                    break;
                
                case KEY_CTRL_OK:
                    return level;
                
                case KEY_CTRL_EXE:
                    return level;
            }
        }
    }
#endif

#if defined(WIN32) || defined(__linux__)

    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>



    void removeFruit(int fruit_x, int fruit_y) {
        COORD coord;
        coord.X = fruit_x + 1;
        coord.Y = fruit_y + 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("\bo");
    }




    void addNewFruit(int fruit_x, int fruit_y) {
        COORD coord;
        coord.X = fruit_x + 1;
        coord.Y = fruit_y + 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("\bz");
    }




    void removeTail(int *head_position, int length, int (*positions)[2][100]) {
        
        COORD coord;

        if (*head_position == (length - 1)) {
            
            coord.X = (*positions)[0][0] + 1;
            coord.Y = (*positions)[1][0] + 1;
        } 
        else {
            coord.X = (*positions)[0][*head_position + 1] + 1;
            coord.Y = (*positions)[1][*head_position + 1] + 1;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("\b ");
    }




    void addNewHead(int head_position, int (*positions)[2][100]) {

        COORD coord;
        coord.X = (*positions)[0][head_position];
        coord.Y = (*positions)[1][head_position];
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("\bo");
    }




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
