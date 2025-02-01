#include <gtest/gtest.h>

#include "../cpp/src/Grid.h"
#include "../cpp/src/LinearGridInterpolation.h"
#include "../cpp/src/ClosestNeighborGridInterpolation.h"

TEST(DownscaleTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1};

    ClosestNeighborGridInterpolation c = ClosestNeighborGridInterpolation{};
    std::vector<float> new_grid_func = grid1.downscale(2, &c).getGridFunction();
    std::vector<float> assert_grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_NEAR(new_grid_func, assert_grid_func, 1e-6);
}

TEST(DownscaleTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func = grid1.downscale(2, new LinearGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_NEAR(new_grid_func, assert_grid_func, 1e-6);
}

TEST(UpscaleTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func = grid1.upscale(2, new ClosestNeighborGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 3, 5, 7, 9, 11, 13};

    EXPECT_NEAR(new_grid_func, assert_grid_func, 1e-6);
}

TEST(UpscaleTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func = grid1.upscale(3, new LinearGridInterpolation).getGridFunction();
    std::vector<float> assert_grid_func{1, 4, 7, 10, 13};

    EXPECT_NEAR(new_grid_func, assert_grid_func, 1e-6);
}

TEST(InterpolateProlongateTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func(20);

    LinearGridInterpolation linearInterpolation = LinearGridInterpolation{};

    Grid new_grid = Grid{new_grid_func, 0.6};
    linearInterpolation.interpolate(grid1, new_grid);
    std::vector<float> assert_grid_func{1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 10, 10, 10, 10, 10};

    EXPECT_NEAR(new_grid.getGridFunction(), assert_grid_func, 1e-6);
}

TEST(InterpolateProlongateTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func(20);

    ClosestNeighborGridInterpolation closestInterpolation = ClosestNeighborGridInterpolation{};

    Grid new_grid = Grid{new_grid_func, 0.6};
    closestInterpolation.interpolate(grid1, new_grid);
    std::vector<float> assert_grid_func{1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 10, 10, 10, 10, 10};

    EXPECT_NEAR(new_grid.getGridFunction(), assert_grid_func, 1e-6);
}

TEST(InterpolateCutTest, LinearGridInterpolation) {
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func(5);

    LinearGridInterpolation linearInterpolation = LinearGridInterpolation{};

    Grid new_grid = Grid{new_grid_func, 1.2};
    linearInterpolation.interpolate(grid1, new_grid);
    std::vector<float> assert_grid_func{1, 3, 4, 5, 6};

    EXPECT_NEAR(new_grid.getGridFunction(), assert_grid_func, 1e-6);
}

TEST(InterpolateCutTest, ClosestNeighborGridInterpolation) {
    std::vector<float> grid_func{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Grid grid1 = Grid{grid_func, 1};

    std::vector<float> new_grid_func(5);

    ClosestNeighborGridInterpolation closestInterpolation = ClosestNeighborGridInterpolation{};

    Grid new_grid = Grid{new_grid_func, 1.2};
    closestInterpolation.interpolate(grid1, new_grid);
    std::vector<float> assert_grid_func{1, 3, 4, 5, 6};

    EXPECT_NEAR(new_grid.getGridFunction(), assert_grid_func, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}