#ifndef BIGNUM_H
#define BIGNUM_H

#include <fstream>
#include <iostream>

using namespace std;

/*
对于大整数的类，大整数的最大位数为100
重载了<<、>>、+、-、运算符
上次更新时间:  2022/5/16
*/
class BigNum
{
private:
    int m_num[100];  //存储大整数的数组
    int m_count;     //大整数的位数
    bool m_positive; //大整数的正负
    bool m_check;    //检测大整数是否超出范围

public:
    BigNum();                                                //无参构造函数
    BigNum(ifstream &);                                      //有参构造函数
    BigNum(const string &);                                  //有参构造函数
    void ShowBigNum();                                       //展示函数，用于测试
    friend ofstream &operator<<(ofstream &, const BigNum &); //重载<<运算符
    friend istream &operator>>(istream &, BigNum &);         //重载>>运算符
    friend BigNum operator+(BigNum &, BigNum &);             //重载+运算符
    friend BigNum operator-(BigNum &, BigNum &);             //重载—运算符
};

#endif