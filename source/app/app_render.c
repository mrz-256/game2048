#include "../../headers/app.h"


int createNumberTexture(int value)
{
    // create text
    char text[20];
    sprintf(text, "%d", value);

    // create surface from text
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, text_color);
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
    int padding = 2;
    SDL_Rect destination = {
            x * TILE_SIZE + padding,
            (y + 1) * TILE_SIZE + padding,
            TILE_SIZE - padding * 2,
            TILE_SIZE - padding * 2
    };

    if (tiles[y * TILES + x] == 0)
    {
        SDL_SetRenderDrawColor(renderer, 0x4f, 0x4f, 0x3f, 0xff);
    } else
    {
        SDL_SetRenderDrawColor(renderer, 0x1f, 0x1f, 0x1f, 0xff);
    }

    SDL_RenderFillRect(renderer, &destination);
}


void onRender()
{
    // clear display
    SDL_SetRenderDrawColor(renderer, 0x1f, 0x1f, 0x1f, 0xff);
    SDL_RenderClear(renderer);

    // write score
    createNumberTexture(score);
    renderNumberTextureAt(TILE_SIZE / 2 - number_width / 2, TILE_SIZE / 2 - number_height / 2);

    // write steps count
    createNumberTexture(count);
    renderNumberTextureAt(TILES*TILE_SIZE - TILE_SIZE / 2 - number_width / 2, TILE_SIZE / 2 - number_height / 2);

    // print the tiles
    for (int y = 0; y < TILES; y++)
    {
        for (int x = 0; x < TILES; x++)
        {
            renderTile(x, y);

            // doesn't render value 0
            if (tiles[y*TILES + x] == 0) continue;

            createNumberTexture(tiles[y * TILES + x]);
            renderNumberTextureAt(
                    x * TILE_SIZE + TILE_SIZE / 2 - number_width / 2,
                    (y + 1) * TILE_SIZE + TILE_SIZE / 2 - number_height / 2
            );

        }
    }

    // render everything
    SDL_RenderPresent(renderer);
}
