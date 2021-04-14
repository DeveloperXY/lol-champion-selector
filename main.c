#include <stdio.h>
#include <SDL2/SDL.h>
#include "defs.h"
#include "functions.h"

int main(int argc, char **argv) {
    int isDebugging = argc > 0;
    int nbrOfChamps = getUserChoice(nbrOfChamps);
    Champion *listOfChamps = loadChampionList(nbrOfChamps);
    calculateChampionPositions(listOfChamps, nbrOfChamps);
    initSDL(isDebugging);
    loadTextures(listOfChamps, nbrOfChamps);
    while (1) {
        prepareScene();
        renderChamps(listOfChamps, nbrOfChamps);
        doInput(listOfChamps, nbrOfChamps);
        presentScene();
        SDL_Delay(16);
    }

    return 0;
}
