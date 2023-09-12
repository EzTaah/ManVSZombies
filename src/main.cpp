#include "Game.hpp"
#include <raylib.hpp> 


int main()
{
    InitWindow(1366, 768, "2Dshooter");
    SetWindowState(FLAG_VSYNC_HINT);
    Game game = Game();

    while (!WindowShouldClose())
    {
        game.Update();
        game.Render();
    }
    CloseWindow();
    return 0;
}