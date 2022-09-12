#include <iostream>

using namespace std;

//二叉查找树
template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &rhs);
    BinarySearchTree(BinarySearchTree &&rhs);
    ~BinarySearchTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree(ostream &out = cout) const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

    BinarySearchTree &operator=(const BinarySearchTree &rhs);
    BinarySearchTree &operator=(BinarySearchTree &&rhs);

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}

        BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    void insert(const Comparable &x, BinaryNode *&t);
    void insert(Comparable &&x, BinaryNode *&t);
    void remove(const Comparable &x, BinaryNode *&t);
    BinaryNode *findMin(BinaryNode *&t) const;
    BinaryNode *findMax(BinaryNode *&t) const;
    bool contains(const Comparable &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t);
    void printTree(BinaryNode *t, ostream &out) const;
    BinaryNode *clone(BinaryNode *t) const;

public:
    bool contains(const Comparable &x)
    {
        return contains(x, root);
    }
    bool contains(const Comparable &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (x > t->element)
            return contains(x, t->right);
        else
            return true;
    }

    void insert(const Comparable)
    {
        insert(x, root);
    }
    void insert(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (x > t->element)
            insert(x, t->right);
        else
            ;
    }
    void insert(Comparable &&x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        else if (x < t->element)
            insert(std::move(x), t->left);
        else if (x > t->element)
            insert(std::move(x), t->right);
        else
            ;
    }

    void remove(const Comparable &x)
    {
        remove(x, root);
    }
    void remove(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (x > t->element)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->right == nullptr)
            return t;
        return findMax(t->right);
    }

    ~BinarySearchTree()
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        makeEmpty(root);
    }
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }
};

template <typename Comparable>
class AvlTree
{
    struct AvlNode
    {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable &ele, AvlNode *lt, AvlNode *rt, int h = 0)
            : element{ele}, left(lt), right{rt}, height{h} {}

        AvlNode(Comparable &&ele, AvlNode *lt, AvlNode *rt, int h = 0)
            : element{std::move(ele)}, left(lt), right{rt}, height{h} {}
    };

    static const int ALLOWED_IMBALANCE = 1;

    int height(AvlNode *t) const
    {
        return t == nullptr ? -1 : t->height;
    }

    void insert(const Comparable &x, AvlNode *&t)
    {
        if (t == nullptr)
            t = new AvlNode{x, nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (x > t->element)
            insert(x, t->right);

        balance(t);
    }

    void balance(AvlNode *&t)
    {
        if (t == nullptr)
            return;
        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
        {
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
        {
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    void rotateWithLeftChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode *&k1)
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(AvlNode *&k3)
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    void remove(const Comparable &x, AvlNode *&t)
    {
        if (t == nullptr)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (x > t->element)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }

        balance(t);
    }
};
