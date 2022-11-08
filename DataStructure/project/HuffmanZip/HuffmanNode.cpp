#include "HuffmanNode.h"

bool HuffmanNode::operator==(const HuffmanNode &rhs)
{
    return num == rhs.num;
}

bool HuffmanNode::operator>=(const HuffmanNode &rhs)
{
    return num >= rhs.num;
}

bool HuffmanNode::operator<=(const HuffmanNode &rhs)
{
    return num <= rhs.num;
}

bool HuffmanNode::operator>(const HuffmanNode &rhs)
{
    return num > rhs.num;
}

bool HuffmanNode::operator<(const HuffmanNode &rhs)
{
    return num < rhs.num;
}