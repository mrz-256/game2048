#include "../../headers/app.h"

void onInput()
{
    SDL_PumpEvents();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT: running = 0;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_LEFT) slide_direction = DIRECTION_LEFT;
                if (event.key.keysym.sym == SDLK_RIGHT) slide_direction = DIRECTION_RIGHT;
                if (event.key.keysym.sym == SDLK_UP) slide_direction = DIRECTION_UP;
                if (event.key.keysym.sym == SDLK_DOWN) slide_direction = DIRECTION_DOWN;
        }
    }
    
}