#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include "Node.h"

using namespace std;

class HuffmanTree
{
public:
    struct HuffmanNode
    {
        unsigned char ch;
        long num;
        bool isleaf;
        HuffmanNode *Lnode;
        HuffmanNode *Rnode;

        HuffmanNode(unsigned char Ch, long Num, bool Isleaf, HuffmanNode *lnode, HuffmanNode *rnode)
            : ch{Ch}, num{Num}, isleaf{false}, Lnode{lnode}, Rnode{rnode} {}
        HuffmanNode(unsigned char Ch, long Num, bool Isleaf, HuffmanNode *lnode, HuffmanNode *rnode)
            : ch{Ch}, num{Num}, isleaf{false}, Lnode{lnode}, Rnode{rnode} {}
    };
private:
    HuffmanNode *root;
    int LeafNum;

public:
    HuffmanTree();
    HuffmanTree(priority_queue<Node, vector<Node>, greater<Node>> &queue);
    ~HuffmanTree();
    HuffmanTree(const HuffmanTree &rhs);
    HuffmanTree &operator=(const HuffmanTree &rhs);
    priority_queue<Node> &GetChFreq(const string &file_name);
    void GetHuffmanCode();
};

#endif