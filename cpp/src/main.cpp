#include "Grid.h"
#include "LinearGridInterpolation.h"
#include "ClosestNeighborGridInterpolation.h"

int main() {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func = grid1.downscale(2, new ClosestNeighborGridInterpolation).getGridFunction();

    for(size_t i = 0; i < new_grid_func.size(); ++i) {
        std::cout << new_grid_func[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}