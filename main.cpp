// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include "SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int SDL_main(int argc, char* argv[]){
    SDL_Window     *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0);

    if(window==NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}