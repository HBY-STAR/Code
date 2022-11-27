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
        string file_name = "";
        unsigned char file_ch = 0;
        long str_bytes;
        input.read((char *)&file_size, sizeof(file_size));
        input.read((char *)&str_bytes, sizeof(str_bytes));
        for (int i = 0; i < str_bytes; i++)
        {
            input.read((char *)&file_ch, sizeof(file_ch));
            file_name += file_ch;
        }
        fs::path file_path = folder_path.string() + '/' + file_name;
        cout << file_path.string();
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

void inFolderCompressTravelDir(const fs::path &folder_path, ofstream &output)
{
    static int file_str_bytes = 0;
    static string tempstr = "";
    static int folder_tag = 0;
    static int right = -1;

    folder_tag = 1;
    tempstr = folder_path.filename().string();
    file_str_bytes = tempstr.size();
    output.write((char *)&folder_tag, sizeof(file_str_bytes));
    output.write((char *)&file_str_bytes, sizeof(file_str_bytes));
    output << tempstr;

    for (const fs::directory_entry &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_directory())
        {
            inFolderCompressTravelDir(entry.path(), output);
        }
        else
        {
            folder_tag = 0;
            tempstr = entry.path().filename().string();
            file_str_bytes = tempstr.size();
            output.write((char *)&folder_tag, sizeof(file_str_bytes));
            output.write((char *)&file_str_bytes, sizeof(file_str_bytes));
            output << tempstr;
        }
    }
    output.write((char *)&right, sizeof(right));
}

void inFolderCompressFile(const fs::path &file_path, ofstream &output)
{
    ifstream input;
    input.open(file_path, ios::in | ios::binary);
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
    output.write((char *)&file_size, sizeof(file_size));

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
}

void inFolderCompressDir(const fs::path &folder_path, ofstream &output)
{
    for (const fs::directory_entry &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_directory())
        {
            inFolderCompressDir(entry.path(), output);
        }
        else
        {
            inFolderCompressFile(entry.path(), output);
        }
    }
}

void FolderCompress(const fs::path &folder_path, const fs::path &zip_path)
{
    ofstream output;
    output.open(zip_path);

    long FolderTag = -1;
    output.write((char *)&FolderTag, sizeof(FolderTag));

    inFolderCompressTravelDir(folder_path, output);

    int right = -1;
    output.write((char *)&right, sizeof(right));

    inFolderCompressDir(folder_path, output);

    output.close();
}

void inFolderUncompressTravelDir(ifstream &input, const fs::path &folder_path)
{
    static int file_str_bytes = 0;
    static unsigned char tempch = 0;
    static int folder_tag = 0;

    input.read((char *)&folder_tag, sizeof(folder_tag));

    while (folder_tag != -1)
    {
        if (folder_tag == 0)
        {
            string file_str;
            input.read((char *)&file_str_bytes, sizeof(file_str_bytes));
            for (int i = 0; i < file_str_bytes; i++)
            {
                input.read((char *)&tempch, sizeof(tempch));
                file_str += tempch;
            }
            fs::path new_file(folder_path / file_str);
            fstream file(new_file, ios::out | ios::trunc);
            file.close();
        }
        else if (folder_tag == 1)
        {
            string folder_str;
            input.read((char *)&file_str_bytes, sizeof(file_str_bytes));
            for (int i = 0; i < file_str_bytes; i++)
            {
                input.read((char *)&tempch, sizeof(tempch));
                folder_str += tempch;
            }
            fs::path new_folder(folder_path / folder_str);
            fs::create_directory(new_folder);
            inFolderUncompressTravelDir(input, new_folder);
        }
        input.read((char *)&folder_tag, sizeof(folder_tag));
    }
}

