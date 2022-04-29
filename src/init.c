/*

init.c

function for init and deinit

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "buffer.h"



#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define LENGTH 5




void initVar(int (*positions)[2][100], int *orientation, char (*buffer)[PLAYGROUND_X][PLAYGROUND_Y]) 
{
    clearBuffer(buffer);
    
    for (int i = 0; i < 100; i++) {
        (*positions)[0][i] = -1;    
        (*positions)[1][i] = -1; 
    }

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
