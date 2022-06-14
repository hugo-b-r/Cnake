/*

windows_gfx.c

file for windows gfx

*/



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




char defaultMenu() {
    char buffer = '0';
    
    printf("- (1) Start a new game\n");
    printf("- (2) Preferences\n");
    printf("- (k) Quit\n");
    printf(">");

    scanf("%c", &buffer);
    flushBuffer();

    return buffer;
}




char preferencesMenu() {
    char buffer = '0';
    
    printf("\n");
    printf("- (1) Level\n");
    printf("- (2) Width of the playground\n");
    printf("- (3) Height of the playground\n");
    printf("- (x) Return to main menu\n");
    printf("- (k) Quit\n");
    printf(">");

    scanf("%c", &buffer);
    flushBuffer();

    return buffer;
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
