#pragma once
#include "globals.h"
#include "logic.h"


/**
 * Initializes SDL, SDL_ttf and the global variables `window` and `renderer` and `tiles`
 * @return 0 on success
 */
int onInit();

/**
 * Loads all loadable media. In this case only global variable `font`
 * @return 0 on success
 */
int onLoadMedia();

/**
 * Runs the actual app.
 */
int onExecute();

/**
 * Is executed on every iteration of main loop.
 */
void onLoop();

/**
 * Processes input from current iteration.
 */
void onInput();

/**
 * Renders everything.
 */
void onRender();

/**
 * Frees all data.
 */
void onCleanup();

/**
 * Used to create the global variable `number` of type SDL_Texture* with an integer value.
 *
 * Defined in app_render.c
 * @param value the number to create the texture with
 * @return 0 on success
 */
int createNumberTexture(int value);

/**
 * Renders the `number` global SDL_Texture at position [x,y]
 * @param x the horizontal position
 * @param y the vertical position
 */
void renderNumberTextureAt(int x, int y);
