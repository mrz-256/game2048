#include "../headers/logic.h"


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
            tiles[y * TILES + right] = 0;
            right++;

            if (value == 0) continue;

            if (left >= 0 && tiles[y * TILES + left] == value)
            {
                tiles[y * TILES + left] *= 2;
                if (!ALLOW_MAX_SLIDE) left++;
                if (value * 2 > score) score = value * 2;
            } else
            {
                tiles[y * TILES + ++left] = value;
            }
        }
    }
}

void slide_right()
{
    for (int y = TILES - 1; y >= 0; y--)
    {
        int right = TILES;
        int left = TILES - 1;

        while (left >= 0)
        {
            int value = tiles[y * TILES + left];
            tiles[y * TILES + left] = 0;
            left--;

            if (value == 0) continue;

            if (right < TILES && tiles[y * TILES + right] == value)
            {
                tiles[y * TILES + right] *= 2;
                if (!ALLOW_MAX_SLIDE) right--;
                if (value * 2 > score) score = value * 2;
            } else
            {
                tiles[y * TILES + --right] = value;
            }
        }
    }
}

void slide_up()
{
    for (int x = 0; x < TILES; x++)
    {
        int up = -1;
        int down = 0;

        while (down < TILES)
        {
            int value = tiles[down * TILES + x];
            tiles[down * TILES + x] = 0;
            down++;

            if (value == 0) continue;

            if (up >= 0 && tiles[up * TILES + x] == value)
            {
                tiles[up * TILES + x] *= 2;
                if (!ALLOW_MAX_SLIDE) up++;
                if (value * 2 > score) score = value * 2;
            } else
            {
                tiles[++up * TILES + x] = value;
            }
        }
    }
}

void slide_down()
{
    for (int x = TILES - 1; x >= 0; x--)
    {
        int down = TILES;
        int up = TILES - 1;

        while (up >= 0)
        {
            int value = tiles[up * TILES + x];
            tiles[up * TILES + x] = 0;
            up--;

            if (value == 0) continue;

            if (down < TILES && tiles[down * TILES + x] == value)
            {
                tiles[down * TILES + x] *= 2;
                if (!ALLOW_MAX_SLIDE) down--;
                if (value * 2 > score) score = value * 2;
            } else
            {
                tiles[--down * TILES + x] = value;
            }
        }
    }
}

void reset()
{
    for (int i = 0; i < TILES * TILES; i++)
    {
        tiles[i] = 0;
    }
    score = 0;
    count = 0;
}

void add_random()
{
    int x, y;
    do
    {
        x = rand() % TILES;
        y = rand() % TILES;
    } while (tiles[y * TILES + x] != 0);

    tiles[y*TILES + x] = 1 +  rand() % 2;
}

int check_if_lost()
{
    for(int i=0; i<TILES*TILES; i++)
    {
        if (tiles[i]==0) return 0;
    }
    return 1;
}
