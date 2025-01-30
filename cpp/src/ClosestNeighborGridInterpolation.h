#pragma once

#include "IGridInterpolation.h"

class ClosestNeighborGridInterpolation: public IGridInterpolation {
    public:
    void interpolate(const vector<float> &old_grid, double old_step, vector<float> &new_grid, double new_step) override;
    private:
    
};