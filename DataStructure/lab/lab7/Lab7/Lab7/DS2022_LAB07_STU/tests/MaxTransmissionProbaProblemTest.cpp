#include "gtest/gtest.h"
#include "MaxTransmissionProbaProlem.h"
#include <cmath>

class MaxTransmissionProbaProblemTest : public ::testing::Test {


};

bool almost_equal(double a, double b) {
    return abs(a - b) < 1e-5;
}

TEST_F(MaxTransmissionProbaProblemTest, maxProbaText) {
    double actual_proba = 0.3;
    double expected_proba = maxTransmissionProba(3,
                                                 std::vector<std::vector<int>>{{0, 1},
                                                                               {1, 2},
                                                                               {0, 2}},
                                                 std::vector{0.5, 0.6, 0.25},
                                                 0,
                                                 2
    );
    ASSERT_TRUE(almost_equal(actual_proba, expected_proba));
}