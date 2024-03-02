#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <time.h>
#include <stdlib.h>



// * * * * * * * * * * * * * * * * *
// * SDL necessities               *
// * * * * * * * * * * * * * * * * *
extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern TTF_Font *font;


// * * * * * * * * * * * * * * * * *
// * Default settings              *
// * * * * * * * * * * * * * * * * *
extern const char* TITLE;
extern const int TILE_SIZE;
extern const int TILES;
extern int ALLOW_MAX_SLIDE;


// * * * * * * * * * * * * * * * * *
// * The `number` texture          *
// * * * * * * * * * * * * * * * * *
extern SDL_Texture *number;
extern SDL_Color white_color;
extern SDL_Color black_color;
extern int number_width;
extern int number_height;


// * * * * * * * * * * * * * * * * *
// * Game variables                *
// * * * * * * * * * * * * * * * * *
extern int running;
extern int* tiles;
extern int score;
extern int count;


// * * * * * * * * * * * * * * * * *
// * Input                         *
// * * * * * * * * * * * * * * * * *
extern int input;
enum InputType{
    NONE, SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN, RESET
};
