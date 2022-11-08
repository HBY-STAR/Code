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
    HuffmanTree(priority_queue<Node, vector<Node>, greater<Node>> &queue);
    ~HuffmanTree();
    HuffmanTree(const HuffmanTree &rhs);
    HuffmanTree &operator=(const HuffmanTree &rhs);
    void PostOrderDel();
    priority_queue<Node> &GetChFreq(const string &file_name);
    void GetHuffmanCode();
};

#endif