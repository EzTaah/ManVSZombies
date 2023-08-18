#include "player.hpp"


Player::Player(const Vector2& position)
    : MovingEntity(position, {400.0f, 400.0f}, {30.0f, 30.0f})    // {400.0f, 400.0f} is the speed of the player, {30.0f, 30.0f} is the size of the player
{}


// === Rendering ===
void Player::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, GREEN);
}