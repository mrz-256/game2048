cmake_minimum_required(VERSION 3.26)
project(game2048 C)

set(CMAKE_C_STANDARD 11)

link_directories(/usr/lib/x86_64-linux-gnu/)

include_directories(/usr/include/SDL2)

add_executable(game2048
        headers/app.h
        source/app/app_init.c
        headers/globals.h
        source/globals.c
        source/app/app_loadmedia.c
        source/app/app_cleanup.c
        source/app/app_execute.c
        source/app/app_input.c
        source/app/app_loop.c
        source/app/app_render.c
        headers/logic.h
        source/logic.c)

target_link_libraries(game2048 SDL2 SDL2_ttf)