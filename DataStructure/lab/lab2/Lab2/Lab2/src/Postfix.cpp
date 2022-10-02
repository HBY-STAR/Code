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
    int i = 0;
    string ret;
    Node<char> *temp;
    MyStack<char> ops(100000);
    while (infix[i] != '\0')
    {
        if (infix[i] == '*' || infix[i] == '/')
        {
            if (ops.peek() == nullptr || ops.peek()->val == '+' || ops.peek()->val == '-')
            {
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
            else
            {
                temp = ops.pop();
                ret += temp->val;
                delete temp;
            }
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            if (ops.peek() == nullptr)
            {
                temp = new Node<char>(infix[i]);
                ops.push(temp);
            }
            else
            {
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
        else
        {
            ret += infix[i];
        }
        i++;
    }
    return ret;
}
