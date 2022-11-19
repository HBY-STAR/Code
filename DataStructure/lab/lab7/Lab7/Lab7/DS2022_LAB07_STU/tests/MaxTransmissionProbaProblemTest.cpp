#include "gtest/gtest.h"
#include "MaxTransmissionProbaProlem.h"
#include <cmath>

class MaxTransmissionProbaProblemTest : public ::testing::Test
{
};

bool almost_equal(double a, double b)
{
    return abs(a - b) < 1e-5;
}

TEST_F(MaxTransmissionProbaProblemTest, maxProbaText)
{
    double actual_proba = 0.3;
    double expected_proba = maxTransmissionProba(3,
                                                 std::vector<std::vector<int>>{{0, 1},
                                                                               {1, 2},
                                                                               {0, 2}},
                                                 std::vector{0.5, 0.6, 0.25},
                                                 0,
                                                 2);
    ASSERT_TRUE(almost_equal(actual_proba, expected_proba));
}
/*
TEST_F(MaxTransmissionProbaProblemTest, maxProbaText1) {
    double actual_proba = 1;
    double expected_proba = maxTransmissionProba(1,
                                                 std::vector<std::vector<int>>{{0,0}},
                                                 std::vector{1.0},
                                                 0,
                                                 0
    );
    ASSERT_TRUE(almost_equal(actual_proba, expected_proba));
}

TEST_F(MaxTransmissionProbaProblemTest, maxProbaText2) {
    double actual_proba = 0.648;
    double expected_proba = maxTransmissionProba(5,
                                                 std::vector<std::vector<int>>{{0,1},
                                                                               {0,2},
                                                                               {0,3},
                                                                               {0,4},
                                                                               {1,2},
                                                                               {2,3},
                                                                               {4,3}},
                                                 std::vector{0.8,0.7,0.5,0.9,0.9,0.9,0.6},
                                                 0,
                                                 3
    );
    ASSERT_TRUE(almost_equal(actual_proba, expected_proba));
}
*/