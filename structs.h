#include "SDL2/SDL_image.h"

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int mouseX;
    int mouseY;
} App;

App app;

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
    char *name;
    char *thumbnailImage;
} Champion;


