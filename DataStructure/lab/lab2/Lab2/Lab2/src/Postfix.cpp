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
static string postfix(string infix) {
    int i=0;
    string ret;
    while(infix[i]!='\0')
    {
        if(infix[i]=='*'||infix[i]=='/')
        {
            
        }


        i++;
    }

    return "";
}
