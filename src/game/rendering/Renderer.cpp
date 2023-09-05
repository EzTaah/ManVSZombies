#include "Renderer.hpp"
#include <raylib.hpp>


Renderer::Renderer() 
    : _gameCamera()
{}

Renderer::Renderer(const Rectangle& playerRectangle)
    : _gameCamera()
{
    // Set the camera position
    Vector2 cameraPosition;
    cameraPosition.x = playerRectangle.x + (playerRectangle.width / 2) - GetScreenWidth()/2;
    cameraPosition.y = playerRectangle.y + (playerRectangle.height / 2) - GetScreenHeight()/2;

    _gameCamera.SetPosition(cameraPosition);
}


// === Update positionInViewSpace for all entities ===
void Renderer::UpdatePositionInViewSpaceEntities(Grid& grid, Player& player, BulletManager& bulletManager, ZombieManager& zombieManager, WallManager& wallManager)
{
    // Grid
    Vector2 gridPositionInViewSpace;
    gridPositionInViewSpace.x = 0.0f - _gameCamera.GetPosition().x;  // 0.0f is the grid position
    gridPositionInViewSpace.y = 0.0f - _gameCamera.GetPosition().y;
    grid.SetPositionInViewSpace(gridPositionInViewSpace);

    // Player 
    Vector2 playerPositionInViewSpace;
    playerPositionInViewSpace.x = player.GetPosition().x - _gameCamera.GetPosition().x;
    playerPositionInViewSpace.y = player.GetPosition().y - _gameCamera.GetPosition().y;
    player.SetPositionInViewSpace(playerPositionInViewSpace);

    // Bullets
    bulletManager.SetPositionInViewSpaceBullets(_gameCamera.GetPosition());

    // Zombies
    zombieManager.SetPositionInViewSpaceZombies(_gameCamera.GetPosition());

    // Walls
    wallManager.SetPositionInViewSpaceWalls(_gameCamera.GetPosition());
}


// === Update Camera ===
void Renderer::UpdateCameraPosition(const Rectangle& playerRectangle)
{
    // Set the camera position
    Vector2 cameraPosition;
    cameraPosition.x = playerRectangle.x + (playerRectangle.width / 2) - GetScreenWidth()/2;
    cameraPosition.y = playerRectangle.y + (playerRectangle.height / 2) - GetScreenHeight()/2;
    _gameCamera.SetPosition(cameraPosition);
}


// === Render ===
void Renderer::Render(const Grid& grid, const Player& player, const BulletManager& bulletManager, const ZombieManager& zombieManager, const WallManager& wallManager)
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Render grid
    for(unsigned int i{0} ; i < grid.GetGrid().size() ; ++i)
    {
        for(unsigned int n{0} ; n < grid.GetGrid()[i].size() ; ++n)
        {
            DrawRectangle(grid.GetPositionInViewSpace().x + (30.0f * n) + 1, grid.GetPositionInViewSpace().y + (30.0f * i) + 1, 29.0f, 29.0f, DARKGRAY);
        }
    }

    // Render player
    player.Render();

    // Render bullets
    for (Bullet& bullet : bulletManager.GetBulletsArray())
        bullet.Render();

    // Render zombies
    for (Zombie& zombie : zombieManager.GetZombiesArray())
        zombie.Render();

    // Render walls
    for (Wall& wall : wallManager.GetWallsArray())
        wall.Render();

    EndDrawing();
}