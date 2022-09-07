#include "ProductList.h"
#include <iostream>
#include <string>
#include <cstdlib>

//无参构造函数
ProductList::ProductList()
{
    ProductName = "NULL";
    m_ProductNum = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

//有参构造函数，参数为Product类对象的引用，建立一个仅包含一个该商品的链表
ProductList::ProductList(Product &product)
{
    ProductName = product.GetName();
    m_ProductNum = 1;
    m_head = new Node;
    m_head->m_product = product;
    m_head->next = nullptr;
    m_tail = m_head;
}

//析构函数，释放链表节点的内存
ProductList::~ProductList()
{
    Node *temp;
    while (m_head != nullptr)
    {
        temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
}

//复制构造函数
ProductList::ProductList(const ProductList &copy)
{
    ProductName = copy.ProductName;
    m_ProductNum = copy.m_ProductNum;
    if (copy.m_head == nullptr)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        Node *temp, *tempcopy;
        m_head = new Node;
        temp = m_head;
        tempcopy = copy.m_head;
        while (tempcopy != copy.m_tail)
        {
            temp->m_product = tempcopy->m_product;
            tempcopy = tempcopy->next;
            temp->next = new Node;
            temp = temp->next;
        }
        temp->m_product = tempcopy->m_product;
        temp->next = nullptr;
        m_tail = temp;
    }
}

//重载赋值运算符
ProductList &ProductList::operator=(const ProductList &copy)
{
    if (this == &copy)
    {
        return *this;
    }
    ProductName = copy.ProductName;
    m_ProductNum = copy.m_ProductNum;
    if (copy.m_head == nullptr)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        Node *temp, *tempcopy;
        m_head = new Node;
        temp = m_head;
        tempcopy = copy.m_head;
        while (tempcopy != copy.m_tail)
        {
            temp->m_product = tempcopy->m_product;
            tempcopy = tempcopy->next;
            temp->next = new Node;
            temp = temp->next;
        }
        temp->m_product = tempcopy->m_product;
        temp->next = nullptr;
        m_tail = temp;
    }
    return *this;
}

//向链表中添加商品并排序，用插入排序使链表从前到后剩余保质期逐渐增多
void ProductList::AddProduct(Product &product)
{
    if (m_ProductNum < 0) //程序出错给出提示
    {
        cout << "m_ProductNum error" << endl;
        system("Pause");
    }
    else if (m_ProductNum == 0) //如果该种商品数量为0
    {
        ProductName = product.GetName();
        m_ProductNum = 1;
        m_head = new Node;
        m_head->m_product = product;
        m_head->next = nullptr;
        m_tail = m_head;
    }
    else // else该种商品数量不为0
    {
        m_ProductNum++;
        Node *temp = m_head;
        Node *tempfront;
        int temp_left_life = product.GetLeftLife();
        if (temp_left_life <= m_head->m_product.GetLeftLife()) // if这件商品剩余保质期最小
        {
            //需要额外对头指针进行操作
            m_head = new Node;
            m_head->m_product = product;
            m_head->next = temp;
        }
        else // else这件商品的剩余保质期并非最小
        {
            //按插入排序添加这件商品
            while (temp != nullptr && temp_left_life > temp->m_product.GetLeftLife())
            {
                tempfront = temp;
                temp = temp->next;
            }
            tempfront->next = new Node;
            tempfront->next->m_product = product;
            tempfront->next->next = temp;
            if (temp == nullptr)
            {
                m_tail = tempfront->next;
            }
        }
    }
}

//售卖该种类商品列表内的剩余保质期最少的商品，并返回打过折后的售卖价格
double ProductList::SellProduct(const double &discount = 1.0)
{
    if (m_ProductNum < 0) //程序运行错误给出提示
    {
        cout << "m_ProductNum error" << endl;
        system("Pause");
        return 0.0;
    }
    else if (m_ProductNum == 0) // if商品数量为0
    {
        // cout << "Sorry,we don't have this product now." << endl;
        return 0.0;
    }
    else if (m_ProductNum == 1) // if商品数量为1，出售该商品并初始化该商品种类
    {
        double temp_price = m_head->m_product.GetPrice();
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_ProductNum--;
        ProductName = "NULL";
        return temp_price * discount;
    }
    else // else正常出售商品
    {
        double temp_price = m_head->m_product.GetPrice();
        Node *temp = m_head->next;
        delete m_head;
        m_head = temp;
        m_ProductNum--;
        return temp_price * discount;
    }
}

//更新函数，更新剩余保质期，清理过期商品，应在一天的最后使用。
void ProductList::UpdateProductList()
{
    if (m_ProductNum < 0) //程序运行错误给出提示
    {
        cout << "m_ProductNum error" << endl;
        system("Pause");
    }
    else if (m_ProductNum == 0) // if商品数量为0直接返回
    {
        return;
    }
    else // else商品数量不为0
    {
        Node *temp = m_head;

        //更新该种商品下的每件商品
        while (temp != nullptr)
        {
            // cout<<temp->m_product.GetLeftLife()<<endl;
            temp->m_product.UpdateProduct();
            // cout<<temp->m_product.GetLeftLife()<<endl;
            temp = temp->next;
        }

        //清除保质期小于等于0的商品(直接从前往后进行清除)
        temp = m_head;
        Node *tempnext = m_head->next;
        while (temp != nullptr && temp->m_product.GetLeftLife() <= 0)
        {
            if (temp->m_product.GetLeftLife() < 0) //程序运行错误给出提示
            {
                cout << "m_left_life error" << endl;
                system("Pause");
            }
            delete temp;
            m_ProductNum--;
            temp = tempnext;
            if (temp != nullptr)
            {
                tempnext = temp->next;
            }
        }
        if (temp == nullptr) // if该链表空了
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_ProductNum = 0;
            ProductName = "NULL";
        }
        else // else该链表不为空
        {
            m_head = temp;
        }
    }
}

//获得该种商品价格
double ProductList::GetPrice()
{
    return m_head->m_product.GetPrice();
}
