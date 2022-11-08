#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include "HuffmanNode.h"

using namespace std;

class HuffmanTree
{
private:
    HuffmanNode *root;
    int LeafNum;

public:
    HuffmanTree();
    HuffmanTree(priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> &queue);
    ~HuffmanTree();
    HuffmanTree(const HuffmanTree &rhs);
    HuffmanTree &operator=(const HuffmanTree &rhs);
    void PostOrderDel(HuffmanNode *node);
    HuffmanNode *PostOrderCopy(const HuffmanNode *rhs_node);
    priority_queue<HuffmanNode> GetChFreq(const string &file_name);
    void GetHuffmanCode();
};

#endif