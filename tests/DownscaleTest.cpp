#include <gtest/gtest.h>

#include "../cpp/src/Grid.h"
#include "../cpp/src/LinearGridInterpolation.h"
#include "../cpp/src/ClosestNeighborGridInterpolation.h"

TEST(DownScaleTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1, 8};

    std::vector<float> new_grid_func = grid1.downscale(2, new ClosestNeighborGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};

    EXPECT_EQ(new_grid_func, assert_grid_func);
}

TEST(DownScaleTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1, 8};

    std::vector<float> new_grid_func = grid1.downscale(2, new LinearGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(new_grid_func, assert_grid_func);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}