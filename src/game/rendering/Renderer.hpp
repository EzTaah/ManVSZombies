#pragma once 
#include "Grid.hpp"
#include "Player.hpp"
#include "ZombieManager.hpp"
#include "BulletManager.hpp"
#include "WallManager.hpp"
#include "GameCamera.hpp"
#include <raylib.hpp>
#include <vector>


class Renderer
{
public:
    Renderer();
    Renderer(const Rectangle& playerRectangle);

    // === Update positionInViewSpace for all entities ===
    void UpdatePositionInViewSpaceEntities(Grid& grid, Player& player, BulletManager& bulletManager, ZombieManager& zombieManager, WallManager& wallManager);

    // === Update Camera ===
    void UpdateCameraPosition(const Rectangle& playerRectangle);

    // === Render ===
    void Render(const Grid& grid, const Player& player, const BulletManager& bulletManager, const ZombieManager& zombieManager, const WallManager& wallManager);

private:
    GameCamera _gameCamera;
};