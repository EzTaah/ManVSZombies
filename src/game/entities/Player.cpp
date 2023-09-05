#include "Player.hpp"


Player::Player(const Vector2& position)
    : MovingEntity(position, {400.0f, 400.0f}, {30.0f, 30.0f})    // {400.0f, 400.0f} is the speed of the player, {30.0f, 30.0f} is the size of the player
{}


// === Accessors ===
Rectangle Player::GetRectangleInViewSpace() const {
    return {_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y};
}


// === Logic ===
void Player::CalculateNextMove() {};


// === Rendering ===
void Player::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, GREEN);
}