#include <iostream>
#include "raylib.h"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame();

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
#if defined(PLATFORM_ANDROID)
    const int windowWidth = 415;
    const int windowHeight = 615;
#else
    const int windowWidth = 615;
    const int windowHeight = 415;
#endif

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

const float movement = 5;
Vector2 position {190, 200};

void HandleMovement() {

    bool moveLeft{false};
    bool moveRight{false};
    bool moveUp{false};
    bool moveDown{false};

    // Detect Keyboard
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) moveLeft = true;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) moveRight = true;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) moveUp = true;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) moveDown = true;

#if defined(PLATFORM_ANDROID)
    // Detect Touch
    if (IsGestureDetected(GESTURE_DRAG) && GetGestureDragVector().x < 0) moveLeft = true;
    if (IsGestureDetected(GESTURE_DRAG) && GetGestureDragVector().x > 0) moveRight = true;
    if (IsGestureDetected(GESTURE_DRAG) && GetGestureDragVector().y < 0) moveUp = true;
    if (IsGestureDetected(GESTURE_DRAG) && GetGestureDragVector().y > 0) moveDown = true;
#else
    // Detect Mouse
    if (GetMouseDelta().x < 0) moveLeft = true;
    if (GetMouseDelta().x > 0) moveRight = true;
    if (GetMouseDelta().y < 0) moveUp = true;
    if (GetMouseDelta().y > 0) moveDown = true;
#endif

    // Move
    if (moveLeft) position.x -= movement;
    if (moveRight) position.x += movement;
    if (moveUp) position.y -= movement;
    if (moveDown) position.y += movement;
}

Color GetTextColour() {
    if (IsKeyDown(KEY_SPACE)) return RED;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) return BLUE;
    if (IsGestureDetected(GESTURE_TAP)) return GREEN;
    return DARKGRAY;
}

void UpdateDrawFrame() {

    HandleMovement();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTextEx(GetFontDefault(), "Hello, World!", position, 40, 4, GetTextColour());

    EndDrawing();
}