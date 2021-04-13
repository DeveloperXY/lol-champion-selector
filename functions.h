#include "structs.h"

void initSDL(int isDebugging);

void prepareScene();

void presentScene();

void doInput(Champion *list, int nbrOfChamps);

void *loadTextures(Champion *list, int nbrOfChamps);

void *calculateChampionPositions(Champion *list, int nbrOfChamps);

void blit(SDL_Texture *texture, int x, int y);

int getUserChoice(int nbrOfChampions);

Champion *loadChampionList(int nbrOfChampions);

int getFirstChampionHorizontalOffset();

int getFirstChampionVerticalOffset(int nbrOfLines);

void renderChamps(Champion *list, int nbrOfChamps);

Champion *getMouseFocusedChampion(Champion *list, int nbrOfChamps, int x, int y);

int mouseWithinChampionBounds(Champion *champion, int x, int y);