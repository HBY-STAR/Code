#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    else
    {
        ListNode *new_head;
        ListNode *p1, *p2, *temp; // p1为前指针，p2为后指针
        p1 = head;
        p2 = head->next;
        if (p2 == nullptr)
        {
            new_head = head;
            return new_head;
        }
        else
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

int main()
{
    ListNode list1(1);
    ListNode list2(2);
    ListNode list3(3);
    ListNode list4(4);
    ListNode list5(5);
    ListNode *list = &list1;
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list5;
    list5.next=nullptr;
    ListNode*new_head=reverseList(list);

    return 0;
}