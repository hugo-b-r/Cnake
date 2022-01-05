/*

init.c

init functions

*/

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include "init.h"




//init subsystems of SDL2
void Init_Subsystems(SDL_Window** window, SDL_Renderer** renderer)
{
    if(SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
  	{
   		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
    	Game_Quit(window,  renderer);
  	}
  	else
  	{
  		//log
    	printf("SDL2 succesfully loaded VIDEO and AUDIO!\n");
    }

}




//to create a window
void Create_Window(SDL_Window** window, SDL_Renderer** renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    //create the windows
    *window = SDL_CreateWindow("Cnake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if(*window == NULL )
    {
      	fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        Game_Quit(window,  renderer);
    }
    else
    {
        printf("SDL successfully created a window!\n");
    }
}




//to create a renderer from a window
void Create_Renderer(SDL_Window** window, SDL_Renderer** renderer)
{
    //create renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if(*renderer == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        Game_Quit(window, renderer);
    }
    else
    {
        printf("SDL successfully created a renderer!\n\n");
    }

}




void Init_SDL(SDL_Window** window, SDL_Renderer** renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
  Init_Subsystems(window, renderer);

  Create_Window(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  Create_Renderer(window, renderer);
}
