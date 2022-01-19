/*

init.h

header for init functions

*/

#ifndef __INIT_H__


    #define __INIT_H__

    #include <SDL2/SDL_ttf.h>

    void Init_Subsystems(SDL_Window** window, SDL_Renderer** renderer);

    void Load_TTF_Font(TTF_Font** font, SDL_Window** window, SDL_Renderer** renderer);

    void Create_Window(SDL_Window** window, SDL_Renderer** renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

    void Create_Renderer(SDL_Window** window, SDL_Renderer** renderer);

    void Init_SDL(SDL_Window** window, SDL_Renderer** renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, TTF_Font** font);

#endif
