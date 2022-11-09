#include <iostream>
#include <cstdlib>
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

    // string post_fix = file_name.substr(file_name.rfind('.'));
    long str_bytes = file_name.size();
    output.write((char *)&str_bytes, sizeof(str_bytes));
    output << file_name;
    HuffmanNode tempnode;
    long code_bytes = save_code.size();
    output.write((char *)&code_bytes, sizeof(code_bytes));
    while (!save_code.empty())
    {
        tempnode = save_code.top();
        save_code.pop();
        output.write((char *)&tempnode.ch, sizeof(tempnode.ch));
        output.write((char *)&tempnode.num, sizeof(tempnode.num));
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
                output.write((char *)&bit_ch, sizeof(bit_ch));
                bit_count = 0;
            }
        }
    }
    if (bit_count > 0 && bit_count < 8)
    {
        bit_ch <<= (8 - bit_count);
        output.write((char *)&bit_ch, sizeof(bit_ch));
    }
    output << EOF;
    input.close();
    output.close();
}

void FileUncompress(const string &zip_name)
{
    ifstream input;
    ofstream output;

    string post_fix = zip_name.substr(zip_name.rfind('.'));
    if (post_fix == ".hby")
    {
        input.open(zip_name, ios::in);
        string file_name;
        unsigned char file_ch = 0;
        long str_bytes;
        input.read((char *)&str_bytes, sizeof(str_bytes));
        for (int i = 0; i < str_bytes; i++)
        {
            input.read((char *)&file_ch, sizeof(file_ch));
            ;
            file_name += file_ch;
        }
        output.open("(1)" + file_name, ios::out);

        long code_bytes;
        unsigned char ch = 0;
        long num = 0;
        long array[MaxCharNum] = {0};
        HuffmanNode temp;
        priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> p_queue;

        input.read((char *)&code_bytes, sizeof(code_bytes));
        for (long i = 0; i < code_bytes; i++)
        {
            input.read((char *)&ch, sizeof(ch));
            input.read((char *)&num, sizeof(num));
            array[ch] = num;
        }
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

        HuffmanTree tree = HuffmanTree(p_queue);
        unsigned char bit_ch = 0;
        unsigned char first_bit = 128; // 0b10000000
        int bit_count = 0;
        HuffmanNode *find_leaf = tree.GetRoot();
        while (!input.eof())
        {
            input >> bit_ch;
            while (bit_count != 8)
            {
                while (!(find_leaf->Isleaf))
                {
                    if ((first_bit & bit_ch) == first_bit)
                    {
                        find_leaf = find_leaf->Rnode;
                        bit_ch <<= 1;
                        bit_count++;
                    }
                    else
                    {
                        find_leaf = find_leaf->Lnode;
                        bit_ch <<= 1;
                        bit_count++;
                    }
                    if (find_leaf == nullptr)
                    {
                        break;
                    }
                }
                if (find_leaf == nullptr)
                {
                    break;
                }
                output << find_leaf->ch;
                find_leaf = tree.GetRoot();
            }
            bit_count = 0;
        }
        input.close();
        output.close();
    }
    else
    {
        cout << zip_name << " is not the right file." << endl;
        system("pause");
    }
}
