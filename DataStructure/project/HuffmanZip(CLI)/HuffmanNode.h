#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

//定义字符集最大种类数为256
const int MaxCharNum = 256;

//定义哈夫曼树的节点
struct HuffmanNode
{
    long num;
    unsigned char ch;
    bool Isleaf;
    HuffmanNode *Lnode;
    HuffmanNode *Rnode;

    HuffmanNode()
        : ch{0}, num{0}, Isleaf{false}, Lnode{nullptr}, Rnode{nullptr} {}
    HuffmanNode(unsigned char Ch, long Num, bool isleaf, HuffmanNode *lnode, HuffmanNode *rnode)
        : ch{Ch}, num{Num}, Isleaf{isleaf}, Lnode{lnode}, Rnode{rnode} {}
    bool operator==(const HuffmanNode &rhs) const;
    bool operator>=(const HuffmanNode &rhs) const;
    bool operator<=(const HuffmanNode &rhs) const;
    bool operator>(const HuffmanNode &rhs) const;
    bool operator<(const HuffmanNode &rhs) const;
};

#endif