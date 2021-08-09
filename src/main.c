/*

main.c

main file for game logic
*/

#include <stdio.h>
#include <string.h>
#include "new_screen.h"
#include "init.h"

int main()
{
  init();
  
  _Bool continueGame = true;
  string game = "     \n     \n     \n     \n     \n";
  int score = 0;

  while(continueGame)
  {
    ScreenUpdate(&game, &score);
  }

}
