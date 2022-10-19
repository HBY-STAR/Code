#include <vector>
#include <stack>
#include <queue>
#include "BinaryNode.cpp"

using namespace std;

template <typename T>
class BinaryTree
{
private:
    BinaryNode<T> *root;

    // You may define some helper functions below:

    //进行递归调用的内部方法
    void preOrder(BinaryNode<T> *node, vector<T> &result)
    {
        if (node != nullptr)
        {
            result.push_back(node->getVal());
            preOrder(node->getLeft(), result);
            preOrder(node->getRight(), result);
        }
    }
    void inOrder(BinaryNode<T> *node, vector<T> &result)
    {
        if (node != nullptr)
        {
            inOrder(node->getLeft(), result);
            result.push_back(node->getVal());
            inOrder(node->getRight(), result);
        }
    }
    void postOrder(BinaryNode<T> *node, vector<T> &result)
    {
        if (node != nullptr)
        {
            postOrder(node->getLeft(), result);
            postOrder(node->getRight(), result);
            result.push_back(node->getVal());
        }
    }

public:
    /**
     * @brief Creates a binary tree with a binary node as its root.
     * */
    explicit BinaryTree(BinaryNode<T> *root)
    {
        this->root = root;
    }

    /**
     * @brief Preorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> preOrder()
    {
        vector<T> result;
        preOrder(root, result);
        return result;
    }

    /**
     * @brief Inorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> inOrder()
    {
        vector<T> result;
        inOrder(root, result);
        return result;
    }

    /**
     * @brief Postorder traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> postOrder()
    {
        vector<T> result;
        postOrder(root, result);
        return result;
    }

    /**
     * @brief Level Order traverse, recursive.
     * @return Traverse result in a vector.
     * */
    vector<T> levelOrder()
    {
        vector<T> result;
        queue<BinaryNode<T> *> tempqueue;
        BinaryNode<T> *tempnode;
        tempqueue.push(root);
        while (!tempqueue.empty())
        {
            tempnode = tempqueue.front();
            result.push_back(tempnode->getVal());
            if (tempnode->getLeft() != nullptr)
            {
                tempqueue.push(tempnode->getLeft());
            }
            if (tempnode->getRight() != nullptr)
            {
                tempqueue.push(tempnode->getRight());
            }
            tempqueue.pop();
        }
        return result;
    }

    /**
     * @brief Inorder traverse, NON-RECURSIVE.
     * @return Traverse result in a vector.
     * */
    vector<T> inOrderNonRecur()
    {
        vector<T> result;
        stack<BinaryNode<T> *> tempstack;
        BinaryNode<T> *tempnode = root;
        while (tempnode != nullptr || !tempstack.empty()) //当子树根节点为nullptr且栈为空时循环结束
        {
            while (tempnode != nullptr) //当子树根节点不为空一直向左遍历让最左处的路径节点全部入栈
            {
                tempstack.push(tempnode);
                tempnode = tempnode->getLeft();
            }
            if (!tempstack.empty()) //当栈不为空，让最远处的路径节点出栈并设置新的子树根节点
            {
                tempnode = tempstack.top();
                result.push_back(tempnode->getVal());
                tempnode = tempnode->getRight();
                tempstack.pop();
            }
        }
        return result;
    }
};
