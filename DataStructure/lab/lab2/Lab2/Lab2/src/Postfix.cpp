//
// Created by yixin on 2022/9/25.
//
#include <iostream>
#include "MyStack.cpp"

using namespace std;

/**
 * @brief Converts infix to postfix, only need '*' '/' '+' '-', does not need '(', ')'.
 * @return Postfix
 * */
static string postfix(string infix)
{
    int i = 0;                 //计数器
    string ret;                //存储要返回的字符串
    Node<char> *temp;          //临时指针
    MyStack<char> ops(100000); //存储操作符的栈的大小
    while (infix[i] != '\0')
    {
        if (infix[i] == '*' || infix[i] == '/') //若检测到操作符且为*或/
        {
            if (ops.peek() == nullptr || ops.peek()->val == '+' || ops.peek()->val == '-') //若栈的头操作符不为*或/
            {
                //直接进栈
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
            else //若栈的头操作符为*或/
            {
                //先弹出栈的头操作符再让本操作符进栈，这样保证了栈中一直没有两个连续的*或/操作符
                temp = ops.pop();
                ret += temp->val;
                delete temp;
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
        }
        else if (infix[i] == '+' || infix[i] == '-') //若检测到操作符且为+或-
        {
            if (ops.peek() == nullptr) //若栈为空
            {
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
            else //若栈不为空
            {
                //弹出栈中所有操作符然后再把当前操作符插入
                while (ops.peek() != nullptr)
                {
                    temp = ops.pop();
                    ret += temp->val;
                    delete temp;
                }
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
        }
        else //若检测到操作数直接输出
        {
            ret += infix[i];
        }
        i++;
    }
    //弹出栈中剩余的指针
    while (ops.peek() != nullptr)
    {
        temp = ops.pop();
        ret += temp->val;
        delete temp;
    }
    return ret;
}
