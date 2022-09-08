template <typename Object>
class List
{
private:
  struct Node
  {
    Object data; //数据对象
    Node *prev;  //前指针
    Node *next;  //后指针

    //构造函数
    Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
        : data{d}, prev{p}, next{n} {}
    Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
        : data{std::move(d)}, prev{p}, next{n} {}
  };

public:
  class const_iterator
  {
  public:
    //默认构造函数
    const_iterator() : current{nullptr}
    {
    }

    //重载 * 运算符
    const Object &operator*() const
    {
      return retrieve();
    }

    //重载 前缀++ 运算符，即 ++iterator 。
    const_iterator &operator++()
    {
      current = current->next;
      return *this;
    }

    //重载 后缀++ 运算符，即 iterator++ 。
    const_iterator &operator++(int)
    {
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    //重载 == 、!= 运算符
    bool operator==(const const_iterator &rhs) const
    {
      return current == rhs.current;
    }
    bool operator!=(const const_iterator &rhs) const
    {
      return !(*this == rhs);
    }

  protected:
    Node *current;

    //解引用
    Object &retrieve() const
    {
      return current->data;
    }

    //用Node指针构造迭代器
    const_iterator(Node *p) : current{p}
    {
    }

    //给List类访问protected内成员的权限
    friend class List<Object>;
  };

  class iterator : public const_iterator
  {
  public:
    //默认构造函数
    iterator()
    {
    }

    //重载 * 运算符
    Object &operator*()
    {
      return const_iterator::retrieve();
    }
    const Object &operator*() const
    {
      return const_iterator::operator*();
    }

    //重载 前缀++ 运算符
    iterator &operator++()
    {
      this->current = this->current->next;
      return *this;
    }

    //重载 后缀++ 运算符
    iterator &operator++(int)
    {
      iterator old = *this;
      ++(*this);
      return old;
    }

  protected:
    //用Node指针构造迭代器
    iterator(Node *p) : const_iterator{p}
    {
    }

    //给List类访问protected内成员的权限
    friend class List<Object>;
  };

public:
  List()
  {
    init();
  }

  List(const List &rhs)
  {
    init();
    for (auto &x : rhs) //依次访问rhs中的每一个元素
      push_back(x);
  }

  ~List()
  {
    clear();
    delete head;
    delete tail;
  }

  List &operator=(const List &rhs)
  {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  List(List &&rhs)
      : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
  {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
  }

  List &operator=(List &&rhs)
  {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
  }

  iterator begin()
  {
    return {head->next};
  } //这里用Node指针构造迭代器
  const_iterator begin() const
  {
    return {head->next};
  }
  iterator end()
  {
    return {tail};
  }
  const_iterator end() const
  {
    return {tail};
  }

  int size() const
  {
    return theSize;
  }
  bool empty() const
  {
    return size() == 0;
  }

  void clear()
  {
    while (!empty())
      pop_front();
  }

  Object &front()
  {
    return *begin();
  }
  const Object &front() const
  {
    return *begin();
  }
  Object &back()
  {
    return *--end();
  }
  const Object &back() const
  {
    return *--end();
  }

  void push_front(const Object &x)
  {
    insert(begin(), x);
  }
  void push_front(Object &&x)
  {
    insert(begin(), std::move(x));
  }

  void push_back(const Object &x)
  {
    insert(end(), x);
  }
  void push_back(Object &&x)
  {
    insert(end(), std::move(x));
  }

  void pop_front()
  {
    erase(begin());
  }
  void pop_back()
  {
    erase(--end());
  }

  //在itr前插入x
  iterator insert(iterator itr, const Object &x)
  {
    Node *p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node{x, p->prev, p}};
  }
  iterator insert(iterator itr, Object &&x)
  {
    Node *p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
  }

  iterator erase(iterator itr)
  {
  }
  iterator erase(iterator from, iterator to)
  {
  }

private:
  int theSize;
  Node *head;
  Node *tail;

  void init()
  {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
  }
};