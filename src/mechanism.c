/*


game logic

*/
#include <stdio.h>
#include <stdlib.h>
#include "mechanism.h"


char getCommand()
{
    #if (defined(_WIN32) || defined(WIN32))

        #include <conio.h>

        return getch();

    #elif defined(linux)

            return system("read -n1");

    #endif
}



int newX (int orientation, int oldX)
{
    int newX = oldX;

    if (orientation == 90) {
        newX += 1;
    } else {
        newX -= 1;
    }

    return newX;
}



int newY (int orientation, int oldY)
{
    int newY = oldY;

    if (orientation == 180) {
        newY += 1;
    } else {
        newY -= 1;
    }

    return newY;
}



void clearBuffer(char (*buffer)[10][10])
{
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
            *buffer[i][j] = ' ';
        }
    }
}



void printBuffer(char buffer[10][10])
{
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
            printf("%c", buffer[i][j]);
        }

        printf("\n");
    }
}
