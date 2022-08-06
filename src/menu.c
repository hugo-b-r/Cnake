/*

controls.h

file for controls functions

*/



#include "controls.h"
#include "game.h"
#include "init.h"



#if defined(NUMWORKS)

    #include <stdint.h>
    
    #include "extapp_api.h"
    #include "peripherals.h"
    
   

    void deathMsg(char *msg)
    {
        extapp_waitForVBlank();
        extapp_drawTextSmall(msg, 0, 111, 0XFFFF, 0X0000, false);
    }




    void firstImage(int playground_width, int playground_height, int current_length, int positions[2][100], int fruit_x, int fruit_y, int *level)
    {
        extapp_waitForVBlank();
        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);

        for (int i = 0; i < current_length; i++) {
            extapp_pushRectUniform(positions[0][i]*10, 208 - (positions[1][i]*10), 10, 10, 0x0F00);
        }
        extapp_waitForVBlank();

        extapp_pushRectUniform(fruit_x*10, 208 - (fruit_y*10), 10, 10, 0xF000);
        extapp_pushRectUniform(0, 218, 320, 22, 0x0000);
        extapp_drawTextLarge("Points:", 0, 222, 0xFFFF, 0x0000, false);
        extapp_waitForVBlank();
    }




    void drawPoint(int x, int y, int playground_height, int type)
    {
        switch (type) {
            case SNAKE:
                extapp_pushRectUniform(x*10, 208- (y*10), 10, 10, 0x0F00);
                break;

            case FRUIT:
                extapp_pushRectUniform(x*10, 208- (y*10), 10, 10, 0xF000);
                break;

            case NOTHING:
                extapp_pushRectUniform(x*10, 208- (y*10), 10, 10, 0x0000);
                break;
        }
    }




    void reDraw(int playground_width, int playground_height, int current_length, int (*positions)[2][100], int fruit_x, int fruit_y, int *level)
    {
        
        extapp_pushRectUniform(70, 218, 100, 22, 0x0000);

    }




    void welcomeMessage()
    {
        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);
        /*extapp_drawTextLarge("Welcome in Cnake !", 0, 20 * 1, 0x00F0, 0xFFFF, false);
        extapp_waitForVBlank();
        extapp_msleep(1000);*/
    }




    int defaultMenu()
    {

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
        int key = extapp_getKey(true, NULL);
        choice = numworksFiguresInput(key);

        return choice;  
    }




    int preferencesMenu()
    {
        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);
        int choice = 10;
        
        extapp_drawTextSmall("(0) Level", 0, 20 * 1, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(1) Return to main menu", 0, 20 * 2, 0x0000, 0xFFFF, false);
        extapp_drawTextSmall("(2) Quit", 0, 20 * 3, 0x0000, 0xFFFF, false);

        extapp_waitForVBlank();
        
        waitForKeyPressed();
        int key = extapp_getKey(true, NULL);
        choice = numworksFiguresInput(key);

        if (choice == 1) choice = 3;
        if (choice == 2) choice = 4;
        
        return choice; 
    }




    int askLevel()
    {

        extapp_pushRectUniform(0, 18, 320, 222, 0xFFFF);

        int level = 0;

        extapp_drawTextSmall("Enter level:", 0, 20 * 1, 0x0000, 0xFFFF, false);

        extapp_waitForVBlank();
        //find a way to draw numbers
        
        while (1) {
            waitForKeyPressed();
            
            int key = extapp_getKey(true, NULL);
            if (numworksFiguresInput(key) != -1) {
                level *= 10;
                level += numworksFiguresInput(key);
                //function to actualise score shown
            } else {
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
    }

#endif

#if defined(WIN32) || defined(__linux__)

    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>



    void deathMsg(char *msg) 
    {
        COORD coord;
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("%s", msg);
    }    
    



    void firstImage(int playground_width, int playground_height, int current_length, int positions[2][100], int fruit_x, int fruit_y, int *level)
    {
        
        system("cls");
        
        for (int i = 0; i <= playground_width+1; i++) {
            printf("#");
        }
        printf("\n");

        for (int i = playground_height - 1; i >= 0; i--) {
            printf("#");
            for (int j = 0; j < playground_width; j++) {
                for (int k = 0; k < current_length; k++) {
                    if (j == positions[0][k] && i == positions[1][k]) {
                        printf("o");
                        goto hell;
                    }
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




    void drawPoint(int x, int y, int playground_height, int type)
    {
        COORD coord;
        coord.X = x + 1;
        coord.Y = playground_height - y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        switch (type) {
            case SNAKE:
                printf("o");
                break;

            case FRUIT:
                printf("z");
                break;

            case NOTHING:
                printf(" ");
                break;
        }
    }




    void flushBuffer()
    {
        int c = 0;
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }
    }




    void reDraw(int playground_width, int playground_height, int current_length, int positions[2][100], int fruit_x, int fruit_y, int *level)
    {
        COORD coord;
        coord.X = 8;
        coord.Y = playground_height + 3;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        //do a init image like for NUMWORkS, maybe in a method
        // go to height + 2# + 2; x = current_length("level = ");case <10 blabla, case <100 blabla...
        printf("%d", *level);
    }




    void welcomeMessage()
    {
        printf("\n\n");
        printf("\x1B[36mWelcome in Cnake !!\033[0m\t\t");
        printf("\n\n");
    }




    int defaultMenu()
    { 
        
        int choice = 0;
        
        printf("- (0) Start a new game\n");
        printf("- (1) Preferences\n");
        printf("- (2) Quit\n");
        printf(">");

        scanf("%d", &choice);
        flushBuffer();

        return choice;
    }




    int preferencesMenu()
    {
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




    int askLevel()
    {
        int level = 0;

        printf("\nWhat level do you want to start with ? \n");
        printf(">");

        scanf("%d", &level);
        flushBuffer();

        return level;
    }




    int askPlaygroundWidth()
    {
        int playground_width = 0;

        printf("\nWhat width do you want to play with ? \n");
        printf(">");

        scanf("%d", &playground_width);
        flushBuffer();

        return playground_width;
    }




    int askPlaygroundHeight()
    {
        int playground_height = 0;

        printf("\nWhat height do you want to play with ? \n");
        printf(">");

        scanf("%d", &playground_height);
        flushBuffer();

        return playground_height;
    }

#endif
