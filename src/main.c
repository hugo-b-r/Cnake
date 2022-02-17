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
#define LENGTH PLAYGROUND_X*PLAYGROUND_Y



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



void newPos(int *tail_position, int *head_position, int (*positions)[2][LENGTH], int orientation, char *command, int *length, int *length_to_add)
{
    int x = (*positions)[0][*head_position];
    int y = (*positions)[1][*head_position];

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

    // if border
    if (x >= PLAYGROUND_X || y >= PLAYGROUND_Y || x <= 0 || y <= 0) {
        *command ='x';
    }

    if (length_to_add > 0) {
        for (int i = length-tail_position-1; i >= 0; i--) {
            (*positions)[0][*tail_position + i] = (*positions)[0][*tail_position + i - 1];
            (*positions)[1][*tail_position + i] = (*positions)[1][*tail_position + i - 1];
        }
        *length += 1;
        *length_to_add -= 1;
    }

    (*positions)[0][*tail_position] = x;
    (*positions)[1][*tail_position] = y;
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

    int length = 2;
    int length_to_add = 0;
    int positions[2][LENGTH];
    int head_position = length-1;
    int tail_position = 0;

    for (int i = 0; i < length; i++) {
        positions[0][i] = PLAYGROUND_X/2;
        positions[1][i] = PLAYGROUND_Y/2;
        positions[1][i] -= length;
        positions[1][i] += i;
        printf("%d, ", positions[1][i]);
    }
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
                printf("Ouch...");
                return EXIT_SUCCESS;
            }
        }

        newPos(&tail_position, &head_position, &positions, orientation, &command, &length, &length_to_add);

        clearBuffer(&buffer);

        for (int i = 0; i < length; i++) {
            buffer[positions[0][i]][positions[1][i]] = 'o';
        }

        system("cls");

        printBuffer(&buffer);

    }
}
