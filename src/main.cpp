#include "game.hpp"
#include <raylib.hpp> 


int main()
{
    InitWindow(1366, 768, "ManVsZombie");
    SetWindowState(FLAG_VSYNC_HINT);
    Game game = Game();

    while (!WindowShouldClose())
    {
        game.Update();
        game.RenderScene();
    }
    CloseWindow();
    return 0;
}