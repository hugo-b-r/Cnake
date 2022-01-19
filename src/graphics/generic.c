/*

generic.c

generic drawing functions

*/

#include <SDL2/SDL.h>

void Draw_Button(SDL_Renderer** renderer, int x, int y, int width, int height)
{
  SDL_SetRenderDrawColor(*renderer, 255, 255, 0, 255);

  SDL_Rect rect = {x, y, width, height};

  SDL_RenderFillRect(*renderer, &rect);
  SDL_RenderPresent(*renderer);
}
