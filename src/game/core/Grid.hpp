#pragma once
#include "utils.hpp"
#include <vector>


class Grid
{
public:
    Grid();

    // === Accessors ===
    std::vector<std::vector<int>> GetGrid() const;
    ut::Vector2fGetGridDimensions() const;
    ut::Vector2fGetNumberOfTiles() const;
    ut::Vector2fGetPositionInViewSpace() const;

    // === Mutators ===
    void SetPositionInViewSpace(const ut::Vector2f& newPositionInViewSpace);

private:
    std::vector<std::vector<int>> _grid;
    ut::Vector2f_gridDimensions;
    ut::Vector2f_positionInViewSpace;
};