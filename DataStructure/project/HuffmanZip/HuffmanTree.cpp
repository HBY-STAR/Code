#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
    root = nullptr;
    LeafNum = 0;
}
HuffmanTree::HuffmanTree(priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> &queue)
{
    LeafNum = queue.size();
    if (LeafNum == 0)
    {
        root = nullptr;
    }
    else if (Leaf == 1)
    {
        root = new HuffmanNode(queue.top());
        queue.pop();
    }
    else
    {
        HuffmanNode *temp, *temp1, *temp2;
        while (queue.size() >= 2)
        {
            temp1 = new HuffmanNode(queue.top());
            queue.pop();
            temp2 = new HuffmanNode(queue.top());
            queue.pop();
            temp = new HuffmanNode(temp1->ch, temp1->num + temp2->num, false, temp1, temp2);
            queue.push(*temp);
        }
        root = temp;
    }
}
HuffmanTree::~HuffmanTree()
{
    PostOrderDel(root);
}
HuffmanTree::HuffmanTree(const HuffmanTree &rhs)
{
    LeafNum = rhs.LeafNum;
    PostOrderCopy(rhs.root);
}
HuffmanTree &HuffmanTree::operator=(const HuffmanTree &rhs)
{
    if (rhs == this)
    {
        return this;
    }
    else
    {
        LeafNum = rhs.LeafNum;
        PostOrderCopy(rhs.root);
    }
}

void HuffmanTree::PostOrderDel(HuffmanNode *node)
{
    if (node != nullptr)
    {
        PostOrderDel(node->Lnode);
        PostOrderDel(node->Rnode);
        delete node;
    }
}

HuffmanNode *HuffmanTree::PostOrderCopy(const HuffmanNode *rhs_node)
{
    if (rhs_node != nullptr)
    {
        HuffmanNode *temp, temp1, temp2;
        temp1 = PostOrderCopy(rhs_node->Lnode);
        temp2 = PostOrderCopy(rhs_node->Rnode);
        temp = new HuffmanNode(rhs_node->ch, rhs_node->num, rhs_node->Isleaf, temp1, temp2);
    }
    else
    {
        return nullptr;
    }
}
priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> &GetChFreq(const string &file_name)
{
    ifstream input;
    input.open(file_name);

    long array[MaxCharNum] = {0};
    unsigned char ch;
    HuffmanNode temp;
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> p_queue;

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
            temp.Isleaf = true;
            temp.Lnode = nullptr;
            temp.Rnode = nullptr;
            p_queue.push(temp);
        }
    }
    return p_queue;
}