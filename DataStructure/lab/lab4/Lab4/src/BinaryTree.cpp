#include<vector>
#include<stack>
#include<queue>
#include "BinaryNode.cpp"

using namespace std;

template<typename T> class BinaryTree {
private:
    BinaryNode<T> *root;

    // You may define some helper functions below:



public:
    /**
     * @brief Creates a binary tree with a binary node as its root.
     * */
    explicit BinaryTree(BinaryNode<T> *root) {
        this->root = root;
    }

    /**
     * @brief Preorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> preOrder() {
        // TODO
        return vector<T>();
    }

    /**
     * @brief Inorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> inOrder() {
        // TODO
        return vector<T>();
    }

    /**
     * @brief Postorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> postOrder() {
        // TODO
        return vector<T>();
    }

    /**
     * @brief Level Order traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> levelOrder() {
        // TODO
        return vector<T>();
    }

    /**
     * @brief Inorder traverse, NON-RECURSIVE.
     * @return Traverse result in a vector.
     * */
    vector<T> inOrderNonRecur() {
        // TODO
        return vector<T>();
    }
};