void inFolderUncompressFile(ifstream &input, const fs::path &file_path)
{
    ofstream output;
    output.open(file_path, ios::out | ios::binary);

    long file_size = 0;
    input.read((char *)&file_size, sizeof(file_size));

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

    while (file_size != bytes_count)
    {
        input.read((char *)&bit_ch, sizeof(bit_ch));
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
    output.close();
}

void inFolderUncompressDir(ifstream &input, const fs::path &folder_path)
{
    for (const fs::directory_entry &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_directory())
        {
            inFolderUncompressDir(input, entry.path());
        }
        else
        {
            inFolderUncompressFile(input, entry.path());
        }
    }
}

void FolderUncompress(const fs::path &zip_path, const fs::path &folder_path)
{
    ifstream input;
    input.open(zip_path);

    string new_folder = "";
    unsigned char tempch;
    int new_folder_str_bytes;

    input.seekg(sizeof(long) + sizeof(int), ios::beg);

    input.read((char *)&new_folder_str_bytes, sizeof(new_folder_str_bytes));
    for (int i = 0; i < new_folder_str_bytes; i++)
    {
        input.read((char *)&tempch, sizeof(tempch));
        new_folder += tempch;
    }
    fs::path new_folder_path(folder_path / new_folder);

    input.seekg(sizeof(long), ios::beg);

    inFolderUncompressTravelDir(input, folder_path);

    inFolderUncompressDir(input, new_folder_path);

    input.close();
}

void Uncompress(const fs::path &zip_path, const fs::path &folder_path)
{
    ifstream input;
    input.open(zip_path);
    long FolderTag = 0;
    input.read((char *)&FolderTag, sizeof(FolderTag));
    input.close();
    if (FolderTag == -1)
    {
        FolderUncompress(zip_path, folder_path);
    }
    else
    {
        FileUncompress(zip_path, folder_path);
    }
}

void inFolderPreviewTravel(ifstream &input, string &preview_graph)
{
    static int file_str_bytes = 0;
    static unsigned char tempch = 0;
    static int folder_tag = 0;
    static int level = 0;
    static bool first = true;

    input.read((char *)&folder_tag, sizeof(folder_tag));

    while (folder_tag != -1)
    {
        if (folder_tag == 0)
        {
            string file_str;
            input.read((char *)&file_str_bytes, sizeof(file_str_bytes));
            for (int i = 0; i < file_str_bytes; i++)
            {
                input.read((char *)&tempch, sizeof(tempch));
                file_str += tempch;
            }
            for (int i = 0; i < level - 1; i++)
            {
                preview_graph += "  |";
                preview_graph += '\t';
            }
            preview_graph += "  |";

            preview_graph += "----";

            preview_graph += file_str;
            preview_graph += '\n';
        }
        else if (folder_tag == 1)
        {
            string folder_str;
            input.read((char *)&file_str_bytes, sizeof(file_str_bytes));
            for (int i = 0; i < file_str_bytes; i++)
            {
                input.read((char *)&tempch, sizeof(tempch));
                folder_str += tempch;
            }
            for (int i = 0; i < level - 1; i++)
            {
                preview_graph += "  |";
                preview_graph += '\t';
            }
            if (first)
            {
                first = false;
            }
            else
            {
                preview_graph += "  |";
                preview_graph += "----";
            }
            preview_graph += folder_str;
            preview_graph += '\n';
            level++;
            inFolderPreviewTravel(input, preview_graph);
            level--;
        }
        input.read((char *)&folder_tag, sizeof(folder_tag));
    }
}

void zipPreview(const fs::path &zip_path, string &preview_graph)
{
    ifstream input;
    input.open(zip_path);
    long FolderTag = 0;
    input.read((char *)&FolderTag, sizeof(FolderTag));
    if (FolderTag == -1)
    {
        inFolderPreviewTravel(input, preview_graph);
    }
    else
    {
        string file_name = "";
        unsigned char file_ch = 0;
        long str_bytes;
        input.read((char *)&str_bytes, sizeof(str_bytes));
        for (int i = 0; i < str_bytes; i++)
        {
            input.read((char *)&file_ch, sizeof(file_ch));
            file_name += file_ch;
        }
        preview_graph = file_name;
    }
    input.close();
}

