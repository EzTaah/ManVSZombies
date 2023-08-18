#pragma once
#include <raylib.hpp>


class StaticEntity
{
public:
    StaticEntity(const Vector2& position, const Vector2& size);

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetPositionInViewSpace() const;
    Rectangle GetRectangle() const;

    // === Setters ===
    void SetPosition(const Vector2& newPosition);
    void SetPositionInViewSpace(const Vector2& newPositionInViewSpace);

    // === Rendering ===
    virtual void Render() const = 0;

protected:
    Vector2 _position;
    Vector2 _positionInViewSpace;
    Vector2 _size;
};