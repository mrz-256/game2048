#include "../../headers/app.h"

int onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return -1;
    if (TTF_Init() < 0) return -2;

    window = SDL_CreateWindow(
            TITLE,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            TILES * TILE_SIZE,
            (TILES + 1) * TILE_SIZE, // the size of one extra tile is for the score text
            SDL_WINDOW_HIDDEN
    );

    if (window != NULL)
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer != NULL)
        {
            tiles = calloc(TILES*TILES, sizeof(int));
            tiles[0] = 8;
            tiles[1] = 1;// todo: remove test values
            tiles[3] = 1;//...
            tiles[5] = 2;//...
            tiles[7] = 4;//...
            tiles[12] = 8;//...
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


