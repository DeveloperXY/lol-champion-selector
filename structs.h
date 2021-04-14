#include "SDL2/SDL_image.h"

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
    char *name;
    char *iconImage;
} Champion;


typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int mouseX;
    int mouseY;
    Champion *champion;
} App;

App app;
SDL_Rect selectedChampionOutline;