template<typename T> class BinaryNode {
private:
    T val;
    BinaryNode<T> *left;
    BinaryNode<T> *right;

public:
    /**
     * @brief Creates a binary node as a leaf node.
     * */
    explicit BinaryNode(T val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    /**
     * @brief Creates a binary node with a left child and a right child (nullable).
     * */
    BinaryNode(T val, BinaryNode<T> *lNode, BinaryNode<T> *rNode) {
        this->val = val;
        this->left = lNode;
        this->right = rNode;
    }

    T getVal() const {
        return val;
    }

    BinaryNode<T> *getLeft() const {
        return left;
    }

    BinaryNode<T> *getRight() const {
        return right;
    }
};
