#include <stdio.h>
#include <SDL2/SDL.h>
#include "defs.h"

int main() {
    int rendererFlags, windowFlags;
    SDL_Renderer *renderer;
    SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    window = SDL_CreateWindow("Champ Select", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);


    return 0;
}
