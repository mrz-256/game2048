#include "../../headers/app.h"

int onInit()
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return -1;
    if (TTF_Init() < 0) return -2;

    // create window
    window = SDL_CreateWindow(
            TITLE,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            TILES * TILE_SIZE,
            (TILES + 1) * TILE_SIZE, // the size of one extra tile is for the score text
            SDL_WINDOW_HIDDEN
    );

    if (window != NULL)
    {
        // create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer != NULL)
        {
            // create tiles
            tiles = calloc(TILES*TILES, sizeof(int));
            add_random();
            return 0;
        }
        else
        {
            SDL_free(window);
            return -4;
        }
    } else
    {
        return -3;
    }
}


