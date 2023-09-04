#pragma once
#include "utils.hpp"
#include <vector>


class Grid
{
public:
    Grid();

    // === Accessors ===
    std::vector<std::vector<int>> GetGrid() const;
    ut::Vector2f GetGridDimensions() const;
    ut::Vector2f GetNumberOfTiles() const;
    ut::Vector2f GetPositionInViewSpace() const;

    // === Mutators ===
    void SetPositionInViewSpace(const ut::Vector2f& newPositionInViewSpace);

private:
    std::vector<std::vector<int>> _grid;
    ut::Vector2f _gridDimensions;
    ut::Vector2f _positionInViewSpace;
};