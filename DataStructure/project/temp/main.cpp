#include <iostream>
#include <cstdlib>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

int main()
{
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> queue;
    HuffmanNode letter[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> letter[i].ch;
        cin >> letter[i].num;
        letter[i].Isleaf = true;
        queue.push(letter[i]);
    }
    HuffmanTree tree = HuffmanTree(queue);
    vector<HuffmanCode> code = tree.GetHuffmanCode();
    for (int i = 0; i < 256; i++)
    {
        cout << code[i].ch << '\t' << code[i].code << endl;
    }
    system("pause");
    return 0;
}