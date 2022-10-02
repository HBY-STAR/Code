//
// Created by yixin on 2022/9/25.
//
#include "gtest/gtest.h"
#include "MyStack.cpp"

class MyStackTest : public ::testing::Test
{
};

/** 以下测试用例仅供参考，实际测试不止这一个 */
TEST_F(MyStackTest, case01Normal)
{
    MyStack<int> stack = MyStack<int>(3);
    stack.push(new Node<int>(1));
    stack.push(new Node<int>(2));
    ASSERT_TRUE(stack.push(new Node<int>(3)));
    ASSERT_EQ(3, stack.getSize());
    ASSERT_EQ(3, stack.pop()->val);
    ASSERT_EQ(2, stack.pop()->val);
    ASSERT_EQ(1, stack.pop()->val);
    ASSERT_EQ(0, stack.getSize());
}

// add tests
/*
TEST_F(MyStackTest, case02Normal)
{
    MyStack<int> stack = MyStack<int>(2);
    stack.push(new Node<int>(1));
    ASSERT_TRUE(stack.push(new Node<int>(3)));
    ASSERT_EQ(2, stack.getSize());
    ASSERT_EQ(3, stack.pop()->val);
    ASSERT_EQ(1, stack.pop()->val);
    ASSERT_EQ(0, stack.getSize());
}

TEST_F(MyStackTest, case03Normal)
{
    MyStack<int> stack = MyStack<int>(1);
    ASSERT_TRUE(stack.push(new Node<int>(3)));
    ASSERT_EQ(1, stack.getSize());
    ASSERT_EQ(3, stack.pop()->val);
    ASSERT_EQ(0, stack.getSize());
}
*/
