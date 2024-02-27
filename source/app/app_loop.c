#include "../../headers/app.h"

void dumpRow(int row, int left, int right)
{
    for(int x=0; x<TILES; x++)
    {
        printf("%i ", tiles[row*TILES + x]);
    }
    printf("  -- %i %i\n", left, right);
}

void slide_left()
{
    // 0 1 0 1 0 0 0 0
    // 0 1 0 1 0 0 0 0
    // 1 0 0 1 0 0 0 0
    // 1 0 0 1 0 0 0 0
    // 2 0 0 0 0 0 0 0
    // ...

    for (int y = 0; y < TILES; y++)
    {
        int left = -1;
        int right = 0;

        while (right < TILES)
        {
            int value = tiles[y * TILES + right];
            tiles[y*TILES + right] = 0;
            right++;

            if (value == 0)
            {
                continue;
            }

            if (left >= 0 & tiles[y*TILES + left] == value)
            {
                tiles[y*TILES + left] *= 2;
                score += value;
            }
            else
            {
                tiles[y * TILES + ++left] = value;
            }
        }
    }
}


void onLoop()
{
    if (slide_direction == DIRECTION_LEFT) slide_left();

    slide_direction = DIRECTION_NONE;
}