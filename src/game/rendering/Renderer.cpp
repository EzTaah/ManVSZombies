#include "Renderer.hpp"


Renderer::Renderer() 
    : _camera()
{}

Renderer::Renderer(const ut::Rectanglef& playerRectangle)
    : _camera()
{
    // Set the camera position
    ut::Vector2f cameraPosition;
    cameraPosition.x = playerRectangle.x + (playerRectangle.width / 2) - 1366/2;    // TODO : GetScreenWidth()
    cameraPosition.y = playerRectangle.y + (playerRectangle.height / 2) - 764/2;

    _camera.SetPosition(cameraPosition);
}


// === Update positionInViewSpace for all entities ===
void Renderer::UpdatePositionInViewSpaceEntities(Grid& grid, Player& player, BulletManager& bulletManager, ZombieManager& zombieManager, WallManager& wallManager)
{
    // Grid
    ut::Vector2f gridPositionInViewSpace;
    gridPositionInViewSpace.x = 0.0f - _camera.GetPosition().x;  // 0.0f is the grid position
    gridPositionInViewSpace.y = 0.0f - _camera.GetPosition().y;
    grid.SetPositionInViewSpace(gridPositionInViewSpace);

    // Player 
    ut::Vector2f playerPositionInViewSpace;
    playerPositionInViewSpace.x = player.GetPosition().x - _camera.GetPosition().x;
    playerPositionInViewSpace.y = player.GetPosition().y - _camera.GetPosition().y;
    player.SetPositionInViewSpace(playerPositionInViewSpace);

    // Bullets
    bulletManager.SetPositionInViewSpaceBullets(_camera.GetPosition());

    // Zombies
    zombieManager.SetPositionInViewSpaceZombies(_camera.GetPosition());

    // Walls
    wallManager.SetPositionInViewSpaceWalls(_camera.GetPosition());
}


// === Update Camera ===
void Renderer::UpdateCameraPosition(const ut::Rectanglef& playerRectangle)
{
    // Set the camera position
    ut::Vector2f cameraPosition;
    cameraPosition.x = playerRectangle.x + (playerRectangle.width / 2) - 1366/2;
    cameraPosition.y = playerRectangle.y + (playerRectangle.height / 2) - 764/2;
    _camera.SetPosition(cameraPosition);
}


// === Render ===
void Renderer::Render(sf::RenderWindow* windowPtr, std::vector<MovingEntity*>* movingEntitiesArrayPtr, std::vector<Entity *>* staticEntitiesArrayPtr, const Grid& grid)
{
    // Clear background with black
    windowPtr->clear(sf::Color::Black);

    // Render grid
    for(unsigned int i{0} ; i < grid.GetGrid().size() ; ++i)
    {
        for(unsigned int n{0} ; n < grid.GetGrid()[i].size() ; ++n)
        {
            sf::RectangleShape shape;
            // Set size
            shape.setSize({29.0f, 29.0f});
            // Set shape position
            float posX{grid.GetPositionInViewSpace().x + (30.0f * n) + 1};
            float posY{grid.GetPositionInViewSpace().y + (30.0f * i) + 1};
            shape.setPosition(posX, posY);
            // color
            shape.setFillColor(sf::Color::Blue);

            windowPtr->draw(shape);
        }
    }

    // === Render all entities in the game
    for(Entity* staticEntityPtr : *staticEntitiesArrayPtr)
        staticEntityPtr->Render(windowPtr);

    for(MovingEntity* movingEntityPtr : *movingEntitiesArrayPtr)
        movingEntityPtr->Render(windowPtr);

    // End the current frame and display its contents on screen
    windowPtr->display();
}