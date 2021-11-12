/*

main.c

main file for game logic

*/

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>


int main(int, char **)
{
  
  if(SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
    return -1;
  }
  else
  {
    printf("SDL2 succesfully loaded VIDEO and AUDIO.")
  }

  SDL_Quit();
  return 0;
}
 