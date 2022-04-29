/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
#define PLAYGROUND_X 50
#define PLAYGROUND_Y 30
#define LENGTH PLAYGROUND_X*PLAYGROUND_Y
=======
#include "positions.h"
#include "init.h"
#include "buffer.h"
>>>>>>> dev




void incrLength(int (*positions)[2][100], int *length, int length_diff, int head_position)
{   
    for (int i = 0; i < *length - head_position - 1; i++) {
        (*positions)[0][*length - i - 1 + length_diff] = (*positions)[0][*length - i - 1];
        (*positions)[1][*length - i - 1 + length_diff] = (*positions)[1][*length - i - 1];
    }
    *length += length_diff;
}




void getKeyboardEntry(char *command)
{
    if (KEYBOARDHIT) {
        *command = GETCHAR;
    }
}



<<<<<<< HEAD
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
=======

void pauseLoop(char *command)
{
    while (*command == 'p') {
        getKeyboardEntry(command);
    }
>>>>>>> dev
}




void testEvents(int *orientation, char *command)
{ 
    switch (*command) {
    case 'z':
        if (*orientation != 180) {
            *orientation = 0;
        }
        break;

    case 'q':
        if (*orientation != 90) {
            *orientation = 270;
        }
        break;

    case 's':
        if (*orientation != 0) {
            *orientation = 180;
        }
       break;
 
    case 'd':
        if (*orientation != 270) {
            *orientation = 90;
        }
        break;
    case 'x':
        quit(3);
        break;
    case 'p':
        pauseLoop(command);
        break;
    }
}




int main(int argc, char* argv[])
{
    srand(time(0));
   
    char command = 'a';
    
    int points = 0;
    
    //fruit pos
    int fruit_x = rand() % (PLAYGROUND_X);
    int fruit_y = rand() % (PLAYGROUND_Y);


    char buffer[PLAYGROUND_X][PLAYGROUND_Y];   
    
    int length = LENGTH;
    int positions[2][100];
    int head_position = LENGTH-1;
    int tail_position = 0; 
    //speed set up
    int last_clock = clock();
    int move_time = 300;

    int orientation = 0;
    
    initVar(&positions, &orientation, &buffer);

    while (command != 'x') {
        
        getKeyboardEntry(&command);
        testEvents(&orientation, &command);

        if (last_clock + move_time <= clock()) {
            
            
            newPos(&tail_position, &head_position, &positions, orientation, length);
            
            //if on fruit
            if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
            
                fruit_x = rand() % (PLAYGROUND_X);
                fruit_y = rand() % (PLAYGROUND_Y);
                incrLength(&positions, &length, 1, head_position);
                points += 1;
                move_time -= 10;
            }

        newPos(&tail_position, &head_position, &positions, orientation, &command, &length, &length_to_add);

        clearBuffer(&buffer);

        for (int i = 0; i < length; i++) {
            if (!((positions[0][i] == -1) && (positions[1][i] == -1))) {
                buffer[positions[0][i]][positions[1][i]] = 'o';
            }
        }

        buffer[fruit_x][fruit_y] = 'z';

        system("cls");

        printBuffer(&buffer);
        printf("\npoints: %d\n", points);

    }
}
