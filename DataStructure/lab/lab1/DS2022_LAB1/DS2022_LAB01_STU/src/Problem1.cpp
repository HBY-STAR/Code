//
// Created by huajuan on 2022/9/14.
//

#include "Problem1.h"

Node *Problem1::rearrangeNodes(Node *head)
{
    if (head == nullptr)//链表为空
    {
        return nullptr;
    }
    else
    {
        Node *new_head;
        Node *p1, *p2, *temp; // p1为前指针，p2为后指针
        p1 = head;
        p2 = head->next;
        if (p2 == nullptr)//链表只有一个节点
        {
            new_head = head;
            return new_head;
        }
        else//链表至少有两个节点
        {
            p1->next = nullptr;
            while (p2 != nullptr)
            {
                temp = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = temp;
            }
            new_head = p1;
            return new_head;
        }
    }
}
