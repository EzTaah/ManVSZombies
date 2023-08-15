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

private:
    std::vector<std::vector<int>> grid;
    Vector2 positionInViewSpace;;
};