#include <fstream>

#include "Grid.h"

Grid::Grid(std::filesystem::path path_to_grid_function, double step, size_t steps_number) :
    step_(step),
    steps_number_(steps_number),
    grid_function_(steps_number + 1) {
        readGridFunctionFromFile(path_to_grid_function);
    }

void Grid::readGridFunctionFromFile(std::filesystem::path path) {
    std::ifstream fin(path, std::ios_base::binary);
    if (!fin.is_open()) {
        throw std::runtime_error("Error: File " + path.string() + " does not exist or cannot be opened.");
    }
    fin.read((char*)grid_function_.data(), sizeof(float)*grid_function_.size());
    fin.close();
}

Grid::Grid(std::vector<float> grid_fuction, double step) :
    grid_function_(grid_fuction),
    step_(step),
    steps_number_(grid_fuction.size() - 1) {}

Grid::Grid(double step, size_t steps_number, Grid old_grid, IGridInterpolation *grid_interpolation) :
    step_(step),
    steps_number_(steps_number),
    grid_function_(steps_number + 1) {
        grid_interpolation->interpolate(old_grid, *this);
    }

Grid Grid::upscale(size_t k, IGridInterpolation *grid_interpolation) {
    double new_step = step_ * k; 
    size_t new_steps_number = steps_number_ / k;
    std::vector<float> new_grid_function(new_steps_number + 1, 0);
    Grid new_grid = Grid{new_grid_function, new_step};
    grid_interpolation->interpolate(*this, new_grid);
    return new_grid;
}

Grid Grid::downscale(size_t k, IGridInterpolation *grid_interpolation) {
    double new_step = step_ / k; 
    size_t new_steps_number = steps_number_ * k;
    std::vector<float> new_grid_function(new_steps_number + 1, 0);
    Grid new_grid = Grid{new_grid_function, new_step};
    grid_interpolation->interpolate(*this, new_grid);
    return new_grid;
}

void Grid::writeGridFunctionInFile(std::filesystem::path path) {
    std::ofstream fout(path, std::ios_base::binary);
    fout.write((char*)grid_function_.data(), sizeof(float)*grid_function_.size());
    fout.close();
}

std::vector<float> Grid::getGridFunction() const {
    return grid_function_;
}

double Grid::getStep() const {
    return step_;
}

size_t Grid::getStepsNumber() const {
    return steps_number_;
}

void Grid::resetGrid(const std::vector<float> &grid_function, double step) {
    grid_function_ = grid_function;
    steps_number_ = grid_function.size() - 1;
    step_ = step;
}