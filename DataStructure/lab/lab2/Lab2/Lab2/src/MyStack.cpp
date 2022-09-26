//
// Created by yixin on 2022/9/25.
//
template<typename T> class Node {
public:
    T val;
    Node<T>* prev;
    Node<T>* next;

    explicit Node(T val) {
        this->val = val;
    }
};


template<typename T> class MyStack {
private:
    const unsigned int CAPACITY;
    int curSize{};
    Node<T>* top;

public:
    /**
     * @brief Inits an empty stack with a given max capacity.
     * @param capacity: max capacity
     * */
    explicit MyStack(int capacity) : CAPACITY(capacity) {
        this->curSize = 0;
        this->top = nullptr;
    }

    /**
     * @brief Pushes a node to the top of the stack.
     * @param node: node to be pushed
     * @return true: on success;
     *         false: when exceeds capacity.
     * */
    bool push(Node<T>* node) {
        // TODO
        
        return false;
    }

    /**
     * @brief Pops top node out of the stack.
     * @return node: when stack is not empty;
     *         nullptr: when stack is empty.
     * */
    Node<T>* pop() {
        // TODO

        return nullptr;
    }

    /**
     * @brief Returns top node, without popping.
     * @return node: when stack is not empty;
     *         nullptr: when stack is empty.
     * */
    Node<T>* peek() {
        // TODO

        return nullptr;
    }
    
    /**
     * @brief Returns current size of the stack.
     * */
    int getSize() {
        // TODO
        
        return 0;
    }

    /**
     * @brief Returns whether the stack is empty.
     * */
    bool isEmpty() {
        // TODO

        return false;
    }

    /**
     * @brief Returns whether the stack is full.
     * */
    bool isFull() {
        // TODO

        return false;
    }
    
};