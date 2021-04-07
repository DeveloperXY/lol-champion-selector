#include "SDL2/SDL_image.h"

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

App app;

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
} Champion ;

Champion talon,kata,darius,zed;