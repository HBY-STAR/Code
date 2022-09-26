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
        if (CAPACITY == 0)
        {
            return false;
        }
        else if (CAPACITY == 1)
        {
            if (front == -1)
            {
                return false;
            }
            else
            {
                data[0] = T;
                front = -1;
                return true;
            }
        }
        else if (CAPACITY == 2)
        {
            if (front == -1)
            {
                if (rear == -1)
                {
                    return false;
                }
                else
                {
                    data[1] = T;
                    rear = -1;
                    return true;
                }
            }
            else
            {
                data[0] = T;
                front = -1;
                return true;
            }
        }
        else
        {
            if (front == rear && full == false) //当队列为空
            {
                data[front] = T;
                rear = 1;
                return true;
            }
            else //当队列中至少有一个元素
            {
                if (full == true)
                {
                    return false;
                }
                else
                {
                    data[rear] = T;
                    rear = (rear + 1) % CAPACITY;
                    if (rear == front)
                    {
                        full == true;
                    }
                    return true;
                }
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
        if (CAPACITY == 0)
        {
            return 0;
        }
        else if (CAPACITY == 1)
        {
            if (front == -1)
            {
                front = 0;
                return data[0];
            }
            else
            {
                return 0;
            }
        }
        else if (CAPACITY == 2)
        {
            if (rear == -1)
            {
                rear = 0;
                return data[1];
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                    return data[0];
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            if (front == rear && full == false) //当队列为空
            {
                return 0;
            }
            else //当队列不为空
            {
                if (full == true)
                {
                    full = false;
                }
                int temp = front;
                front = (front + 1) % CAPACITY;
                return data[temp];
            }
        }
    }

    /**
     * @brief Returns front item, without removing it.
     * @return item: when queue is not empty;
     *         0: when queue is empty.
     * */
    T getHead()
    {
        if (front == rear && full == false)
        {
            return 0;
        }
        else
        {
            return data[front];
        }
    }

    /**
     * @brief Returns current size of the queue.
     * */
    int getSize()
    {
        if (front == rear)
        {
            if (full == true)
            {
                return CAPACITY;
            }
            else
            {
                return 0;
            }
        }
        else if (front < rear)
        {
            return rear - front;
        }
        else
        {
            return CAPACITY - front + rear;
        }
    }

    /**
     * @brief Returns whether the queue is empty.
     * */
    bool isEmpty()
    {
        if (front == rear && full == false)
        {
            return true;
        }
        else
        {
            return false;
        }

        return false;
    }

    /**
     * @brief Returns whether the queue is full.
     * */
    bool isFull()
    {
        return full;
    }
};
