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





void preferences(int *level, int *playground_width, int *playground_height) {
    char buffer = '0';
    
    printf("\n");
    printf("- (1) Level\n");
    printf("- (2) Width of the playground\n");
    printf("- (3) Height of the playground\n");
    printf("- (x) Return to main menu\n");
    printf("- (k) Quit\n");
    printf(">");

    scanf("%c", &buffer);
        
    switch (buffer) {
        case '1':
            printf("\nWhat level do you want to start with ? \n");
            printf(">");
            scanf("%d", level);
            break;

        case '2':
            printf("\nWhat width do you want to play with ? \n");
            printf(">");
            scanf("%d", playground_width);
            break;

        case '3':
            printf("\nWhat height do you want to play with ? \n");
            printf(">");
            scanf("%d", playground_height);
            break;

        case 'x':
            return;   
        
        case 'k':
            quit(3);
    }
    printf("\n");
}