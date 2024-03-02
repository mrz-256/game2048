#pragma once
#include "globals.h"

/// slides the tiles left
void slide_left();

/// slides the tiles right
void slide_right();

/// slides the tiles up
void slide_up();

/// slides the tiles down
void slide_down();

/// resets the game
void reset();

/// adds random value to a random tile
void add_random();

/**
 * Checks if player filled all tiles
 * @return 0 if there still are empty tiles
 */
int check_if_lost();
