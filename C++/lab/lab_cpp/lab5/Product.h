#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

/*
对于每件商品的类，包含了商品的各种信息
上次更新时间：2022/4/28
*/
class Product
{
private:
    string m_name;   //商品名称
    double m_price;  //商品价格
    int m_life;      //商品总保质期
    int m_left_life; //商品剩余保质期
    int m_date[3];   //商品生产日期
public:
    Product();                                  //无参构造函数
    Product(string, double, int, int *, int *); //有参构造函数
    ~Product();                                 //析构函数
    Product(const Product &);                   //复制构造函数
    Product &operator=(const Product &);        //重载赋值运算符
    int LeftLife(int, int *, int *);            //计算商品剩余保质期
    string GetName() { return m_name; };        //获取商品名称
    int GetLeftLife() { return m_left_life; };  //获取商品剩余保质期
    double GetPrice() { return m_price; };      //获取商品价格
    void UpdateProduct() { m_left_life--; };    //每天更新商品剩余保质期
};

#endif