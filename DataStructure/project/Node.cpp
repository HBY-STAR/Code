#include "Node.h"

Node::Node()
{
    ch = 0;
    num = 0;
}

Node::Node(unsigned char c, long n)
{
    ch = c;
    num = n
}

Node::~Node()
{
    ;
}

Node::Node(const Node &rhs)
{
    ch = rhs.ch;
    num = rhs.ch;
}

Node::Node &operator=(const Node &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    ch = rhs.ch;
    num = rhs.ch;
}

bool Node::operator==(const Node &rhs)
{
    return num == rhs.num;
}

bool Node::operator>=(const Node &rhs)
{
    return num >= rhs.num;
}

bool Node::operator<=(const Node &rhs)
{
    return num <= rhs.num;
}

bool Node::operator>(const Node &rhs)
{
    return num > rhs.num;
}

bool Node::operator<(const Node &rhs)
{
    return num < rhs.num;
}