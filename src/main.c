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
#include "mechanism/mechanism.h"
#include "deinit.h"
#include "graphics/generic.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int Set_Background(SDL_Window** window, SDL_Renderer** renderer, SDL_Color color);


int main(int argc, char* argv[])
{

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	Init_SDL(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

	Draw_Button(&renderer, 50, 50, 200, 200);

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
