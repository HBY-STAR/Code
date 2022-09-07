#include "BigNum.h"

//无参构造函数
BigNum::BigNum()
{
    for (int i = 0; i < 100; i++)
    {
        m_num[i] = 0;
    }
    m_count = 0;
    m_positive = true;
    m_check = true;
}

//接受一个文件流输入的有参构造函数
BigNum::BigNum(ifstream &input)
{
    string temp;
    input >> temp;
    m_count = temp.length();
    if (m_count > 100)
    {
        m_check = false;
        for (int i = 0; i < 100; i++)
        {
            m_num[i] = 0;
        }
        m_positive = true;
    }
    else
    {
        for (int i = 0; i < m_count; i++)
        {
            m_num[i] = int(temp[i] - '0');
        }
        for (int i = m_count; i < 100; i++)
        {
            m_num[i] = 0;
        }
        m_positive = true;
        m_check = true;
    }
}

//接受一个字符串输入的有参构造函数
BigNum::BigNum(const string &temp)
{
    m_count = temp.length();
    if (m_count > 100)
    {
        m_check = false;
        for (int i = 0; i < 100; i++)
        {
            m_num[i] = 0;
        }
        m_positive = true;
    }
    else
    {
        for (int i = 0; i < m_count; i++)
        {
            m_num[i] = int(temp[i] - '0');
        }
        for (int i = m_count; i < 100; i++)
        {
            m_num[i] = 0;
        }
        m_positive = true;
        m_check = true;
    }
}

//重载<<运算符，接受一个BigNum对象并将其输入到流中
ofstream &operator<<(ofstream &output, const BigNum &result)
{
    if (result.m_check == false)
    {
        output << "out of range";
        return output;
    }
    else if (result.m_positive == false)
    {
        output << "-";
    }
    for (int i = 0; i < result.m_count; i++)
    {
        output << result.m_num[i];
    }
    return output;
}

//重载>>运算符，接受一个流输入并将其存储在BigNum对象中
istream &operator>>(istream &input, BigNum &result)
{
    string temp;
    input >> temp;
    result = BigNum(temp);
    return input;
}

//重载+运算符，接受两个BinNum对象，返回二者加和之后的对象
BigNum operator+(BigNum &X, BigNum &Y)
{
    BigNum Z;
    if (X.m_check == false || Y.m_check == false)
    {
        Z.m_check = false;
        return Z;
    }
    BigNum x = X;
    BigNum y = Y;

    //尾部对齐
    int big_count, small_count;
    if (X.m_count > Y.m_count)
    {
        big_count = X.m_count;
        small_count = Y.m_count;
        for (int i = Y.m_count - 1; i >= 0; i--)
        {
            Y.m_num[i + big_count - small_count] = Y.m_num[i];
        }
        for (int i = 0; i < big_count - small_count; i++)
        {
            Y.m_num[i] = 0;
        }
    }
    else
    {
        big_count = Y.m_count;
        small_count = X.m_count;
        for (int i = X.m_count - 1; i >= 0; i--)
        {
            X.m_num[i + big_count - small_count] = X.m_num[i];
        }
        for (int i = 0; i < big_count - small_count; i++)
        {
            X.m_num[i] = 0;
        }
    }

    //进行计算
    for (int i = big_count - 1; i > 0; i--)
    {
        if (X.m_num[i] + Y.m_num[i] + Z.m_num[i] >= 10)
        {
            Z.m_num[i - 1]++;
        }
        Z.m_num[i] = (Z.m_num[i] + X.m_num[i] + Y.m_num[i]) % 10;
    }
    if (X.m_num[0] + Y.m_num[0] + Z.m_num[0] >= 10)
    {
        if (big_count >= 100)
        {
            Z.m_check = false;
            return Z;
        }
        Z.m_num[0] = (Z.m_num[0] + X.m_num[0] + Y.m_num[0]) % 10;
        for (int i = big_count; i > 0; i--)
        {
            Z.m_num[i] = Z.m_num[i - 1];
        }
        Z.m_num[0] = 1;
        Z.m_count = big_count + 1;
    }
    else
    {
        Z.m_num[0] = Z.m_num[0] + X.m_num[0] + Y.m_num[0];
        Z.m_count = big_count;
    }
    X = x;
    Y = y;
    return Z;
}

//重载-运算符，接受两个BigNum对象，返回前者减去后者之后的对象
BigNum operator-(BigNum &X, BigNum &Y)
{
    BigNum Z;
    if (X.m_check == false || Y.m_check == false)
    {
        Z.m_check = false;
        return Z;
    }
    BigNum x = X;
    BigNum y = Y;

    //尾部对齐
    int big_count, small_count;
    if (X.m_count > Y.m_count)
    {
        big_count = X.m_count;
        small_count = Y.m_count;
        for (int i = Y.m_count - 1; i >= 0; i--)
        {
            Y.m_num[i + big_count - small_count] = Y.m_num[i];
        }
        for (int i = 0; i < big_count - small_count; i++)
        {
            Y.m_num[i] = 0;
        }
    }
    else
    {
        big_count = Y.m_count;
        small_count = X.m_count;
        for (int i = X.m_count - 1; i >= 0; i--)
        {
            X.m_num[i + big_count - small_count] = X.m_num[i];
        }
        for (int i = 0; i < big_count - small_count; i++)
        {
            X.m_num[i] = 0;
        }
    }
    for (int i = big_count - 1; i > 0; i--)
    {
        if (X.m_num[i] + Z.m_num[i] - Y.m_num[i] < 0)
        {
            Z.m_num[i - 1] = -1;
            Z.m_num[i] = X.m_num[i] + 10 + Z.m_num[i] - Y.m_num[i];
        }
        else
        {
            Z.m_num[i] = X.m_num[i] + Z.m_num[i] - Y.m_num[i];
        }
    }

    //进行计算
    if (X.m_num[0] + Z.m_num[0] - Y.m_num[0] < 0)
    {
        Z.m_num[0] = X.m_num[0] + 10 + Z.m_num[0] - Y.m_num[0];
        for (int i = 0; i < big_count - 1; i++)
        {
            Z.m_num[i] = 9 - Z.m_num[i];
        }
        Z.m_num[big_count - 1] = 10 - Z.m_num[big_count - 1];
        Z.m_positive = false;
        Z.m_count = big_count;
    }
    else if (X.m_num[0] + Z.m_num[0] - Y.m_num[0] == 0)
    {
        Z.m_num[0] = 0;
        int count = 0;
        for (int i = 0; i < big_count; i++)
        {
            if (Z.m_num[i] == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < big_count - count; i++)
        {
            Z.m_num[i] = Z.m_num[i + count];
        }
        for (int i = big_count - count; i < big_count; i++)
        {
            Z.m_num[i] = 0;
        }
        Z.m_count = big_count - count;
    }
    else
    {
        Z.m_num[0] = X.m_num[0] + Z.m_num[0] - Y.m_num[0];
        Z.m_count = big_count;
    }
    X = x;
    Y = y;
    return Z;
}

//展示大整数的函数，可作测试用
void BigNum::ShowBigNum()
{
    if (m_count == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (m_positive == false)
    {
        cout << "-";
    }
    for (int i = 0; i < m_count; i++)
    {
        cout << m_num[i];
    }
    cout << endl;
}