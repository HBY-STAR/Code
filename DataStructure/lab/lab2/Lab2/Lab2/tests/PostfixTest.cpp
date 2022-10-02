//
// Created by yixin on 2022/9/25.
//
#include "gtest/gtest.h"
#include "Postfix.cpp"

class PostfixTest : public ::testing::Test
{
};

/** 以下测试用例仅供参考，实际测试不止这一个 */
TEST_F(PostfixTest, case01Normal)
{
    ASSERT_EQ("ab+cd*-", postfix("a+b-c*d"));
}

// add tests
/*
TEST_F(PostfixTest, case01Normal)
{
    ASSERT_EQ("abc*d/e*+a-fb/+", postfix("a+b*c/d*e-a+f/b"));
    ASSERT_EQ("ab+c-d+e-f+", postfix("a+b-c+d-e+f"));
}
*/