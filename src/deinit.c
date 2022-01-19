/*

deinit.c

deinit functions

*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


void Game_Quit(SDL_Window** window, SDL_Renderer** renderer, TTF_Font** font)
{
    if(font != NULL)
    {
        TTF_CloseFont(*font);
    }
    if(*renderer != NULL)
    {
	    SDL_DestroyRenderer(*renderer);
    }

    if(*window != NULL)
    {
  	    SDL_DestroyWindow(*window);
    }

  	SDL_Quit();

  	exit(EXIT_SUCCESS);
}
