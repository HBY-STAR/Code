#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "Functions.h"
#include "HuffmanNode.h"
#include "HuffmanTree.h"

namespace fs = std::filesystem;
using namespace std;

priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>>
GetChFreq(const fs::path &file_path, long *file_size)
{
    ifstream input;
    input.open(file_path, ios::in | ios::binary);

    long array[MaxCharNum] = {0};
    long size = 0;
    unsigned char ch;
    HuffmanNode temp;
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> p_queue;

    while (1)
    {
        input.read((char *)&ch, sizeof(ch));
        if (input.eof())
        {
            break;
        }
        array[ch]++;
        size++;
    }
    *file_size = size;
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

void FileCompress(const fs::path &file_path, const fs::path &zip_path)
{
    ifstream input;
    ofstream output;
    input.open(file_path, ios::in | ios::binary);
    output.open(zip_path, ios::out | ios::binary);
    long file_size = 0;

    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> queue = GetChFreq(file_path, &file_size);
    priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> save_code = queue;
    HuffmanTree tree = HuffmanTree(queue);
    vector<HuffmanCode> huffman_code(MaxCharNum);
    huffman_code = tree.GetHuffmanCode();
    /*
    for (int i = 0; i < MaxCharNum; i++)
    {
        if (huffman_code[i].code.size() != 0)
        {
            cout << huffman_code[i].ch << '\t' << ":" << huffman_code[i].code << endl;
        }
    }
    */

    // string post_fix = file_name.substr(file_name.rfind('.'));
    string file_str_name = file_path.filename().string();
    long str_bytes = file_str_name.size();
    output.write((char *)&file_size, sizeof(file_size));
    output.write((char *)&str_bytes, sizeof(str_bytes));
    output << file_str_name;
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
    while (1)
    {
        input.read((char *)&ch, sizeof(ch));
        if (input.eof())
        {
            break;
        }
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
    input.close();
    output.close();
}

void FileUncompress(const fs::path &zip_path, const fs::path &folder_path)
{
    ifstream input;
    ofstream output;

    string zip_str_name = zip_path.filename().string();
    string post_fix = zip_str_name.substr(zip_str_name.rfind('.'));
    if (post_fix == ".hby")
    {
        input.open(zip_path, ios::in | ios::binary);
        long file_size = 0;
        string file_name;
        unsigned char file_ch = 0;
        long str_bytes;
        input.read((char *)&file_size, sizeof(file_size));
        input.read((char *)&str_bytes, sizeof(str_bytes));
        for (int i = 0; i < str_bytes; i++)
        {
            input.read((char *)&file_ch, sizeof(file_ch));
            ;
            file_name += file_ch;
        }
        file_name = "(1)" + file_name;
        fs::path file_path = folder_path / file_name;
        output.open(file_path, ios::out | ios::binary);

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
        long bytes_count = 0;
        HuffmanNode *find_leaf = tree.GetRoot();
        while (1)
        {
            input.read((char *)&bit_ch, sizeof(bit_ch));
            if (input.eof())
            {
                break;
            }
            while (bit_count < 8)
            {
                while ((!(find_leaf->Isleaf)) && (bit_count < 8))
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
                if (find_leaf == nullptr || file_size == bytes_count)
                {
                    break;
                }
                if ((find_leaf->Isleaf) && (file_size != bytes_count))
                {
                    output << find_leaf->ch;
                    bytes_count++;
                    find_leaf = tree.GetRoot();
                }
            }
            bit_count = 0;
        }
        input.close();
        output.close();
    }
    else
    {
        cout << zip_path << " is not the right file." << endl;
        system("pause");
    }
}

void FolderCompress(const fs::path &folder_path, const fs::path &zip_path)
{
    if (!fs::exists(folder_path))
    {
        cout << "There is no folder in path: " << folder_path.string() << endl;
        system("pause");
    }
    if (!fs::exists(zip_path))
    {
        fs::create_directory(zip_path);
    }
    for (const fs::directory_entry &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_block_file())
        {
            continue;
        }
        else if (entry.is_regular_file())
        {
            fs::path dst = folder_path / entry.path().filename().replace_extension("hby");
            // cout << dst.string() << endl;
            FileCompress(entry.path(), dst);
        }
        else if (entry.is_directory())
        {
            fs::path dst = folder_path / entry.path().filename().replace_extension("hby1");
            FolderCompress(entry.path(), dst);
        }
    }
    for (const fs::directory_entry &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_block_file())
        {
            fs::path toPath(zip_path / entry.path().filename());
            fs::copy(entry.path(), toPath);
        }
        else if (entry.is_regular_file() && entry.path().extension() == ".hby")
        {
            fs::path toPath(zip_path / entry.path().filename());
            cout << toPath.string() << endl;
            fs::rename(entry.path(), toPath);
        }
        else if (entry.is_directory() && entry.path().extension() == ".hby1")
        {
            fs::path toPath(zip_path / entry.path().filename());
            cout << toPath.string() << endl;
            fs::rename(entry.path(), toPath);
        }
    }
}
void FolderUncompress(const fs::path &zip_path, const fs::path &folder_path)
{
    if (!fs::exists(zip_path))
    {
        cout << "There is no right file in path: " << folder_path.string() << endl;
        system("pause");
    }
    if (!fs::exists(folder_path))
    {
        fs::create_directory(folder_path);
    }
    for (const fs::directory_entry &entry : fs::directory_iterator(zip_path))
    {
        if (entry.is_block_file())
        {
            continue;
        }
        else if (entry.is_regular_file() && entry.path().extension() == ".hby")
        {
            // cout << dst.string() << endl;
            FileUncompress(entry.path(), zip_path);
        }
        else if (entry.is_directory() && entry.path().extension() == ".hby1")
        {
            fs::path dst = zip_path / entry.path().filename().replace_extension("");
            FolderUncompress(entry.path(), dst);
        }
    }
    for (const fs::directory_entry &entry : fs::directory_iterator(zip_path))
    {
        if (entry.is_block_file())
        {
            fs::path toPath(folder_path / entry.path().filename());
            fs::copy(entry.path(), toPath);
        }
        else if (entry.is_regular_file() && entry.path().extension() != ".hby")
        {
            fs::path toPath(folder_path / entry.path().filename());
            cout << toPath.string() << endl;
            fs::rename(entry.path(), toPath);
        }
        else if (entry.is_directory() && entry.path().extension() != ".hby1")
        {
            fs::path toPath(folder_path / entry.path().filename());
            cout << toPath.string() << endl;
            fs::rename(entry.path(), toPath);
        }
    }
}