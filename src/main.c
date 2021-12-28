/*

main.c

main file for game

*/

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include "init.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int Set_Background(SDL_Window** window, SDL_Renderer** renderer, SDL_Color color);


int main(int argc, char* argv[])
{

	SDL_Window* window = NULL;

	SDL_Renderer* renderer = NULL;

	SDL_Color rouge = {255, 0, 0, 255};
	SDL_Color orange = {255, 127, 40, 255};
	SDL_Color vert = {0, 255, 0, 255};
	SDL_Color white = {255, 255, 255, 255};


	Init_Subsystems(&window, &renderer);

  Create_Window(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  Create_Renderer(&window, &renderer);


	SDL_Event events;
	_Bool isOpen = 1;
	while (isOpen)
	{
    	while (SDL_PollEvent(&events))
    	{
      	switch (events.type)
      		{
      		case SDL_QUIT:
					isOpen = 0;
        			break;
      		}

    	}
  	}
	Game_Quit(&window, &renderer);
}


int Set_Background(SDL_Window** window, SDL_Renderer** renderer, SDL_Color color)
{
	if(0 != SDL_SetRenderDrawColor(*renderer, color.r, color.g, color.b, color.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Game_Quit(window, renderer);
    }

    if(0 != SDL_RenderClear(*renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Game_Quit(window, renderer);
    }

	SDL_RenderPresent(*renderer);
	return 0;
}
