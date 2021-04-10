#include <SDL2/SDL.h>
#include <stdio.h>
#include "defs.h"
#include "functions.h"

int getUserChoice(int nbrOfChampions) {
    puts("how many champs to load?");
    scanf("%d", &nbrOfChampions);
    return nbrOfChampions;
}


Champion *loadChampionList() {
    int nbrOfChamps = 10;
    Champion *list;
    list = malloc(sizeof(list) * nbrOfChamps);
    for (int i = 0; i < 10; ++i) {
        (list + i)->name = malloc(sizeof(char) * 15);
        (list + i)->thumbnailImage = malloc(sizeof(char) * 30);
    }
    (list)->name = "aatrox";
    (list + 1)->name = "darius";
    (list + 2)->name = "diana";
    (list + 3)->name = "gangplank";
    (list + 4)->name = "katarina";
    (list + 5)->name = "leblanc";
    (list + 6)->name = "mordekaiser";
    (list + 7)->name = "talon";
    (list + 8)->name = "vladimir";
    (list + 9)->name = "zed";

    (list)->thumbnailImage = "champs/aatroxIcon.jpg";
    (list + 1)->thumbnailImage = "champs/dariusIcon.jpg";
    (list + 2)->thumbnailImage = "champs/dianaIcon.jpg";
    (list + 3)->thumbnailImage = "champs/gangplankIcon.jpg";
    (list + 4)->thumbnailImage = "champs/katarinaIcon.jpg";
    (list + 5)->thumbnailImage = "champs/leblancIcon.jpg";
    (list + 6)->thumbnailImage = "champs/mordekaiserIcon.jpg";
    (list + 7)->thumbnailImage = "champs/talonIcon.jpg";
    (list + 8)->thumbnailImage = "champs/vladimirIcon.jpg";
    (list + 9)->thumbnailImage = "champs/zedIcon.jpg";

    return list;
}


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
    SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
    if (!app.renderer) {
        printf("couldn't create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}


void doInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    exit(0);
                break;
            default:
                break;
        }
    }
}


void *loadTextures(Champion *list, int nbrOfChamps) {
    for (int i = 0; i < nbrOfChamps; ++i) {
        (list + i)->texture = IMG_LoadTexture(app.renderer, (list + i)->thumbnailImage);
    }
}


void blit(SDL_Texture *texture, int x, int y) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = CHAMPION_THUMBNAIL_SIZE;
    dest.h = CHAMPION_THUMBNAIL_SIZE;

    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}


void renderChamps(Champion *list, int nbrOfChamps) {
    for (int i = 0; i < nbrOfChamps; ++i) {
        blit((list + i)->texture, (list + i)->x, (list + i)->y);
    }
}

void *calculateChampionPositions(Champion *list, int nbrOfChamps) {
    int nbrOfLines = nbrOfChamps / CHAMPS_PER_LINE;
    if (nbrOfChamps % CHAMPS_PER_LINE != 0)
        nbrOfLines++;

    int offsetX = getFirstChampionHorizontalOffset();
    int offsetY = getFirstChampionVerticalOffset(nbrOfLines);

    int championX, championY;
    for (int i = 0; i < nbrOfChamps; ++i) {
        Champion *champion = (list + i);
        championX = offsetX + (i % CHAMPS_PER_LINE) * (CHAMPION_THUMBNAIL_SIZE + LINE_SPACING);
        championY = offsetY + (i / CHAMPS_PER_LINE) * (CHAMPION_THUMBNAIL_SIZE + LINE_SPACING);
        champion->x = championX;
        champion->y = championY;
    }
}

int getFirstChampionHorizontalOffset() {
    int thumbnailsViewportWidth = SCREEN_WIDTH * 2 / 3;
    int widthStartOffset = SCREEN_WIDTH - thumbnailsViewportWidth;
    int nbrOfInnerMargins = CHAMPS_PER_LINE - 1;
    int innerMarginsTotal = nbrOfInnerMargins * INNER_MARGIN;
    int championThumbsTotalWidth = CHAMPS_PER_LINE * CHAMPION_THUMBNAIL_SIZE;
    int freeWidth = thumbnailsViewportWidth - (innerMarginsTotal + championThumbsTotalWidth);
    return widthStartOffset + (freeWidth / 2);
}

int getFirstChampionVerticalOffset(int nbrOfLines) {
    int viewportHeight = SCREEN_HEIGHT;
    int heightStartOffset = 0;
    int nbrOfInnerMargins = nbrOfLines - 1;
    int innerMarginsTotal = nbrOfInnerMargins * LINE_SPACING;
    int championThumbsTotalHeight = nbrOfLines * CHAMPION_THUMBNAIL_SIZE;
    int freeWidth = viewportHeight - (innerMarginsTotal + championThumbsTotalHeight);
    return heightStartOffset + (freeWidth / 2);
}