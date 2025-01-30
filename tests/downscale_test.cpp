#include <gtest/gtest.h>

#include "../cpp/src/Grid.h"
#include "../cpp/src/LinearGridInterpolation.h"
#include "../cpp/src/ClosestNeighborGridInterpolation.h"

TEST(DownScaleTest, ClosestNeighborGridInterpolation) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(DownScaleTest, LinearGridInterpolation) {
    EXPECT_EQ(multiply(2, 3), 6);
    EXPECT_EQ(multiply(-1, 1), -1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}