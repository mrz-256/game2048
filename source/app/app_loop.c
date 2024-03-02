#include "../../headers/app.h"


void onLoop()
{
    switch (input)
    {
        case SLIDE_LEFT: slide_left();
            break;
        case SLIDE_RIGHT: slide_right();
            break;
        case SLIDE_UP: slide_up();
            break;
        case SLIDE_DOWN: slide_down();
            break;
        case RESET: reset();
            break;
        default:
            break; // nothing
    }

    if (input != NONE)
    {
        input = NONE;
        count++;
        add_random();
    }


}