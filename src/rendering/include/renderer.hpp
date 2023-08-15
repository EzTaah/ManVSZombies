#pragma once 
#include "grid_manager.hpp"
#include "player.hpp"
#include "zombie.hpp"
#include "bullet.hpp"
#include "wall.hpp"
#include "game_camera.hpp"
#include <raylib.hpp>
#include <vector>


class Renderer
{
public:
    Renderer();
    Renderer(const Rectangle& playerRectangle_);

    void UpdateCamera(const Rectangle& playerRectangle_);

    void UpdateAllEntitiesPositionInViewSpace(GridManager& gridManager_, Player& player_,std::vector<Bullet>& bullets_, std::vector<Zombie>&zombies_, std::vector<Wall>& walls_);

    void Draw(GridManager& gridManager_, const Player& player_, const std::vector<Bullet>& bullets_, const std::vector<Zombie>&zombies_, const std::vector<Wall>& walls_);

private:
    GameCamera gameCamera;
};