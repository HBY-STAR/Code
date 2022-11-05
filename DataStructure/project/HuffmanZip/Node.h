#ifndef NODE_H
#define NODE_H

const int MaxCharNum = 256;

struct Node
{
    unsigned char ch;
    long num;

    Node();
    Node(unsigned char c, long n);
    ~Node();
    Node(const Node &rhs);
    Node &operator=(const Node &rhs);
    bool operator==(const Node &rhs);
    bool operator>=(const Node &rhs);
    bool operator<=(const Node &rhs);
    bool operator>(const Node &rhs);
    bool operator<(const Node &rhs);
};

#endif