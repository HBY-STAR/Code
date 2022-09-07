#include "FamilyMart.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//无参构造函数，初始日期为2022/5/2,初始库存为nullptr。
FamilyMart::FamilyMart()
{
    //初始化
    m_TypeNum = 0;
    // m_DayPay = 0.0;
    m_DaySell = 0.0;
    m_AllProfits = 0.0;
    NowDate[0] = 2022;
    NowDate[1] = 5;
    NowDate[2] = 2;
    m_head = nullptr;
    m_tail = nullptr;
}

//有参构造函数，参数为第一天进的商品清单的文件名，初始日期为2022/5/2,初始库存为该商品清单
FamilyMart::FamilyMart(const std::string &cmmodity_file_name)
{
    //初始化
    m_TypeNum = 0;
    // m_DayPay = 0.0;
    m_DaySell = 0.0;
    m_AllProfits = 0.0;
    NowDate[0] = 2022;
    NowDate[1] = 5;
    NowDate[2] = 2;
    m_head = nullptr;
    m_tail = nullptr;

    ifstream inFilePurchase;
    inFilePurchase.open(cmmodity_file_name);

    //储存每个商品各种信息的变量
    string name;
    double price;
    int life;
    int date[3];

    //临时变量
    Product tempproduct;
    char tempch;
    int tempcount;
    char tempstr[100];
    ListNode *tempnode;

    //跳过文件第一行的内容
    inFilePurchase.getline(tempstr, 90);
    inFilePurchase.clear();

    //循环读入数据并进行操作
    while (inFilePurchase.eof() == false)
    {
        /***********数据读取***********/
        inFilePurchase >> name;
        if (inFilePurchase.eof() == true)
        {
            break;
        }
        inFilePurchase >> price;
        inFilePurchase >> life;
        inFilePurchase >> date[0];
        inFilePurchase >> tempch;
        inFilePurchase >> date[1];
        inFilePurchase >> tempch;
        inFilePurchase >> date[2];
        /*****************************/

        //生成临时商品对象
        tempproduct = Product(name, price, life, date, NowDate);

        //进了过期商品直接跳过
        if (tempproduct.GetLeftLife() <= 0)
        {
            continue;
        }

        if (m_head == nullptr) // if库存为空
        {
            m_head = new ListNode;
            m_head->m_productlist = ProductList(tempproduct);
            m_head->next = nullptr;
            m_tail = m_head;
            m_TypeNum++;
            // m_DayPay += price;
        }
        else // else库存不为空
        {
            tempcount = 0;
            tempnode = m_head;
            //在库存中寻找名字相匹配的商品种类
            while (tempnode != nullptr && tempnode->m_productlist.GetName() != name)
            {
                tempcount++;
                tempnode = tempnode->next;
            }
            if (tempcount == m_TypeNum || tempnode == nullptr) // if没有找到，则创建一个商品种类
            {
                m_tail->next = new ListNode;
                m_tail->next->m_productlist = ProductList(tempproduct);
                m_tail->next->next = nullptr;
                m_tail = m_tail->next;
                m_TypeNum++;
                // m_DayPay += price;
            }
            else // else找到了该商品种类，直接在该商品种类后添加该商品
            {
                tempnode->m_productlist.AddProduct(tempproduct); // m_DayPay += price;
            }
        }
    }
}

//析构函数，释放运行中申请的链表节点的内存。
FamilyMart::~FamilyMart()
{
    ListNode *templist;
    while (m_head != nullptr)
    {
        templist = m_head->next;
        delete m_head;
        m_head = templist;
    }
}

//进货函数，参数为要进货的商品清单的文件名，将商品添加进库存中。
void FamilyMart::purchase_file(const std::string &cmmodity_file_name)
{
    ifstream inFilePurchase;
    inFilePurchase.open(cmmodity_file_name);

    //储存每个商品各种信息的变量
    string name;
    double price;
    int life;
    int date[3];

    //临时变量
    Product tempproduct;
    char tempch;
    int tempcount;
    char tempstr[100];
    ListNode *tempnode;

    //跳过文件第一行的内容
    inFilePurchase.getline(tempstr, 90);
    inFilePurchase.clear();

    //循环读入数据并进行操作
    while (inFilePurchase.eof() == false)
    {
        /***********数据读取***********/
        inFilePurchase >> name;
        if (inFilePurchase.eof() == true)
        {
            break;
        }
        inFilePurchase >> price;
        inFilePurchase >> life;
        inFilePurchase >> date[0];
        inFilePurchase >> tempch;
        inFilePurchase >> date[1];
        inFilePurchase >> tempch;
        inFilePurchase >> date[2];
        /*****************************/

        //生成临时商品对象
        tempproduct = Product(name, price, life, date, NowDate);

        //进了过期商品直接跳过
        if (tempproduct.GetLeftLife() <= 0)
        {
            continue;
        }

        if (m_head == nullptr) // if库存为空
        {
            m_head = new ListNode;
            m_head->m_productlist = ProductList(tempproduct);
            m_head->next = nullptr;
            m_tail = m_head;
            m_TypeNum++;
            // m_DayPay += price;
        }
        else // else库存不为空
        {
            tempcount = 0;
            tempnode = m_head;
            //在库存中寻找名字相匹配的商品种类
            while (tempnode != nullptr && tempnode->m_productlist.GetName() != name)
            {
                tempcount++;
                tempnode = tempnode->next;
            }
            if (tempcount == m_TypeNum || tempnode == nullptr) // if没有找到，则创建一个商品种类
            {
                m_tail->next = new ListNode;
                m_tail->next->m_productlist = ProductList(tempproduct);
                m_tail->next->next = nullptr;
                m_tail = m_tail->next;
                m_TypeNum++;
                // m_DayPay += price;
            }
            else // else找到了该商品种类，直接在该商品种类后添加该商品
            {
                tempnode->m_productlist.AddProduct(tempproduct);
                // m_DayPay += price;
            }
        }
    }
}

