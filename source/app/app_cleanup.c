#include "../../headers/app.h"

void onCleanup()
{
    if (tiles != NULL)
    {
        free(tiles);
        tiles = NULL;
    }
    SDL_DestroyTexture(number);

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}