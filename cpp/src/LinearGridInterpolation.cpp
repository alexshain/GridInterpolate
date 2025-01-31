#include "LinearGridInterpolation.h"

void LinearGridInterpolation::interpolate(const Grid &old_grid, Grid &new_grid) {
    std::vector<float> new_grid_function(new_grid.getGridFunction().size());
    new_grid_function[0] = old_grid.getGridFunction()[0];
    double old_area_size = (old_grid.getGridFunction().size() - 1) * old_grid.getStep();
    double lust_value_in_old_grid = old_grid.getGridFunction()[old_grid.getGridFunction().size() - 1];
    for(size_t i = 1; i < new_grid.getGridFunction().size(); i++) {
        if(i * new_grid.getStep() > old_area_size) {
            new_grid_function[i] = lust_value_in_old_grid;
        }
        for(size_t j = 1; j < old_grid.getGridFunction().size(); j++) {
            double next_node_distance = abs(j * old_grid.getStep() - i * new_grid.getStep());
            double previos_node_distance = abs((j-1) * old_grid.getStep() - i * new_grid.getStep());
            if(abs(next_node_distance) < 1e-10) {
                new_grid_function[i] = old_grid.getGridFunction()[j];
            } else if(j * old_grid.getStep() > i * new_grid.getStep() && (j-1) * old_grid.getStep() < i * new_grid.getStep()) {
                new_grid_function[i] = ((old_grid.getStep() - previos_node_distance) / old_grid.getStep()) * old_grid.getGridFunction()[j-1] +
                                    ((old_grid.getStep() - next_node_distance)/old_grid.getStep()) * old_grid.getGridFunction()[j];
            }
        }
    }
    new_grid.resetGrid(new_grid_function, new_grid.getStep());
}