//售货函数，参数为要售卖的商品清单的文件名，售卖商品并更新销售额。
void FamilyMart::sell_file(const std::string &sell_file_name)
{
    m_DaySell = 0;
    ifstream inFileSell;
    inFileSell.open(sell_file_name);

    //储存要卖出商品特征的变量
    string name;
    double discount;

    //临时变量
    char ch;
    char tempstr[100];
    ListNode *tempnode;
    int tempcount = 0;

    //跳过文件第一行的内容
    inFileSell.getline(tempstr, 90);
    inFileSell.clear();

    while (inFileSell.eof() == false)
    {
        /*********数据读入*********/
        inFileSell >> name;
        if (inFileSell.eof() == true)
        {
            break;
        }
        inFileSell.get();
        ch = inFileSell.get();
        if (ch != '\n')
        {
            inFileSell >> discount;
        }
        else
        {
            discount = 1.0;
        }
        /*************************/

        tempcount = 0;
        tempnode = m_head;

        //在库存中寻找该种商品
        while (tempnode != nullptr && tempnode->m_productlist.GetName() != name)
        {
            tempcount++;
            tempnode = tempnode->next;
        }
        if (tempcount == m_TypeNum || tempnode == nullptr) // if没找到该种商品
        {
            // cout << "Sorry,we don't have " << name << " now." << endl;
            ;
        }
        else // else找到了该种商品
        {
            if (tempnode->m_productlist.GetNum() == 0) //如果该种商品库存为0
            {
                // cout << "Sorry,we don't have " << name << " now." << endl;
                ;
            }
            else // else该种商品库存不为0
            {
                m_DaySell += tempnode->m_productlist.SellProduct(discount);
            }
        }
    }
}

//展示一天的销售额
double FamilyMart::show_turnover()
{
    //计算总销售额
    m_AllProfits += m_DaySell;
    this->UpdateFamilyMart();
    /*************************************************************************
    // cout << "Today' PurchaseCost is " << m_DayPay << "." << endl;
    // cout << "Today' SellMoney is " << m_DaySell << "." << endl;
    // cout << "Today' Profits is " << m_DaySell - m_DayPay << "." << endl;
    // cout << "All Profits since openning is " << m_AllProfits << "." << endl;
    **************************************************************************/
    return m_AllProfits;
}

//更新函数，更新当前日期，清理过期商品，该函数应在每天的售货完成后再使用。
void FamilyMart::UpdateFamilyMart()
{
    //储存平年和闰年的月份
    static int month[2][13] =
        {{9999999, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  //平年
         {9999999, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; //闰年

    //临时变量
    int tempmonth = NowDate[1] + 1;
    int tempday = NowDate[2] + 1;
    int leap = 0;

    //检查为平年还是闰年
    if ((NowDate[0] % 4 == 0 && NowDate[0] % 100 != 0) || (NowDate[0] % 400 == 0))
    {
        leap++;
    }

    if (tempday > month[leap][NowDate[1]]) // if要进月
    {
        if (tempmonth > 12) // if要进年
        {
            NowDate[0]++;
            NowDate[1] = 1;
            NowDate[2] = 1;
        }
        else // else不用进年
        {
            NowDate[1]++;
            NowDate[2] = 1;
        }
    }
    else // else不用进月
    {
        NowDate[2]++;
    }

    if (m_TypeNum < 0) // if程序运行错误给出提示
    {
        cout << "m_TypeNum error" << endl;
        system("Pause");
    }
    else if (m_TypeNum == 0) // else if库存为空直接返回
    {
        return;
    }
    else // else库存不为空
    {
        ListNode *temp = m_head;
        ListNode *temp1;

        //对库存中每种商品都进行更新
        while (temp != nullptr)
        {
            temp->m_productlist.UpdateProductList();
            temp = temp->next;
        }

        temp = m_head;
        temp1 = m_head;

        //下面的while语句主要是为了去掉商品数量为0的商品种类
        while (temp != nullptr)
        {
            if (temp->m_productlist.GetNum() <= 0) // if该种商品数量为0
            {
                if (temp->m_productlist.GetNum() < 0) // if程序运行错误给出提示
                {
                    cout << "m_productNum error" << endl;
                    system("Pause");
                }
                if (m_TypeNum == 1) // if库存中只有一种商品，则要额外初始化头尾指针
                {
                    delete temp;
                    m_TypeNum--;
                    m_head = nullptr;
                    m_tail = nullptr;
                    break;
                }
                else // else库存中不止一种商品
                {
                    if (temp == m_head) // if该种商品为头指针指向的商品种类
                    {
                        //额外对头指针进行操作
                        m_head = temp->next;
                        m_TypeNum--;
                        delete temp;
                        temp = m_head;
                        temp1 = m_head;
                    }
                    else if (temp == m_tail) // else if该种商品为尾指针指向的商品种类
                    {
                        //额外对尾指针进行操作
                        m_TypeNum--;
                        m_tail = temp1;
                        delete temp;
                        temp = m_tail->next = nullptr;
                    }
                    else // else 既不为头指针也不为尾指针指向的商品种类
                    {
                        //对temp进行操作
                        temp1->next = temp->next;
                        delete temp;
                        m_TypeNum--;
                        temp = temp1->next;
                    }
                }
            }
            else // else该种商品数量不为0
            {
                temp1 = temp;
                temp = temp->next;
            }
        }
    }
}
