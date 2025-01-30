#pragma once

#include <vector>

class IGridInterpolation {
    public:
    virtual void interpolate(const std::vector<float> &old_grid, double old_step, std::vector<float> &new_grid, double new_step) = 0;
};