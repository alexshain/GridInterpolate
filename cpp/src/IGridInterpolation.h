#pragma once

#include <vector>

class Grid;

class IGridInterpolation {
    public:
    virtual void interpolate(const Grid &old_grid, Grid &new_grid) = 0;
    //virtual void interpolate(const std::vector<float> &old_grid, double old_step, std::vector<float> &new_grid, double new_step) = 0;
};