#include <SDL2/SDL.h>
#include <stdio.h>
#include "defs.h"
#include "functions.h"
#include "structs.h"


void prepareScene() {
    SDL_SetRenderDrawColor(app.renderer, 96, 20, 255, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene() {
    SDL_RenderPresent(app.renderer);
}

void initSDL() {
    int rendererFlags, windowFlags;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    app.window = SDL_CreateWindow("Champ Select", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, windowFlags);
    if (!app.window) {
        printf("couldn't create window: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
    if (!app.renderer) {
        printf("couldn't create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

void doInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;

            default:
                break;
        }
    }
}

void cleanup() {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
}

SDL_Texture *loadTexture(char *filename) {
    SDL_Texture *texture;
    texture = IMG_LoadTexture(app.renderer, filename);
    return texture;
}

void blit(SDL_Texture *texture, int x, int y) {
    SDL_Rect dest;

}