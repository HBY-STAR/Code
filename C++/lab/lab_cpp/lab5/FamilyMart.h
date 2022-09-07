#ifndef FAMILYMART_H
#define FAMILYMART_H
// TODO
//  you need to modify this file
//  you need to finish this class, but don't change the definition of the existing functions below.

#include "ProductList.h"

/*
对于一个商店的类，包含了当前日期和库存的信息
上次更新时间：2022/5/2
*/
class FamilyMart
{
public:
    FamilyMart(); // no commodity

    // using file name to construct FamilyMart
    // the format of the file is the same as purchase.txt
    FamilyMart(const std::string &cmmodity_file_name);

    ~FamilyMart();

    // using file name to add new commodities every morning, the format of the file is the same as purchase.txt
    void purchase_file(const std::string &cmmodity_file_name);

    // the same as above, this is sell process
    void sell_file(const std::string &sell_file_name);

    // return a total sales, a turnover since the start of new FamilyMart.
    double show_turnover();

    // ... your other function
    //每过一天就对当前日期和库存商品进行更新，该函数应该在当天的售卖完成后再执行。
    void UpdateFamilyMart();

private:
    //这里用一个链表来存放商店内的所有种类的商品
    struct ListNode
    {
        ProductList m_productlist;
        struct ListNode *next;
    };

    // some attributes
    ListNode *m_head;    //存放商品种类链表的头指针
    ListNode *m_tail;    //存放商品种类链表的尾指针
    int m_TypeNum;       //商品种类数量
    int NowDate[3];      //目前的日期
    double m_AllProfits; //从开张(2022/5/2)开始的总销售额
    double m_DaySell;    //一天的销售额
    // double m_DayPay;
};
#endif // FAMILYMART_H