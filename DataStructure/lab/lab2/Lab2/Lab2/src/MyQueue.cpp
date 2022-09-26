//
// Created by yixin on 2022/9/25.
//
template <typename T>
class MyQueue
{
private:
    const unsigned int CAPACITY;
    int front{};
    int rear{};
    bool full{};
    T *data;

public:
    /**
     * @brief Inits an empty queue with a given max capacity.
     * @param capacity: max capacity
     * */
    explicit MyQueue(int capacity) : CAPACITY(capacity)
    {
        this->front = 0;
        this->rear = 0;
        this->full = (capacity == 0);
        this->data = new T[capacity];
    }

    /**
     * @brief Enqueues an item.
     * @return true: on success;
     *         false: when exceeds capacity.
     * */
    bool enqueue(T item)
    {
        if(CAPACITY==0)
        {
            return false;
        }
        else if(CAPACITY==1)
        {
            if(rear==-1)
            {
                return false;
            }
            else
            {
                data[0]=T;
                rear=-1;
            }
        }
        else if(CAPACITY==2)
        {
            if()
        }
        else
        {
            int next = (rear + 1) % CAPACITY;
            if (front == 0 && rear == 0)
            {
                data[0] = T;
                rear = 1;
                return true;
            }
            else if (front == 0 && rear == 1)
            {
                data[1] = T;
            }
            else
            {
            }
        }
    }

    /**
     * @brief Removes front item from queue.
     * @return item: when queue is not empty;
     *         0: when queue is empty.
     * */
    T dequeue()
    {
        // TODO

        return 0;
    }

    /**
     * @brief Returns front item, without removing it.
     * @return item: when queue is not empty;
     *         0: when queue is empty.
     * */
    T getHead()
    {
        // TODO

        return 0;
    }

    /**
     * @brief Returns current size of the queue.
     * */
    int getSize()
    {
        // TODO

        return 0;
    }

    /**
     * @brief Returns whether the queue is empty.
     * */
    bool isEmpty()
    {
        // TODO

        return false;
    }

    /**
     * @brief Returns whether the queue is full.
     * */
    bool isFull()
    {
        // TODO

        return false;
    }
};
