#include <SDL2/SDL.h>
#include "defs.h"
#include "functions.h"

int main(int argc, char **argv) {
    int nbrOfChamps = getUserChoice(nbrOfChamps);
    Champion *listOfChamps = loadChampionList();
    initSDL();
    loadTextures(listOfChamps, nbrOfChamps);
    calculateChampionPositions(listOfChamps, nbrOfChamps);
    while (1) {
        prepareScene();
        renderChamps(listOfChamps, nbrOfChamps);
        doInput();
        presentScene();
        SDL_Delay(16);
    }

    return 0;
}
