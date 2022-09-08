#include<algorithm>

//test

/*
关于C++11中的移动操作
当用一个已存在对象来构造一个新的对象时，
若该对象是一个左值，那么就用拷贝构造函数，
如果该对象是一个右值(临时量)，则用移动构造
函数。拷贝赋值和移动赋值同理。
*/

template<typename Object>
class Vector
{
public:
    //构造函数
    explicit Vector(int initSize = 0) : theSize{ initSize },
        theCapacity{ initSize + SPARE_CAPACITY }
    { objects = new Object[theCapacity]; }

    //拷贝构造函数
    Vector(const Vector & rhs) : theSize{ rhs.theSize} ,
        theCapacity{ rhs.theCapacity }, objects{ nullptr }
    {
        objects = new Object[theCapacity];
        for(int k=0; k < theSize; ++k)
            objects[k] = rhs.objects[k];
    }

    //重载赋值运算符
    Vector & operator= (const Vector & rhs)
    {
        Vector copy = rhs; //这里直接用了拷贝构造函数
        std::swap( *this, copy ); //要求移动构造函数和移动operator的实现
        return *this;
    }

    //析构函数
    ~Vector()
    { delete [] objects; }

    //移动构造函数
    Vector( Vector && rhs ) : theSize{ rhs.theSize },
        theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    //移动operator=的实现
    Vector & operator= (Vector && rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(objects, rhs.objects);

        return *this;
    }

    //改变Vector的大小
    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 );
            theSize = newSize * 2;
    }

    //改变Vector的容量
    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[newCapacity];
        for(int k = 0; k < theSize; ++k)
            newArray[k] = std::move( objects[k] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [] newArray;
    } 

    //重载 [ ] 运算符
    Object & operator[] (int index)
    { return objects[ index ]; }
    const Object & operator[] (int index) const
    { return objects[ index ]; }

    //检验容器是否为空
    bool empty() const 
    { return size() == 0; }

    //返回容器中元素个数
    int size() const
    { return theSize; }

    //返回容器容量
    int capacity() const
    { return theCapacity; }

    //将x添加到表的末端
    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2*theCapacity + 1 );
        objects[theSize++] = x;
    }

    void push_back( Object && x )
    {
        if(theSize == theCapacity)
            reserve( 2*theCapacity + 1);
        objects[theSize++] = std::move(x);
    }

    //删除位于表末端的元素
    void pop_back()
    {
        --theSize;
    }

    //返回位于表末端的对象
    const Object & back() const
    {
        return objects[thesize - 1];
    }

    //定义迭代器
    typedef Object* iterator;
    typedef const Object* const_iterator;

    //返回一个适当的迭代器，表示表中的第一项
    iterator begin()
    { return &objects[0]; }
    const_iterator begin() const
    { return &objects[0]; }

    //返回一个适当的迭代器，表示容器中的尾端标记
    //(即容器中最后一项之后的位置)
    iterator end()
    { return &objects[ size() ]; }
    const_iterator end() const
    { return &objects[ size() ]; }

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;    //容器中元素个数
    int theCapacity;    //容器容量
    Object * objects;
};