#include "game.hpp"
#include <raylib.hpp>

int main()
{
    InitWindow(1366, 768, "lckp");
    SetWindowState(FLAG_VSYNC_HINT);

    Game game = Game();

    while (!WindowShouldClose())
    {
        game.Update();

        // Drawing
        BeginDrawing();
        ClearBackground(BROWN);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}