void initEditBox(sys_edit *editBox, int x, int y, int width, int height)
{
    editBox->create(true);
    editBox->size(width, height);
    editBox->setbgcolor(EGERGB(0xff, 0xff, 0xff));
    editBox->setcolor(EGERGB(0x00, 0x00, 0x00));
    editBox->setfont(20, 0, "黑体");
    editBox->move(x, y);
    editBox->setmaxlen(100); //设置允许输入的字符数
    editBox->visible(true);
}

void loadImages(PIMAGE *images, int num)
{
    string image_half_path = "image/rect";
    string image_path;
    for (int i = 0; i < num; i++)
    {
        images[i] = newimage();
        image_path = image_half_path + to_string(i) + ".png";
        const char *path = image_path.data();
        getimage(images[i], path);
    }
}

void releaseImages(PIMAGE *images, int num)
{
    for (int i = 0; i < num; i++)
    {
        delimage(images[i]);
    }
}

void drawMainInterface(PIMAGE *images)
{
    setfont(30, 0, "隶书", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    setcolor(EGERGB(0x00, 0x00, 0x00));

    outtextxy(30, 30, "本程序基于哈夫曼编码实现对于单个文件以及");
    outtextxy(30, 70, "文件夹的压缩与解压缩，压缩包后缀为.hby。");
    setfont(18, 0, "微软雅黑", 0, 0, FW_DONTCARE, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 120, "https://github.com/HBY-STAR/Code/tree/master/DataStructure/project/HuffmanZip");

    putimage_withalpha(NULL, images[0], 70, 210);
    putimage_withalpha(NULL, images[1], 370, 210);
    putimage_withalpha(NULL, images[2], 70, 330);
    putimage_withalpha(NULL, images[3], 370, 330);
}

void drawFileCompressInterface(PIMAGE *images)
{
    putimage_withalpha(NULL, images[4], 500, 20);
    putimage_withalpha(NULL, images[5], 40, 380);
    setfont(30, 0, "方正启功行楷 简", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 20, "文件压缩:");
    outtextxy(70, 60, "请输入要压缩的文件路径");
    outtextxy(70, 210, "请输入压缩包的路径(后缀为.hby)");
    setfont(20, 0, "等线", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(180, 360, "程序状态:(read only)");
}

void drawFolderCompressInterface(PIMAGE *images)
{
    putimage_withalpha(NULL, images[4], 500, 20);
    putimage_withalpha(NULL, images[5], 40, 380);
    setfont(30, 0, "方正启功行楷 简", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 20, "文件夹压缩:");
    outtextxy(70, 60, "请输入要压缩的文件夹路径");
    outtextxy(70, 210, "请输入压缩包的路径(后缀为.hby)");
    setfont(20, 0, "等线", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(180, 360, "程序状态:(read only)");
}

void drawUncompressInterface(PIMAGE *images)
{
    putimage_withalpha(NULL, images[4], 500, 20);
    putimage_withalpha(NULL, images[6], 40, 380);
    setfont(30, 0, "方正启功行楷 简", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 20, "解压缩:");
    outtextxy(70, 60, "请输入压缩包的路径(后缀为.hby)");
    outtextxy(70, 210, "请输入存储解压文件的文件夹路径");
    setfont(20, 0, "等线", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(180, 360, "程序状态:(read only)");
}

void drawPreviewInterface(PIMAGE *images)
{
    putimage_withalpha(NULL, images[4], 500, 20);
    putimage_withalpha(NULL, images[7], 40, 380);
    setfont(30, 0, "方正启功行楷 简", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 20, "压缩包预览:");
    outtextxy(70, 60, "请输入压缩包的路径");
    outtextxy(70, 210, "压缩包结构如下：(read only)");
    setfont(20, 0, "等线", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(180, 360, "程序状态:(read only)");
}

/*
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
*/