/*

mechanism.h

game logic headers

*/

#ifndef MECHANISM_H

#define MECHANISM_H



struct position
{
    int x;
    int y;
};

struct player
{
    int Head_Str_Pos;
    int Tail_Str_Pos;
    int length;
    int orientation;
    int id;
    int points;
    int Poss[2][100];
};

struct game
{
    struct player Player1;
    struct position Apple_Pos;
    char buffer[10][10];
};

char getCommand();

int newX (int orientation, int oldX);

int newY (int orientation, int oldY);

void clearBuffer(char (*buffer)[10][10]);

void printBuffer(char buffer[10][10]);


#endif
