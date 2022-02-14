/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define PLAYGROUND_X 50
#define PLAYGROUND_Y 30

void newPos(int *x, int *y, int orientation)
{
    switch (orientation) {
    case 0:
        if (*y != PLAYGROUND_Y - 1) {
            *y += 1;
        }
        break;
    case 90:
        if (*x != PLAYGROUND_X - 2 || *x != PLAYGROUND_X - 2) {
            *x += 2;
        }
        break;
    case 180:
        if (*y != 0) {
            *y -= 1;
        }
        break;
    case 270:
        if (*x != 0 || *x != 0) {
            *x -= 2;
        }
    }
}


void clearBuffer(char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y])
{
    for (int i = PLAYGROUND_Y - 1; i > 0; i--) {

        for (int j = 0; j < PLAYGROUND_X; j++) {
            (*buffer)[j][i] = ' ';
        }
    }
}



void printBuffer(char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y])
{
    for (int i = PLAYGROUND_Y - 1; i > 0; i--) {

        for (int j = 0; j < PLAYGROUND_X; j++) {
            printf("%c", (*buffer)[j][i]);
        }

        printf("\n");
    }
}



int main(int argc, char* argv[])
{
    char command = 'a';

    char buffer[PLAYGROUND_X][PLAYGROUND_Y];
    clearBuffer(&buffer);

    int x = 0;
    int y = 0;

    int orientation = 0;

    while (command != 'x') {

        if (kbhit()) {
            switch (getch()) {
            case 'z':
                orientation = 0;
                break;

            case 'q':
                orientation = 270;
                break;

            case 's':
                orientation = 180;
                break;

            case 'd':
                orientation = 90;
                break;

            case 'x':
                return EXIT_SUCCESS;
            }
        }

        newPos( &x, &y, orientation );

        clearBuffer(&buffer);

        buffer[x][y] = 'o';

        system("cls");

        printBuffer(&buffer);
    }
}
