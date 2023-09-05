#pragma once
#include <raylib.hpp>
#include <vector>


class Grid
{
public:
    Grid();

    // === Accessors ===
    std::vector<std::vector<int>> GetGrid() const;
    Vector2 GetGridDimensions() const;
    Vector2 GetNumberOfTiles() const;
    Vector2 GetPositionInViewSpace() const;

    // === Mutators ===
    void SetPositionInViewSpace(const Vector2& newPositionInViewSpace);

private:
    std::vector<std::vector<int>> _grid;
    Vector2 _gridDimensions;
    Vector2 _positionInViewSpace;
};