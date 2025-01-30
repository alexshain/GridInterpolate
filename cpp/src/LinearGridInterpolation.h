#pragma once

#include "IGridInterpolation.h"

class LinearGridInterpolation: public IGridInterpolation {
    public:
    void interpolate(const std::vector<float> &old_grid, double old_step, std::vector<float> &new_grid, double new_step) override;
};