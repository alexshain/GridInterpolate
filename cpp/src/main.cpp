#include "Grid.h"
#include "LinearGridInterpolation.h"
#include "ClosestNeighborGridInterpolation.h"

int main() {
    //TODO
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func(20);

    LinearGridInterpolation linearInterpolation = LinearGridInterpolation{};

    Grid new_grid = Grid{new_grid_func, 0.6};
    linearInterpolation.interpolate(grid1, new_grid);

    for(int i = 0; i < new_grid.getGridFunction().size(); ++i) {
        std::cout << new_grid.getGridFunction()[i] << " " ;
    }
    std::cout << std::endl;
    return 0;
}