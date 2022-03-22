/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define LENGTH 10



void quit(int type)
{
    switch (type) {
        case 1:
            printf("ouch!");
            break;
        case 2:
            printf("Good Job!");
            break;
    }
    exit(0);
}




void incrPos(int *tail_position, int *head_position)
{
    (*head_position)++;
    if (*head_position >= LENGTH) {
        *head_position  = 0;
    }
    (*tail_position)++;
    if (*tail_position >= LENGTH) {
        *tail_position  = 0;
    }
}



void newPos(int *tail_position, int *head_position, int (*position)[2][LENGTH], int orientation, int length)
{
    int x = (*position)[0][*head_position];
    int y = (*position)[1][*head_position];

    switch (orientation) {
    case 0:
        y += 1;
        break;
    case 90:
        x += 1;
        break;
    case 180:
        y -= 1;
        break;
    case 270:
        x -= 1;
        break;
    }


    //if on itself
    for (int i = 0; i < length+1; i++) {
        if (x == (*position)[0][i] && y == (*position)[1][i]) {
            quit(1);
        }
    }

    // if border
    if (x >= PLAYGROUND_X || y >= PLAYGROUND_Y || x <= 0 || y <= 0) {
       quit(1); 
    }

    (*position)[0][*tail_position] = x;
    (*position)[1][*tail_position] = y;

    incrPos(tail_position, head_position);

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
    
    for (int i = 0; i < PLAYGROUND_X + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int i = PLAYGROUND_Y - 1; i > 0; i--) {
        
        printf("#");
        for (int j = 0; j < PLAYGROUND_X; j++) {
            printf("%c", (*buffer)[j][i]);
        }

        printf("#\n");
    }

    for (int i = 0; i < PLAYGROUND_X + 2; i++) {
        printf("#");
    }
    printf("\n");
}



int main(int argc, char* argv[])
{
    char command = 'a';

    char buffer[PLAYGROUND_X][PLAYGROUND_Y];
    clearBuffer(&buffer);

    int positions[2][LENGTH];
    int head_position = LENGTH-1;
    int tail_position = 0;

    for (int i = 0; i < LENGTH; i++) {
        positions[0][i] = PLAYGROUND_X/2;
        positions[1][i] = PLAYGROUND_Y/2;
        positions[1][i] -= LENGTH;
        positions[1][i] += i;
        printf("%d, ", positions[1][i]);
    }
    int orientation = 0;

    while (command != 'x') {

        if (kbhit()) {
            switch (getch()) {
            case 'z':
                if (orientation != 180) {
                    orientation = 0;
                }
                break;

            case 'q':
                if (orientation != 90) {
                    orientation = 270;
                }
                break;

            case 's':
                if (orientation != 0) {
                    orientation = 180;
                }
                break;

            case 'd':
                if (orientation != 270) {
                    orientation = 90;
                }
                break;

            case 'x':
                quit(1);
            }
        }

        newPos(&tail_position, &head_position, &positions, orientation, LENGTH);

        clearBuffer(&buffer);

        for (int i = 0; i < LENGTH; i++) {
            buffer[positions[0][i]][positions[1][i]] = 'o';
        }

        system("cls");

        printBuffer(&buffer);

    }
}
