void initSDL();
void prepareScene();
void presentScene();
void doInput();
SDL_Texture *loadTexture(char *filename);
void blit(SDL_Texture *texture, int x, int y);