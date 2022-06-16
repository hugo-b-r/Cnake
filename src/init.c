/*

init.c

function for init and deinit

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void quit(int type)
{
    switch (type) {
        case 1:
            printf("\nOuch!\n");
            break; 
        case 2: 
            printf("\nGood Job!\n");
            break;
        case 3:
            printf("\nBye bye !\n\n");
    }
    //exit(0);
}
