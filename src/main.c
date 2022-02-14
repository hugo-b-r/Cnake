/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char getCommand();

int newX (int orientation, int oldX);

int newY (int orientation, int oldY);

void clearBuffer(char (*buffer)[10][10]);

void printBuffer(char buffer[10][10]);


int main(int argc, char* argv[])
{
    char command = 'a';

    char buffer[10][10];
    clearBuffer(&buffer);

    int positions[2][10];

    int tail_position = 0;
    int head_position = 0;
    int length = 1;

    while (command != 'x') {

        command = getCommand();
        system("cls");

        switch (command) {
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
        }

        newPos( &(positions[0][tail_position]), &(positions[1][tail_position]), orientation  );

        tail_position += 1;
        head_position += 1;

        clearBuffer(&(buffer));


        for(int i = 0; i < length; i++){

            buffer[positions[0][i]][positions[1][i]] = 'o';

        }

        printBuffer(buffer);

    }

    return EXIT_SUCCESS;

}




char getCommand()
{
    #if (defined(_WIN32) || defined(WIN32))

        #include <conio.h>

        if (kbhit()) {
            return geth();
        }

    #elif defined(linux)

            return system("read -n1");

    #endif
}


void newPos(int *x, int *y, int orientation)
{
    switch (orientation) {
    case 0:
        *x += 1;
        break;
    case 90:
        *y += 1;
        break;
    case 180:
        *x -= 1;
        break;
    case 270:
        *y -= 1;
    }
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
