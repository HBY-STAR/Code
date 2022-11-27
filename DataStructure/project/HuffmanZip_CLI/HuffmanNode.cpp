#include"HuffmanNode.h"

//重载比较运算符
bool HuffmanNode::operator==(const HuffmanNode &rhs) const
{
    return num == rhs.num;
}

bool HuffmanNode::operator>=(const HuffmanNode &rhs) const
{
    return num >= rhs.num;
}

bool HuffmanNode::operator<=(const HuffmanNode &rhs) const
{
    return num <= rhs.num;
}

bool HuffmanNode::operator>(const HuffmanNode &rhs) const
{
    return num > rhs.num;
}

bool HuffmanNode::operator<(const HuffmanNode &rhs) const
{
    return num < rhs.num;
}