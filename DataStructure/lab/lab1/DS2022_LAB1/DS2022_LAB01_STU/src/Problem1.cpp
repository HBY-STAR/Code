//
// Created by huajuan on 2022/9/14.
//

#include "Problem1.h"

Node *Problem1::rearrangeNodes(Node *head)
{
    if (head == nullptr) //链表为空
    {
        return nullptr;
    }
    else
    {
        Node *p1, *p2, *temp, *temp_2; // p1为前指针，p2为后指针
        p1 = head;
        p2 = head->next;
        if (p2 == nullptr) //链表只有一个节点
        {
            return head;
        }
        else //链表至少有两个节点
        {
            // 找出中间节点

            //先求链表长度，找出中间位置
            int length = 0;
            while (p1 != nullptr)
            {
                length++;
                p1 = p1->next;
            }
            int mid = length / 2;

            //再让p1在中间节点靠前的位置，p2在中间节点靠后的位置，并翻转后面半条链
            p1 = head;
            for (int i = 1; i < mid; i++)
            {
                p1 = p1->next;
            }
            temp = p1->next;
            p1->next = nullptr;   //设置前面半条链的最后指向nullptr
            p1 = temp;            // p1在中间节点靠前的位置
            p2 = p1->next;        // p2在中间节点靠后的位置
            p1->next = nullptr;   //设置后面将要翻转的半条链的最后指向nullptr
            while (p2 != nullptr) //翻转后半条链表
            {
                temp = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = temp;
            }
            p2 = p1; //设置p2在后面一条已经翻转的链的头节点

            //设置p1在前面一条链的头节点
            p1 = head;
            while (p1 != nullptr && p2 != nullptr) //依次在前面的链中插入后面链的节点
            {
                temp = p1->next;
                p1->next = p2;
                temp_2 = p2->next;
                if (temp != nullptr)
                {
                    p2->next = temp;
                }
                p1 = temp;
                p2 = temp_2;
            }
            return head;
        }
    }
}
