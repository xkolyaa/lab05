#include <gtest/gtest.h>
#include "solver.h"

TEST(Solver, Addition) {
    EXPECT_EQ(solve(2, 2), 4);
    EXPECT_EQ(solve(-1, 1), 0);
}

TEST(Solver, Zero) {
    EXPECT_EQ(solve(0, 0), 0);
}
