#include "../../headers/app.h"

int onLoadMedia()
{
    font = TTF_OpenFont("../assets/font.ttf", 12);
    if (font == NULL) return -1;

    return 0;
}