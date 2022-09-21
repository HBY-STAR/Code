//
// Created by huajuan on 2022/9/14.
//
#include "LinkedListVectorConverter.h"
#include "Node.h"

Node *LinkedListVectorConverter::toLinkedList(const std::vector<int> &v)
{
    Node *head = nullptr;
    Node *temp = nullptr;
    int length = v.size();
    if (length == 0)
    {
        return head;
    }
    else
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
        v.insert(v.begin() + i, temp->data);
        i++;
        temp = temp->next;
    }
    return v;
}