#include "ClosestNeighborGridInterpolation.h"

void ClosestNeighborGridInterpolation::interpolate(const vector<float> &old_grid, double old_step, 
    vector<float> &new_grid, double new_step) {
    new_grid[0] = old_grid[0];
    double old_area_size = (old_grid.size()-1) * old_step;
    double lust_value_in_old_grid = old_grid[old_grid.size()-1];
    for(size_t i = 1; i < new_grid.size(); i++) {
        if(i*new_step > old_area_size) {
            new_grid[i] = lust_value_in_old_grid;
        }
        for(size_t j = 1; j < old_grid.size(); j++) {
            double next_node_distance = j*old_step - i*new_step;
            double previos_node_distance = abs((j-1)*old_step-i*new_step);
            if(abs(next_node_distance) < 1e-9) {
                new_grid[i] = old_grid[j];
            } else if(next_node_distance <= previos_node_distance && (j*old_step > i*new_step && (j-1)*old_step < i*new_step)) {
                new_grid[i] = old_grid[j];
            } else if(next_node_distance > previos_node_distance && (j*old_step > i*new_step && (j-1)*old_step < i*new_step)){
                new_grid[i] = old_grid[j-1];
            }
        }
    }
}