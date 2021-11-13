/*

init.h

header for init functions

*/

#ifndef __INIT_H__

#define __INIT_H__


#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>



void Init_Subsystems(SDL_Window** window, SDL_Renderer** renderer);

void Create_Window(SDL_Window** window, SDL_Renderer** renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

void Create_Renderer(SDL_Window** window, SDL_Renderer** renderer);

void Game_Quit(SDL_Window** window, SDL_Renderer** renderer);

#endif

