#pragma once
#include <raylib.hpp>
#include <vector>


class GridManager
{
public:
    GridManager();
    
    void InitGrid();
    std::vector<std::vector<int>> GetGrid();
    Vector2 GetPositionInViewSpace();
    void SetPositionInViewSpace(Vector2 position_);
    Vector2 GetGridDimensions();

private:
    std::vector<std::vector<int>> grid;
    Vector2 gridDimensions;
    Vector2 positionInViewSpace;;
};