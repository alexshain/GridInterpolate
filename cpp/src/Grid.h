#pragma once

#include <iostream>
#include <filesystem>
#include <vector>

#include "IGridInterpolation.h"

class Grid {
    std::vector<float> grid_function_;
    double step_;
    size_t steps_number_;

    public:
    Grid(std::filesystem::path path_to_grid_function, double step, size_t steps_number);
    Grid(std::vector<float> grid_fuction, double step);
    Grid(double step, size_t steps_number, Grid old_grid, IGridInterpolation *grid_interpolation);
    Grid upscale(size_t k, IGridInterpolation *grid_interpolation);
    Grid downscale(size_t k, IGridInterpolation *grid_interpolation);
    void writeGridFunctionInFile(std::filesystem::path path);

    std::vector<float> getGridFunction() const;
    double getStep() const;
    size_t getStepsNumber() const;

    void resetGrid(const std::vector<float> &grid_function, double step);
    
    private:
    void readGridFunctionFromFile(std::filesystem::path path);
};