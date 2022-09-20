#include "gtest/gtest.h"
#include "Node.h"
#include "LinkedListVectorConverter.h"
#include "Problem1.h"
#include <vector>

class Problem1Test : public ::testing::Test {
protected:
    LinkedListVectorConverter converter;
    Problem1 problem2;
};

TEST_F(Problem1Test, evenCase) {
    std::vector<std::vector<int>> ins = {{1, 2},
                                         {1, 2, 3, 4},
                                         {1, 2, 3, 4, 5, 6},
                                         {1, 2, 3, 4, 5, 6, 7, 8}};
    std::vector<std::vector<int>> expected_outs = {{1, 2},
                                                   {1, 4, 2, 3},
                                                   {1, 6, 2, 5, 3, 4},
                                                   {1, 8, 2, 7, 3, 6, 4, 5}};
    for (size_t i = 0; i < ins.size(); i++) {
        auto in = ins[i];
        auto expected_out = expected_outs[i];
        Node *head = this->converter.toLinkedList(in);
        head = this->problem2.rearrangeNodes(head);
        std::vector<int> actual_out = this->converter.toVector(head);
        ASSERT_EQ(expected_out, actual_out);
    }

}

TEST_F(Problem1Test, oddCase) {
    std::vector<std::vector<int>> ins = {{1},
                                         {1, 2, 3},
                                         {1, 2, 3, 4, 5},
                                         {1, 2, 3, 4, 5, 6, 7},
                                         {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<std::vector<int>> expected_outs = {{1},
                                                   {1, 3, 2},
                                                   {1, 5, 2, 4, 3},
                                                   {1, 7, 2, 6, 3, 5, 4},
                                                   {1, 9, 2, 8, 3, 7, 4, 6, 5}};
    for (size_t i = 0; i < ins.size(); i++) {
        auto in = ins[i];
        auto expected_out = expected_outs[i];
        Node *head = this->converter.toLinkedList(in);
        head = this->problem2.rearrangeNodes(head);
        std::vector<int> actual_out = this->converter.toVector(head);
        ASSERT_EQ(expected_out, actual_out);
    }

}
