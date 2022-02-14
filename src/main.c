/*

main.c

main file for game

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mechanism.h"



int main(int argc, char* argv[])
{
    char command = 'a';

    struct game Game = { .Player1.orientation = 180, .Player1.length = 2, .Player1.Head_Str_Pos = 1, .Player1.Tail_Str_Pos = 0, .Player1.id = 0, .Player1.points = 0};
    Game.Player1.Poss[0][0] = 5;
    Game.Player1.Poss[1][0] = 5;
    Game.Player1.Poss[0][1] = 5;
    Game.Player1.Poss[1][1] = 6;

    clearBuffer(&(Game.buffer));

    while (command != 'x') {

        command = getCommand();
        system("cls");

        switch (command) {
        case 'z':
            Game.Player1.orientation = 0;
            break;

        case 'q':
            Game.Player1.orientation = 270;
            break;

        case 's':
            Game.Player1.orientation = 180;
            break;

        case 'd':
            Game.Player1.orientation = 90;
            break;
        }

        Game.Player1.Poss[0][Game.Player1.Tail_Str_Pos] = newX( Game.Player1.orientation, Game.Player1.Poss[0][Game.Player1.Head_Str_Pos] );
        Game.Player1.Poss[1][Game.Player1.Tail_Str_Pos] = newY( Game.Player1.orientation, Game.Player1.Poss[1][Game.Player1.Head_Str_Pos] );

        Game.Player1.Head_Str_Pos = Game.Player1.Tail_Str_Pos;
        Game.Player1.Tail_Str_Pos += 1;

        clearBuffer(&(Game.buffer));


        for(int i = 0; i < Game.Player1.length; i++){

            Game.buffer[Game.Player1.Poss[0][i]][Game.Player1.Poss[1][i]] = 'o';

        }


        printBuffer(Game.buffer);

    }

    return EXIT_SUCCESS;

}
