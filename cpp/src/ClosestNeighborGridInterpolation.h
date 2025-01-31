#pragma once

#include "IGridInterpolation.h"
#include "Grid.h"

class ClosestNeighborGridInterpolation: public IGridInterpolation {
    public:
    void interpolate(const Grid &old_grid, Grid &new_grid) override;
};