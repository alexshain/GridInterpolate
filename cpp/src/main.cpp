#include "Grid.h"
#include "LinearGridInterpolation.h"
#include "ClosestNeighborGridInterpolation.h"

int main() {
    Grid grid1 = Grid{"grid1.raw", 0.2, 49};
    Grid grid2 = Grid{"grid2.raw", 0.35, 749};

    std::vector<Grid> grids = {grid1, grid2};

    ClosestNeighborGridInterpolation closestInterpolation = ClosestNeighborGridInterpolation{};
    LinearGridInterpolation linearInterpolation = LinearGridInterpolation{};
    std::vector<IGridInterpolation*> interpolators = {&closestInterpolation, &linearInterpolation};

    for(size_t i = 0; i < interpolators.size(); i++) {
        for(size_t j = 0; j < grids.size(); j++) {
            std::string filename = "grid" + std::to_string(j+1) + "_downscale_" + std::to_string(i) + ".raw";
            grids[j].downscale(2, interpolators[i]).writeGridFunctionInFile(filename);
        }
    }

    
    for(size_t i = 0; i < interpolators.size(); i++) {
        Grid grid = {0.18, 149, grid1, interpolators[i]};
        std::string filename = "grid1_interpolate_" + std::to_string(i) + ".raw";
        grid.writeGridFunctionInFile(filename);
    }    

    return 0;
}