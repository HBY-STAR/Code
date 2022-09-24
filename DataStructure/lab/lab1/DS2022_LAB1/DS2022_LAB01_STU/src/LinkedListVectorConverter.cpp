//
// Created by huajuan on 2022/9/14.
//

//21302010042
//侯斌洋
//注：经测试，在Linux系统上是可以通过Problem1Test和Problem2Test测试的。若出现无法运行成功的情况可以直接联系我

#include "LinkedListVectorConverter.h"
#include "Node.h"

Node *LinkedListVectorConverter::toLinkedList(const std::vector<int> &v)
{
    Node *head = nullptr; //头节点
    Node *temp = nullptr;
    int length = v.size(); //获取链表长度
    if (length == 0)       //若链表为空
    {
        return head;
    }
    else //若链表不为空
    {
        head = new Node(v[0]);
        temp = head;
        for (int i = 1; i < length; i++)
        {
            temp->next = new Node(v[i]);
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
}

std::vector<int> LinkedListVectorConverter::toVector(Node *head)
{
    std::vector<int> v;
    Node *temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        v.insert(v.begin() + i, temp->data); //在vector中插入
        i++;
        temp = temp->next;
    }
    return v;
}