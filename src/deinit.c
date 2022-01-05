/*

deinit.c

deinit functions

*/

#include <SDL2/SDL.h>


void Game_Quit(SDL_Window** window, SDL_Renderer** renderer)
{
    if(*renderer != NULL)
    {
        //Destroy renderer
	    SDL_DestroyRenderer(*renderer);
    }

    if(*window != NULL)
    {
        //Destroy window
  	    SDL_DestroyWindow(*window);
    }

  	SDL_Quit();

  	exit(EXIT_SUCCESS);
}
