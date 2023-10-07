#include <iostream>
#include "raylib.h"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame();

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    const int windowWidth = 615;
    const int windowHeight = 415;

    InitWindow(windowWidth, windowHeight, "Hello, World!");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();

    return 0;
}

void UpdateDrawFrame() {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Hello, World!", 190, 200, 40, DARKGRAY);

    EndDrawing();
}