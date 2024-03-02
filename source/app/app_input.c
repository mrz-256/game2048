#include "../../headers/app.h"

void onInput()
{
    SDL_PumpEvents();

    SDL_Event event;
    int sym;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT: running = 0;

            case SDL_KEYDOWN:
                 sym = event.key.keysym.sym;

                if (sym == SDLK_a || sym == SDLK_LEFT) input = SLIDE_LEFT;
                if (sym == SDLK_d || sym == SDLK_RIGHT) input = SLIDE_RIGHT;
                if (sym == SDLK_w || sym == SDLK_UP) input = SLIDE_UP;
                if (sym == SDLK_s || sym == SDLK_DOWN) input = SLIDE_DOWN;
                if (sym == SDLK_r) input = RESET;
        }
    }
    
}