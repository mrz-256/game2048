#include "../headers/globals.h"

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;
TTF_Font *font = NULL;


const char* TITLE = "2048";
const int TILE_SIZE = 48;
const int TILES = 8;
int ALLOW_MAX_SLIDE = 1;


SDL_Texture *number;
SDL_Color white_color = {0xdf, 0xdf, 0xdf, 0xff};
SDL_Color black_color = {0x0, 0x0, 0x0, 0xff};
int number_width;
int number_height;


int running = 1;
int* tiles;
int score = 0;
int count = 0;


int input = NONE;