/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define LENGTH 5



#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #define KEYBOARDHIT kbhit()
    #define GETCHAR getch()
/*#elif defined(__linux__)*/
#endif




void clearBuffer(char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y])
{
    for (int i = PLAYGROUND_Y - 1; i > 0; i--) {

        for (int j = 0; j < PLAYGROUND_X; j++) {
            (*buffer)[j][i] = ' ';
        }
    }
}





void initVar(int (*positions)[2][LENGTH], int *orientation, char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y]) 
{
    clearBuffer(&(*buffer));
    
    for (int i = 0; i < LENGTH; i++) {
        (*positions)[0][i] = PLAYGROUND_X/2;
        (*positions)[1][i] = PLAYGROUND_Y/2;
        (*positions)[1][i] -= LENGTH/2;
        (*positions)[1][i] += i;      
    }
}




void quit(int type)
{
    switch (type) {
        case 1:
            printf("\nOuch!\n");
            break; 
        case 2: 
            printf("\nGood Job!\n");
            break;
    }
    exit(0);
}



void testEvents(int *orientation)
{ 
    if (KEYBOARDHIT) {
        switch (GETCHAR) {
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
        }
    }
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
    
    int points = 0;
    
    srand(time(0));

    int fruit_x = rand() % (PLAYGROUND_X) + 1;
    int fruit_y = rand() % (PLAYGROUND_Y) + 1;

    char buffer[PLAYGROUND_X][PLAYGROUND_Y];   

    int positions[2][LENGTH];
    int head_position = LENGTH-1;
    int tail_position = 0;  

    int orientation = 0;
    
    initVar(&positions, &orientation, &buffer);

    while (command != 'x') {
        
        testEvents(&orientation);

        newPos(&tail_position, &head_position, &positions, orientation, LENGTH);
        
        //if on fruit
        if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
            
            fruit_x = rand() % (PLAYGROUND_X);
            fruit_y = rand() % (PLAYGROUND_Y);
            points += 1;

        }

        clearBuffer(&buffer);

        for (int i = 0; i < LENGTH; i++) {
            buffer[positions[0][i]][positions[1][i]] = 'o';
        }

        buffer[fruit_x][fruit_y] = 'z';

        system("cls");

        printBuffer(&buffer);
        printf("\npoints: %d\n", points);

    }
}
