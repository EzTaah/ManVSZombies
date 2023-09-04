#pragma once 
#include "Grid.hpp"
#include "Player.hpp"
#include "ZombieManager.hpp"
#include "BulletManager.hpp"
#include "WallManager.hpp"
#include "Camera.hpp"
#include <vector>


class Renderer
{
public:
    Renderer();
    Renderer(const ut::Rectanglef& playerRectangle);

    // === Update positionInViewSpace for all entities ===
    void UpdatePositionInViewSpaceEntities(Grid& grid, Player& player, BulletManager& bulletManager, ZombieManager& zombieManager, WallManager& wallManager);

    // === Update Camera ===
    void UpdateCameraPosition(const ut::Rectanglef& playerRectangle);

    // === Render ===
    void Render(sf::RenderWindow* windowPtr, std::vector<MovingEntity*>* movingEntitiesArrayPtr, std::vector<Entity *>* staticEntitiesArrayPtr, const Grid& grid);

private:
    Camera _camera;
};