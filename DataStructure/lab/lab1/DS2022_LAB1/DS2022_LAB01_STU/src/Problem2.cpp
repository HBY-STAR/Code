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
    if (head1 == nullptr)//
        return head2;
    else if (head2 == nullptr)//
        return head1;
    else//
    {
        PolynomialTerm *new_head, *temp, *temp1 = head1, *temp2 = head2;
        if (temp1->exponent == temp2->exponent)//
        {
            new_head = temp1;
            temp1->coefficient += temp2->coefficient;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->coefficient)//
        {
            new_head = temp1;
            temp1 = temp1->next;
        }
        else//
        {
            new_head = temp2;
            temp2 = temp2->next;
        }
        temp = new_head;
        while (temp1 != nullptr && temp2 != nullptr)//
        {
            if (temp1->exponent == temp2->exponent)//
            {
                temp->next = temp1;
                temp1->coefficient += temp2->coefficient;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->exponent > temp2->coefficient)//
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else//
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp=temp->next;
        }
        if(temp1==nullptr)//
        {
            temp->next=temp2;
        }
        else if(temp2==nullptr)//
        {
            temp->next=temp1;
        }
        return new_head;
    }
}

std::string Problem2::toString(PolynomialTerm *head)
{
    // TODO
    return "";
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