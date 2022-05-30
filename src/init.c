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
