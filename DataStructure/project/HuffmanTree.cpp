#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
    root=nullptr;
    LeafNum=0;
}
HuffmanTree::HuffmanTree(priority_queue<Node> &queue)
{
}
HuffmanTree::~HuffManTree()
{
}
HuffmanTree::HuffmanTree(const HuffmanTree &rhs)
{
}
HuffmanTree::HuffmanTree &operator=(const HuffmanTree &rhs)
{
}

priority_queue<Node> &GetChFreq(const string &file_name)
{
    ifstream input;
    input.open(file_name);

    long array[MaxCharNum] = {0};
    unsigned char ch;
    Node temp;
    priority_queue<Node, vector<Node>, greater<Node>> p_queue;

    while (!input.eof())
    {
        input >> ch;
        array[ch]++;
    }
    for (unsigned int i = 0; i < MaxCharNum; i++)
    {
        if (array[i] != 0)
        {
            temp.ch = unsigned char(i);
            temp.num = array[i];
            p_queue.push(temp);
        }
    }
    return p_queue;
}