#include "renderer.hpp"
#include <raylib.hpp>


Renderer::Renderer() {}


Renderer::Renderer(const Rectangle& playerRectangle_)
    : gameCamera()
{
    // Set the camera positio
    Vector2 cameraPosition;
    cameraPosition.x = playerRectangle_.x + (playerRectangle_.width / 2) - GetScreenWidth()/2;
    cameraPosition.y = playerRectangle_.y + (playerRectangle_.height / 2) - GetScreenHeight()/2;

    gameCamera.SetPosition(cameraPosition);
}


void Renderer::UpdateCamera(const Rectangle& playerRectangle_)
{
    // Set the camera positio
    Vector2 cameraPosition;
    cameraPosition.x = playerRectangle_.x + (playerRectangle_.width / 2) - GetScreenWidth()/2;
    cameraPosition.y = playerRectangle_.y + (playerRectangle_.height / 2) - GetScreenHeight()/2;

    gameCamera.SetPosition(cameraPosition);
}



void Renderer::UpdateAllEntitiesPositionInViewSpace(GridManager& gridManager_, Player& player_, std::vector<Bullet>& bullets_, std::vector<Zombie>& zombies_,std::vector<Wall>& walls_)
{
    // Grid
    Vector2 gridPositionInViewSpace;
    gridPositionInViewSpace.x = 0.0f - gameCamera.GetPosition().x;  // 0.0f is the grid position
    gridPositionInViewSpace.y = 0.0f - gameCamera.GetPosition().y;
    gridManager_.SetPositionInViewSpace(gridPositionInViewSpace);


    // Player 
    Vector2 playerPositionInViewSpace;
    playerPositionInViewSpace.x = player_.GetPosition().x - gameCamera.GetPosition().x;
    playerPositionInViewSpace.y = player_.GetPosition().y - gameCamera.GetPosition().y;
    player_.SetPositionInViewSpace(playerPositionInViewSpace);

    // Bullets
    for (Bullet& bullet : bullets_)
    {
        Vector2 bulletPositionInViewSpace;
        bulletPositionInViewSpace.x = bullet.GetPosition().x - gameCamera.GetPosition().x;
        bulletPositionInViewSpace.y = bullet.GetPosition().y - gameCamera.GetPosition().y;
        bullet.SetPositionInViewSpace(bulletPositionInViewSpace);
    }

    // Zombies
    for (Zombie& zombie : zombies_)
    {
        Vector2 zombiePositionInViewSpace;
        zombiePositionInViewSpace.x = zombie.GetPosition().x - gameCamera.GetPosition().x;
        zombiePositionInViewSpace.y = zombie.GetPosition().y - gameCamera.GetPosition().y;
        zombie.SetPositionInViewSpace(zombiePositionInViewSpace);
    }


    // Walls
    for (Wall& wall : walls_)
    {
        Vector2 wallPositionInViewSpace;
        wallPositionInViewSpace.x = wall.GetPosition().x - gameCamera.GetPosition().x;
        wallPositionInViewSpace.y = wall.GetPosition().y - gameCamera.GetPosition().y;
        wall.SetPositionInViewSpace(wallPositionInViewSpace);
    }
}


void Renderer::Draw(GridManager& gridManager_, const Player& player_, const std::vector<Bullet>& bullets_, const std::vector<Zombie>&zombies_, const std::vector<Wall>& walls_)
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw grid
    for(unsigned int i{0} ; i < gridManager_.GetGrid().size() ; ++i)
    {
        for(unsigned int n{0} ; n < gridManager_.GetGrid()[i].size() ; ++n)
        {
            DrawRectangle(gridManager_.GetPositionInViewSpace().x + (30.0f * n) + 1, gridManager_.GetPositionInViewSpace().y + (30.0f * i) + 1, 29.0f, 29.0f, DARKGRAY);
        }
    }

    // Draw player
    player_.Draw();

    // Draw bullets
    for (const Bullet& elt : bullets_)
        elt.Draw();

    // Draw zombies
    for (const Zombie& elt : zombies_)
        elt.Draw();

    // Draw walls
    for (const Wall& elt : walls_)
        elt.Draw();

    EndDrawing();
}