//
// Created by yixin on 2022/9/25.
//
#include "gtest/gtest.h"
#include "MyQueue.cpp"

class MyQueueTest : public ::testing::Test {

};

/** 以下测试用例仅供参考，实际测试不止这一个 */
TEST_F(MyQueueTest, case01Normal) {
    MyQueue<int> queue = MyQueue<int>(3);
    queue.enqueue(3);
    queue.enqueue(2);
    ASSERT_TRUE(queue.enqueue(1));
    ASSERT_EQ(3, queue.getSize());
    ASSERT_EQ(3, queue.dequeue());
    ASSERT_EQ(2, queue.dequeue());
    ASSERT_EQ(1, queue.dequeue());
    ASSERT_EQ(0, queue.getSize());
}