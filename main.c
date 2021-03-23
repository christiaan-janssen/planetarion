#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Planetarion");

    Vector2 mousePos = { -100.0f, -100.0f };
    Vector2 gridPos = {0, 0};
    Vector2 rectPos = {-100.0, -100.0};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            gridPos.x = mousePos.x / 32;
            gridPos.y = mousePos.y / 32;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            for (int i = 0; i < screenWidth / 32; i++) {
                DrawLine(32*i, 0, 32*i, 450, LIGHTGRAY);
            }

            for (int i = 0; i < screenHeight / 32; i++) {
                DrawLine(0, 32*i,  800, 32*i, LIGHTGRAY);
            }

            ClearBackground(RAYWHITE);

            DrawText(TextFormat("x %i, y %i", (int)gridPos.x, (int)gridPos.y), 10, 10, 20, DARKGRAY);
            DrawRectangle((int)gridPos.x*32, (int)gridPos.y*32, 32, 32, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
