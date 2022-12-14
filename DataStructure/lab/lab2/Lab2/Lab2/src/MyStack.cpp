//
// Created by yixin on 2022/9/25.
//

//注：文件在本地Linux系统上均可成功编译并通过测试案例以及我自己添加的测试案例
//若无法编译或不能通过测试请联系我

template <typename T>
class Node
{
public:
    T val;
    Node<T> *prev;
    Node<T> *next;

    explicit Node(T val)
    {
        this->val = val;
    }
};

template <typename T>
class MyStack
{
private:
    const unsigned int CAPACITY;
    int curSize{};
    Node<T> *top;

public:
    /**
     * @brief Inits an empty stack with a given max capacity.
     * @param capacity: max capacity
     * */
    explicit MyStack(int capacity) : CAPACITY(capacity)
    {
        this->curSize = 0;
        this->top = nullptr;
    }

    /**
     * @brief Pushes a node to the top of the stack.
     * @param node: node to be pushed
     * @return true: on success;
     *         false: when exceeds capacity.
     * */
    bool push(Node<T> *node)
    {
        if (top == nullptr) //若栈为空
        {
            node->prev = nullptr;
            node->next = nullptr;
            top = node;
            curSize++;
            return true;
        }
        else if (curSize == CAPACITY) //若栈满了
        {
            return false;
        }
        else //若栈未满
        {
            node->prev = top;
            node->next = nullptr;
            top = top->next = node;
            curSize++;
            return true;
        }
    }

    /**
     * @brief Pops top node out of the stack.
     * @return node: when stack is not empty;
     *         nullptr: when stack is empty.
     * */
    Node<T> *pop()
    {
        if (top == nullptr) //若栈为空
        {
            return nullptr;
        }
        else //若栈不为空
        {
            Node<T> *temp = top;
            top = top->prev;
            curSize--;
            return temp;
        }
    }

    /**
     * @brief Returns top node, without popping.
     * @return node: when stack is not empty;
     *         nullptr: when stack is empty.
     * */
    Node<T> *peek()
    {
        return top;
    }

    /**
     * @brief Returns current size of the stack.
     * */
    int getSize()
    {
        return curSize;
    }

    /**
     * @brief Returns whether the stack is empty.
     * */
    bool isEmpty()
    {
        return top == nullptr;
        ;
    }

    /**
     * @brief Returns whether the stack is full.
     * */
    bool isFull()
    {
        return curSize == CAPACITY;
    }
};