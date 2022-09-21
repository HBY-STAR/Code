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
            // zhaochuzhongjianjiedian  kaoqianyige
            int length = 0;
            while (p1 != nullptr)
            {
                length++;
                p1 = p1->next;
            }
            int mid = length / 2;
            p1 = head;
            for (int i = 1; i < mid; i++)
            {
                p1 = p1->next;
            }
            temp = p1->next;
            p1->next = nullptr;
            p1 = temp;
            p2 = p1->next;
            p1->next = nullptr;
            while (p2 != nullptr)
            {
                temp = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = temp;
            }
            p2 = p1;
            p1 = head;
            while (p1 != nullptr && p2 != nullptr)
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
