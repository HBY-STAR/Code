#include "gtest/gtest.h"
#include "BinaryTree.cpp"

class BinaryTreeTest : public ::testing::Test {

};

TEST_F(BinaryTreeTest, case01PreInPostNormal) {
    auto *node1 = new BinaryNode<int>(1);
    auto *node3 = new BinaryNode<int>(3);
    auto *node2 = new BinaryNode<int>(2, node1, node3);
    auto *node5 = new BinaryNode<int>(5);
    auto *node7 = new BinaryNode<int>(7);
    auto *node6 = new BinaryNode<int>(6, node5, node7);
    auto *node4 = new BinaryNode<int>(4, node2, node6);

    BinaryTree<int> binaryTree = BinaryTree<int>(node4);
    ASSERT_EQ((vector<int>{4, 2, 1, 3, 6, 5, 7}), binaryTree.preOrder());
    ASSERT_EQ((vector<int>{1, 2, 3, 4, 5, 6, 7}), binaryTree.inOrder());
    ASSERT_EQ((vector<int>{1, 3, 2, 5, 7, 6, 4}), binaryTree.postOrder());
}

TEST_F(BinaryTreeTest, case02LevelNormal) {
    auto *node1 = new BinaryNode<int>(1);
    auto *node3 = new BinaryNode<int>(3);
    auto *node2 = new BinaryNode<int>(2, node1, node3);
    auto *node5 = new BinaryNode<int>(5);
    auto *node7 = new BinaryNode<int>(7);
    auto *node6 = new BinaryNode<int>(6, node5, node7);
    auto *node4 = new BinaryNode<int>(4, node2, node6);

    BinaryTree<int> binaryTree = BinaryTree<int>(node4);
    ASSERT_EQ((vector<int>{4, 2, 6, 1, 3, 5, 7}), binaryTree.levelOrder());
}
