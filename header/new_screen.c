/*

new_screen.c

functions for the same named header

*/



#include <stdio.h>
#include <string.h>
#include "new_screen.h"

int ScreenUpdate(string &game, int &score)
{
  system("cls");
  printf("Score:%d\n
                  \n
                  %s", &score, &game)
}
