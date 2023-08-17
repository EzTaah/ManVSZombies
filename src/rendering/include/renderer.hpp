#pragma once 
#include "grid_manager.hpp"
#include "player.hpp"
#include "zombie_manager.hpp"
#include "bullet_manager.hpp"
#include "wall_manager.hpp"
#include "game_camera.hpp"
#include <raylib.hpp>
#include <vector>


class Renderer
{
public:
    Renderer();
    Renderer(const Rectangle& playerRectangle);

    // === Update positionInViewSpace for all entities ===
    void UpdatePositionInViewSpaceEntities(GridManager& gridManager, Player& player, BulletManager& bulletManager, ZombieManager& zombieManager, WallManager& wallManager);

    // === Update Camera ===
    void UpdateCameraPosition(const Rectangle& playerRectangle);

    // === Render ===
    void Render(const GridManager& gridManager, const Player& player, const BulletManager& bulletManager, const ZombieManager& zombieManager, const WallManager& wallManager);

private:
    GameCamera _gameCamera;
};