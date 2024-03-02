#include "../headers/globals.h"

const char* TITLE = "2048";
const int TILE_SIZE = 48;
const int TILES = 8;

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;
TTF_Font *font = NULL;

int running = 1;
int* tiles;

SDL_Texture *number;
SDL_Color text_color = {0xdf, 0xdf, 0xdf, 0xff};
int number_width;
int number_height;

int score = 0;
int count = 0;
int slide_direction = DIRECTION_NONE;