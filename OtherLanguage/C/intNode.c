/***********************此程序完成int类型值链表的创建以及增删改查***********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct intNode
{
    int val;
    struct intNode *next;
};

//函数声明
void print_intnode(struct intNode *list);
void add_to_end(struct intNode **list, int num);
void add_to_first(struct intNode **list, int num);
void add_after_num(struct intNode *list, int num1, int num2);
void add_before_num(struct intNode *list, int num1, int num2);
void del_first_num(struct intNode **list);
void del_last_num(struct intNode **list);
void del_assigned_num(struct intNode **list, int num);
void change_assinged_num(struct intNode *list, int num1, int num2);
void travel(struct intNode *list, int num);
void reverse(struct intNode **list);

//主函数
int main(void)
{
    struct intNode *head = NULL;
    struct intNode *pre;
    char ch;
    int temp;
    system("CLS");
    printf("请输入一行以空格隔开的整数作为初始链表，按ENTER键结束键入。\n");
    do
    {
        scanf("%d", &temp);
        struct intNode *cur = (struct intNode *)malloc(sizeof(struct intNode));
        if (head == NULL)
        {
            head = cur;
        }
        else
        {
            pre->next = cur;
        }
        cur->val = temp;
        cur->next = NULL;
        pre = cur;
    } while ((ch = getchar()) != '\n');
    printf("初始链表如下：\n");
    print_intnode(head);
    printf("颠倒链表如下：\n");
    reverse(&head);
    print_intnode(head);
    system("pause");
    return 0;
}

//显示链表中数据的函数
void print_intnode(struct intNode *list)
{
    struct intNode *temp = list;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

//在链表末尾增加一个表元的函数
void add_to_end(struct intNode **list, int num)
{
    struct intNode *pre = *list;
    struct intNode *cur = (struct intNode *)malloc(sizeof(struct intNode));
    if (*list == NULL)
    {
        *list = cur;
        cur->val = num;
        cur->next = NULL;
    }
    else
    {
        while (pre->next != NULL)
        {
            pre = pre->next;
        }
        pre->next = cur;
        cur->val = num;
        cur->next = NULL;
    }
}

//在链表的最前面增加一个表元的函数
void add_to_first(struct intNode **list, int num)
{
    struct intNode *cur = (struct intNode *)malloc(sizeof(struct intNode));
    cur->val = num;
    cur->next = *list;
    *list = cur;
}

//在链表的某个数后增加一个表元的函数
void add_after_num(struct intNode *list, int num1, int num2)
{
    struct intNode *pre = list;
    struct intNode *cur = (struct intNode *)malloc(sizeof(struct intNode));
    while (pre != NULL && pre->val != num1)
    {
        pre = pre->next;
    }
    if (pre == NULL)
    {
        printf("在链表中找不到这个数字。\n");
    }
    else
    {
        cur->next = pre->next;
        cur->val = num2;
        pre->next = cur;
    }
}

//在链表的某个数前增加一个表元的函数
void add_before_num(struct intNode *list, int num1, int num2)
{
    struct intNode *dummy = (struct intNode *)malloc(sizeof(struct intNode));
    dummy->next = list;
    dummy->val = 0;
    struct intNode *pre = dummy;
    struct intNode *cur = (struct intNode *)malloc(sizeof(struct intNode));
    while (pre->next != NULL && pre->next->val != num1)
    {
        pre = pre->next;
    }
    if (pre->next == NULL)
    {
        printf("在链表中找不到这个数字。\n");
        free(dummy);
    }
    else
    {
        cur->next = pre->next;
        cur->val = num2;
        pre->next = cur;
        free(dummy);
    }
}

//在链表中删除最前面的表元的函数
void del_first_num(struct intNode **list)
{
    struct intNode *temp;
    if (*list == NULL)
    {
        printf("空链表，操作无效。\n");
    }
    else
    {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

//在链表中删除最后面表元的函数
void del_last_num(struct intNode **list)
{
    struct intNode *temp = *list;
    if (*list == NULL)
    {
        printf("空链表，操作无效。\n");
    }
    else if (temp->next == NULL)
    {
        *list == NULL;
        free(temp);
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//在链表中删除某个数的函数
void del_assigned_num(struct intNode **list, int num)
{
    struct intNode *pre = *list;
    struct intNode *cur;
    if (*list == NULL)
    {
        printf("空链表，操作无效。\n");
    }
    else
    {
        while (pre->next != NULL && pre->next->val != num)
        {
            pre = pre->next;
        }
        cur = pre->next;
        if (cur == NULL)
        {
            if (pre->val == num)
            {
                *list = NULL;
                free(pre);
            }
            else
            {
                printf("在链表中找不到该数字。\n");
            }
        }
        else
        {
            pre->next = cur->next;
            free(cur);
        }
    }
}

//在链表中修改某个数的值的函数
void change_assigned_num(struct intNode *list, int num1, int num2)
{
    struct intNode *temp = list;
    if (list == NULL)
    {
        printf("空链表，操作无效。\n");
    }
    else
    {
        while (temp != NULL && temp->val != num1)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("在链表中找不到此数。\n");
        }
        else
        {
            temp->val = num2;
        }
    }
}

//遍历链表，判断链表中是否含有某个数
void travel(struct intNode *list, int num)
{
    struct intNode *temp = list;
    while (temp != NULL && temp->val != num)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("在链表中不存在这个数。\n");
    }
    else
    {
        printf("在链表中存在此数。\n");
    }
}

//颠倒链表函数
void reverse(struct intNode **list)
{
    struct intNode *pre, *cur, *temp;
    pre=NULL;
    cur=*list;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    *list=pre;
}