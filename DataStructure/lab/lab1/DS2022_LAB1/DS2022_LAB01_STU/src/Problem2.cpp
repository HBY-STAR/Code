//
// Created by huajuan on 2022/9/15.
//
#include "Problem2.h"
#include <string>

PolynomialTerm *Problem2::addTerm(PolynomialTerm *head, int coefficient, int exponent)
{
    PolynomialTerm *temp;
    if (head == nullptr) //原链表为空
    {
        head = new PolynomialTerm(coefficient, exponent);
        head->next = nullptr;
    }
    else //原链表不为空
    {
        if (exponent >= head->exponent) //要进行头插或在头部合并同类项
        {
            if (exponent == head->exponent) //在头部合并同类项
            {
                head->coefficient += coefficient;
            }
            else //头插
            {
                temp = head->next;
                head->next = new PolynomialTerm(coefficient, exponent);
                head->next->next = temp;
                int swap_c = head->coefficient, swap_e = head->exponent;
                head->coefficient = head->next->coefficient;
                head->exponent = head->next->exponent;
                head->next->coefficient = swap_c;
                head->next->exponent = swap_e;
            }
        }
        else
        {
            temp = head;
            while (temp->next != nullptr && exponent < temp->next->exponent) //找插入位置
            {
                temp = temp->next;
            }
            if (temp->next == nullptr) //链表中没有比exponent小的项
            {
                temp->next = new PolynomialTerm(coefficient, exponent);
                temp->next->next = nullptr;
            }
            else if (exponent == temp->next->exponent) //链表中有与exponent相同的项
            {
                temp->next->coefficient += coefficient;
            }
            else //链表中有比exponent小的项且没有与exponent相同的项
            {
                PolynomialTerm *temp_2 = new PolynomialTerm(coefficient, exponent);
                temp_2->next = temp->next;
                temp->next = temp_2;
            }
        }
    }
    return head;
}

PolynomialTerm *Problem2::add(PolynomialTerm *head1, PolynomialTerm *head2)
{
    if (head1 == nullptr) //若head1位空
        return head2;
    else if (head2 == nullptr) //若head2为空
        return head1;
    else //若两条链都不为空
    {
        PolynomialTerm *new_head, *temp, *temp1 = head1, *temp2 = head2;
        if (temp1->exponent == temp2->exponent) //若两条链的头节点指数相同
        {
            new_head = new PolynomialTerm(temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent) //若head1的头节点大于head2
        {
            new_head = new PolynomialTerm(temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else //若head2的头节点大于head1
        {
            new_head = new PolynomialTerm(temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
        temp = new_head;
        while (temp1 != nullptr && temp2 != nullptr) //处理完头节点后开始循环进行
        {
            if (temp1->exponent == temp2->exponent) //若temp1节点指数大于temp2
            {
                temp->next = new PolynomialTerm(temp1->coefficient + temp2->coefficient, temp1->exponent);

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exponent > temp2->exponent) //若temp1节点指数小于temp2
            {
                temp->next = new PolynomialTerm(temp1->coefficient, temp1->exponent);
                temp1 = temp1->next;
            }
            else //若temp1节点指数等于temp2
            {
                temp->next = new PolynomialTerm(temp2->coefficient, temp2->exponent);
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        //之后处理剩余节点
        if (temp1 == nullptr) // head1空了，接上head2的节点
        {
            temp->next = temp2;
        }
        else if (temp2 == nullptr) // head2空了，接上head1的节点

        {
            temp->next = temp1;
        }
        return new_head;
    }
}

std::string Problem2::toString(PolynomialTerm *head)
{
    int count = 0, temp_count = 0;
    std::string str, temp_str;
    PolynomialTerm *temp = head;
    if (head == nullptr) //链表为空
    {
        return str;
    }
    else //链表不为空
    {
        while (temp != nullptr)
        {
            temp_count = 0;

            if (temp->coefficient == 0) //系数为0
            {
                temp = temp->next;
                continue;
            }
            else if (temp->coefficient > 0) //系数为正
            {
                if (temp->exponent == 0) //指数为0
                {
                    if (str == "") //在头节点
                    {
                        temp_str = std::to_string(temp->coefficient);
                    }
                    else //不在头结点
                    {
                        temp_str = "+" + std::to_string(temp->coefficient);
                    }
                }
                else if (temp->exponent == 1) //指数为1
                {
                    if (str == "") //在头节点
                    {
                        if (temp->coefficient == 1) //系数为1
                        {
                            temp_str = "x";
                        }
                        else //系数不为1
                        {
                            temp_str = std::to_string(temp->coefficient) + "x";
                        }
                    }
                    else //不在头节点
                    {
                        if (temp->coefficient == 1) //系数为1
                        {
                            temp_str = "+x";
                        }
                        else //系数不为1
                        {
                            temp_str = "+" + std::to_string(temp->coefficient) + "x";
                        }
                    }
                }
                else //指数不为0或1
                {
                    if (str == "") //在头节点
                    {
                        if (temp->coefficient == 1) //系数为1
                        {
                            temp_str = "x^" + std::to_string(temp->exponent);
                        }
                        else //系数不为1
                        {
                            temp_str = std::to_string(temp->coefficient) + "x^" + std::to_string(temp->exponent);
                        }
                    }
                    else //不在头节点
                    {
                        if (temp->coefficient == 1) //系数为1
                        {
                            temp_str = "+x^" + std::to_string(temp->exponent);
                        }
                        else //系数不为1
                        {
                            temp_str = "+" + std::to_string(temp->coefficient) + "x^" + std::to_string(temp->exponent);
                        }
                    }
                }
            }
            else //系数为负
            {
                if (temp->exponent == 0) //指数为0
                {
                    temp_str = std::to_string(temp->coefficient);
                }
                else if (temp->exponent == 1) //指数为1
                {
                    if (temp->coefficient == -1) //系数为-1
                    {
                        temp_str = "-x";
                    }
                    else //系数不为-1
                    {
                        temp_str = std::to_string(temp->coefficient) + "x";
                    }
                }
                else //指数不为0或1
                {
                    if (temp->coefficient == -1) //系数为-1
                    {
                        temp_str = "-x^" + std::to_string(temp->exponent);
                    }
                    else //系数不为-1
                    {
                        temp_str = std::to_string(temp->coefficient) + "x^" + std::to_string(temp->exponent);
                    }
                }
            }
            temp = temp->next;
            str = str + temp_str;
        }
        return str;
    }
}

void Problem2::free(PolynomialTerm *head)
{
    PolynomialTerm *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
