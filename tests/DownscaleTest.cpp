#include <gtest/gtest.h>

#include "../cpp/src/Grid.h"
#include "../cpp/src/LinearGridInterpolation.h"
#include "../cpp/src/ClosestNeighborGridInterpolation.h"

TEST(DownScaleTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1, 8};

    std::vector<float> new_grid_func = grid1.downscale(2, new ClosestNeighborGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(new_grid_func, assert_grid_func);
}

TEST(DownScaleTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1, 8};

    std::vector<float> new_grid_func = grid1.downscale(2, new LinearGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_EQ(new_grid_func, assert_grid_func);
}

TEST(InterpolateProlongateTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    std::vector<float> new_grid_func(20);

    LinearGridInterpolation linearInterpolation = LinearGridInterpolation{};

    linearInterpolation.interpolate(grid_func, 1, new_grid_func, 0.6);
    std::vector<float> assert_grid_func{1, 1.6, 2.2, 2.8, 3.4, 4, 4.6, 5.2, 5.8, 6.4, 7, 7.6, 8.2, 8.8, 9.4, 10, 10, 10, 10, 10};

    EXPECT_EQ(new_grid_func, assert_grid_func);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}