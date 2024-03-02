#include "../../headers/app.h"


int createNumberTexture(int value, SDL_Color color)
{
    // create text
    char text[20];
    sprintf(text, "%d", value);

    // create surface from text
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, color);
    if (text_surface == NULL)
    {
        printf("error creating `number` (%s)", text);
        return -1;
    }

    // create texture from surface
    SDL_DestroyTexture(number);
    number = SDL_CreateTextureFromSurface(renderer, text_surface);

    number_width = text_surface->w;
    number_height = text_surface->h;
    free(text_surface);

    return number == NULL;
}

void renderNumberTextureAt(int x, int y)
{
    if (number == NULL) return;

    SDL_Rect destination = {
            x,
            y,
            number_width,
            number_height
    };
    SDL_RenderCopy(renderer, number, NULL, &destination);
}

/// A helper function to render a tile rectangle
void renderTile(int x, int y)
{
    // find position to render it at
    int padding = 2;
    SDL_Rect destination = {
            x * TILE_SIZE + padding,
            (y + 1) * TILE_SIZE + padding,
            TILE_SIZE - padding * 2,
            TILE_SIZE - padding * 2
    };

    // choose color
    if (tiles[y * TILES + x] == 0)
    {
        SDL_SetRenderDrawColor(renderer, 0xef, 0xef, 0xef, 0xff);
    } else
    {
        int color = 255 / (tiles[y*TILES + x] + 1);
        SDL_SetRenderDrawColor(renderer, color, color, color, 0xff);
    }

    // render the tile
    SDL_RenderFillRect(renderer, &destination);
}


void onRender()
{
    // clear display
    SDL_SetRenderDrawColor(renderer, 0xcf, 0xcf, 0xaf, 0xff);
    SDL_RenderClear(renderer);

    // write score
    createNumberTexture(score, black_color);
    renderNumberTextureAt(TILE_SIZE / 2 - number_width / 2, TILE_SIZE / 2 - number_height / 2);

    // write steps count
    createNumberTexture(count, black_color);
    renderNumberTextureAt(TILES*TILE_SIZE - TILE_SIZE / 2 - number_width / 2, TILE_SIZE / 2 - number_height / 2);

    // print the tiles
    for (int y = 0; y < TILES; y++)
    {
        for (int x = 0; x < TILES; x++)
        {
            renderTile(x, y);

            // doesn't render value 0
            if (tiles[y*TILES + x] == 0) continue;

            createNumberTexture(tiles[y * TILES + x], white_color);
            renderNumberTextureAt(
                    x * TILE_SIZE + TILE_SIZE / 2 - number_width / 2,
                    (y + 1) * TILE_SIZE + TILE_SIZE / 2 - number_height / 2
            );

        }
    }

    // render everything
    SDL_RenderPresent(renderer);
}
