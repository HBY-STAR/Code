//
// Created by yixin on 2022/9/25.
//

//注：文件在本地Linux系统上均可成功编译并通过测试案例以及我自己添加的测试案例
//若无法编译或不能通过测试请联系我

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
        //注：容量为0,1,2的情况均需要单独考虑
        if (CAPACITY == 0) //容量为0
        {
            return false;
        }
        else if (CAPACITY == 1) //容量为1
        {
            if (front == -1)
            {
                return false;
            }
            else
            {
                data[0] = item;
                front = -1;
                return true;
            }
        }
        else if (CAPACITY == 2) //容量为2
        {
            if (front == -1)
            {
                if (rear == -1)
                {
                    return false;
                }
                else
                {
                    data[1] = item;
                    rear = -1;
                    return true;
                }
            }
            else
            {
                data[0] = item;
                front = -1;
                return true;
            }
        }
        else //容量大于2
        {
            if (front == rear && full == false) //当队列为空
            {
                data[front] = item; //在开始处插入
                rear = 1;
                return true;
            }
            else //当队列中至少有一个元素
            {
                if (full == true) //队列满了无法插入返回false
                {
                    return false;
                }
                else //队列未满插入
                {
                    data[rear] = item;            //在rear处插入
                    rear = (rear + 1) % CAPACITY; //找rear的下一个位置
                    if (rear == front)            //对插入后队列是否为满的判定
                    {
                        full = true;
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
        //注：容量为0,1,2的情况均需要单独考虑
        if (CAPACITY == 0) //容量为0
        {
            return 0;
        }
        else if (CAPACITY == 1) //容量为1
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
        else if (CAPACITY == 2) //容量为2
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
        else //容量大于2
        {
            if (front == rear && full == false) //当队列为空，返回0
            {
                return 0;
            }
            else //当队列不为空
            {
                if (full == true) //若队列满了则设置队列未满
                {
                    full = false;
                }
                int temp = front;               //保存front的值
                front = (front + 1) % CAPACITY; //找front的下一个位置
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
        if (front == rear && full == false) //若队列为空
        {
            return 0;
        }
        else //若队列不为空
        {
            return data[front];
        }
    }

    /**
     * @brief Returns current size of the queue.
     * */
    int getSize()
    {
        //注：容量为0,1,2的情况均需要单独考虑
        if (CAPACITY == 0) //容量为0
        {
            return 0;
        }
        else if (CAPACITY == 1) //容量为1
        {
            if (front == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (CAPACITY == 2) //容量为2
        {
            if (front == -1)
            {
                if (rear == -1)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                return 0;
            }
        }
        else //容量大于2
        {
            if (front == rear) //先考虑front与rear重合的情况
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
            else if (front < rear) //若front小于rear
            {
                return rear - front;
            }
            else //若front大于rear
            {
                return CAPACITY - front + rear;
            }
        }
    }

    /**
     * @brief Returns whether the queue is empty.
     * */
    bool isEmpty()
    {
        if (front == rear && full == false) //若队列为空
        {
            return true;
        }
        else //若队列不为空
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
