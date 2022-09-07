#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include "Product.h"

/*
对于每种商品的类，包含了每种商品的名字、数量、信息存放地址等。
上次更新时间：2022/4/28
*/
class ProductList
{
private:
    //这里用了链表来存储一个商品种类中的所有商品
    struct Node
    {
        Product m_product;
        struct Node *next;
    };
    
    string ProductName; //商品名称
    Node *m_head;       //存放商品信息链表的头指针
    Node *m_tail;       //存放商品信息链表的尾指针
    int m_ProductNum;   //该种商品剩余数量

public:
    ProductList();                               //无参构造函数
    ProductList(Product &);                      //有参构造函数
    ~ProductList();                              //析构函数
    ProductList(const ProductList &);            //复制构造函数
    ProductList &operator=(const ProductList &); //重载赋值运算符
    void AddProduct(Product &);                  //添加商品
    double SellProduct(const double &);          //出售该种商品
    void UpdateProductList();                    //每天更新商品剩余保质期
    Node *GetHead() { return m_head; };          //获得商品名称
    string GetName() { return ProductName; };    //获得商品名称
    double GetPrice();                           //获得商品价格
    int GetNum() { return m_ProductNum; };       //获得该种商品的数量
};

#endif