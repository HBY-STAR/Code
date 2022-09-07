#include "Product.h"

//无参构造函数
Product::Product()
{
    m_name = "NULL";
    m_price = 0.0;
    m_life = 0;
    m_left_life = 0;
    m_date[1] = 0;
    m_date[2] = 0;
    m_date[3] = 0;
}

//有参构造函数，需要提供当前日期以计算剩余保质期
Product::Product(string name, double price, int life, int *date, int *NowDate)
{
    m_name = name;
    m_price = price;
    m_life = life;
    m_left_life = LeftLife(life, date, NowDate);
    m_date[1] = date[1];
    m_date[2] = date[2];
    m_date[3] = date[3];
}

//析构函数，空语句。
Product::~Product()
{
    ;
}

//复制构造函数
Product::Product(const Product &copy)
{
    m_name = copy.m_name;
    m_price = copy.m_price;
    m_life = copy.m_life;
    m_left_life = copy.m_left_life;
    m_date[1] = copy.m_date[1];
    m_date[2] = copy.m_date[2];
    m_date[3] = copy.m_date[3];
}

//重载赋值运算符
Product &Product::operator=(const Product &copy)
{
    if (this == &copy)
    {
        return *this;
    }
    m_name = copy.m_name;
    m_price = copy.m_price;
    m_life = copy.m_life;
    m_left_life = copy.m_left_life;
    m_date[1] = copy.m_date[1];
    m_date[2] = copy.m_date[2];
    m_date[3] = copy.m_date[3];
    return *this;
}

//计算剩余保质期，进行此计算时并未计入当前这一天，因而在使用该函数后，这一天的最后要更新保质期。
int Product::LeftLife(int life, int *date, int *NowDate)
{
    //区分平年闰年
    static int month[2][13] =
        {{9999999, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  //平年
         {9999999, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; //闰年

    //临时变量
    int day = 0;
    int tempmonth = 0;
    int tempyear = 0;
    int leap = 0;

    if (date[0] == NowDate[0]) // if年份相同
    {
        if (date[1] == NowDate[1]) // if月份相同
        {
            day = NowDate[2] - date[2];
            return life - day;
        }
        else // else月份不同
        {
            if ((date[0] % 4 == 0 && date[0] % 100 != 0) || (date[0] % 400 == 0))
            {
                leap++;
            }
            tempmonth = date[1];
            day = month[leap][tempmonth] - date[2];
            tempmonth++;
            while (tempmonth != NowDate[1])
            {
                day += month[leap][tempmonth];
                tempmonth++;
            }
            day += NowDate[2];
            return life - day;
        }
    }
    else // else年份不同
    {
        tempyear = date[0];
        if ((tempyear % 4 == 0 && tempyear % 100 != 0) || (tempyear % 400 == 0))
        {
            leap++;
        }
        tempmonth = date[1];
        day = month[leap][tempmonth] - date[2];
        tempmonth++;
        while (tempmonth != 13)
        {
            day += month[leap][tempmonth];
            tempmonth++;
        }
        tempyear++;
        while (tempyear != NowDate[0])
        {
            if ((tempyear % 4 == 0 && tempyear % 100 != 0) || (tempyear % 400 == 0))
            {
                day += 366;
            }
            else
            {
                day += 365;
            }
            tempyear++;
        }
        leap = 0;
        if ((tempyear % 4 == 0 && tempyear % 100 != 0) || (tempyear % 400 == 0))
        {
            leap++;
        }
        tempmonth = 0;
        while (tempmonth != NowDate[1])
        {
            day += month[leap][tempmonth];
            tempmonth++;
        }
        day += NowDate[2];
        return life - day;
    }
}
