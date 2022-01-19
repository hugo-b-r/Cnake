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
	TTF_Font* font;
	SDL_Color font_color = { 255, 255, 255 };

	Init_SDL(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT, &font);



	Draw_Button(&renderer, SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2, 200, 20);


	SDL_Surface * surface_text = TTF_RenderText_Solid(font, "Test button", font_color);


	SDL_Texture * text_texture = SDL_CreateTextureFromSurface(renderer, surface_text);
	int texW =  0;
	int texH = 0;
	SDL_QueryTexture(text_texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2, 0, 0 };

	SDL_RenderCopy(renderer, text_texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);

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
	Game_Quit(&window, &renderer, &font);
}
