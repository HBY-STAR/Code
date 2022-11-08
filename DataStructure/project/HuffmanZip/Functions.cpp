#include "Functions.h"
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> GetChFreq(const string &file_name)
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
    array[ch]--;
    for (unsigned int i = 0; i < MaxCharNum; i++)
    {
        if (array[i] != 0)
        {
            temp.ch = i;
            temp.num = array[i];
            temp.Isleaf = true;
            temp.Lnode = nullptr;
            temp.Rnode = nullptr;
            p_queue.push(temp);
        }
    }
    input.close();
    return p_queue;
}

void FileCompress(const string &file_name, const string &zip_name)
{
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> queue = GetChFreq(file_name);
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> save_code = queue;
    HuffmanTree tree = HuffmanTree(queue);
    vector<HuffmanCode> huffman_code(MaxCharNum);
    huffman_code = tree.GetHuffmanCode();

    ifstream input;
    ofstream output;
    input.open(file_name, ios::in);
    output.open(zip_name, ios::out);

    string post_fix = file_name.substr(file_name.rfind('.'));
    output << post_fix;
    HuffmanNode tempnode;
    long code_bytes = 9 * save_code.size();
    output << code_bytes;
    while (!save_code.empty())
    {
        tempnode = save_code.top();
        save_code.pop();
        output << tempnode.ch;
        output << tempnode.num;
    }

    unsigned char ch = 0;
    unsigned char bit_ch = 0;
    int bit_count = 0;
    while (!input.eof())
    {
        input >> ch;
        string &code = huffman_code[ch].code;
        for (int i = 0; i < code.size(); i++)
        {
            bit_ch <<= 1;
            if (code[i] == '1')
            {
                bit_ch |= 1;
            }
            bit_count++;
            if (bit_count == 8)
            {
                output << bit_ch;
                bit_count = 0;
            }
        }
    }
    if (bit_count > 0 && bit_count < 8)
    {
        bit_ch <<= (8 - bit_count);
        output << bit_ch;
    }
    input.close();
    output.close();
}
