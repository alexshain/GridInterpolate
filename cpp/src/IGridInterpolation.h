#pragma once

#include <vector>

using namespace std;

class IGridInterpolation {
    public:
    virtual void interpolate(const vector<float> &old_grid, double old_step, vector<float> &new_grid, double new_step) = 0;
};