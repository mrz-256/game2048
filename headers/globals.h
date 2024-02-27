#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <time.h>
#include <stdlib.h>


extern const char* TITLE;
extern const int TILE_SIZE;
extern const int TILES;

extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern TTF_Font *font;

/// boolean if the game is running
extern int running;
/// the 2D array of tiles
extern int* tiles;


/// the texture used for rendering any numbers
extern SDL_Texture *number;
/// the color of the number texture
extern SDL_Color text_color;
extern int number_width;
extern int number_height;

/// the total sum of all joined tiles
extern int score;

/// The direction of current slide
extern int slide_direction;
enum SlideDirection{
    DIRECTION_LEFT, DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_DOWN, DIRECTION_NONE
};
