#include "../../headers/app.h"


void onLoop()
{
    count++;
    if (slide_direction == DIRECTION_LEFT) slide_left();
    else if (slide_direction == DIRECTION_RIGHT) slide_right();
    else if (slide_direction == DIRECTION_UP) slide_up();
    else if (slide_direction == DIRECTION_DOWN) slide_down();
    else count--;

    slide_direction = DIRECTION_NONE;
}