#include "structs.h"

void initSDL();

void prepareScene();

void presentScene();

void doInput();

void *loadTextures(Champion *list, int nbrOfChamps);

void *calculateChampionPositions(Champion *list, int nbrOfChamps);

void blit(SDL_Texture *texture, int x, int y);

int getUserChoice(int nbrOfChampions);

Champion *loadChampionList();

int getFirstChampionHorizontalOffset();

int getFirstChampionVerticalOffset(int nbrOfLines);

void renderChamps(Champion *list, int nbrOfChamps);