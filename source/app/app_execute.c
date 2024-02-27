#include "../../headers/app.h"

int onExecute()
{
    if (onInit() < 0 || onLoadMedia() < 0)
    {
        onCleanup();
        return -1;
    }

    SDL_ShowWindow(window);
    clock_t last = clock();
    while (running)
    {
        clock_t current = clock();
        if ((current - last) * 1000 / CLOCKS_PER_SEC  < 50) continue;
        last = current;

        onInput();
        onLoop();
        onRender();
    }

    onCleanup();
    return 0;
}

int main()
{
    return onExecute();
}