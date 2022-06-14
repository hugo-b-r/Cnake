/*

windows_gfx.c

file for windows gfx

*/



#include <stdio.h>
#include <stdlib.h>



void reDraw(int playground_width, int playground_height, int length, int positions[2][100], int fruit_x, int fruit_y, int *level) {

    system("cls");
        
    for (int i = playground_height - 1; i >= 0; i--) {
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
        printf("\n");
    }
    printf("\npoints: %d\n", *level);
}