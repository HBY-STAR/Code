#include <iostream>
#include <fstream>
#include <filesystem>
#include <graphics.h>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Functions.h"

namespace fs = std::filesystem;
using namespace std;

int main()
{
    setcaption("HuffmanZip");

    initgraph(640, 480, 0);

    setfont(18, 0, "宋体");
    // settextjustify(LEFT_TEXT, TOP_TEXT); //默认值
    outtextxy(300, 0, "Hello Graphics");

    settextjustify(RIGHT_TEXT, TOP_TEXT);
    outtextxy(300, 50, "Hello Graphics");

    settextjustify(CENTER_TEXT, TOP_TEXT);
    outtextxy(300, 100, "Hello Graphics");

    settextjustify(LEFT_TEXT, BOTTOM_TEXT);
    outtextxy(300, 50, "Hello Graphics");

    getch();

    closegraph();

    // fs::path folder_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\test1";
    // fs::path zip_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\test1.hby";
    // fs::path folder_path2 = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\(1)test1";
    // fs::path file_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\miku.jfif";
    // fs::path folder_path1 = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip";
    // fs::path zip_path1 = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\miku.hby";
    // FileCompress(file_path, zip_path1);
    // FileUncompress(zip_path1, folder_path1);
    // FolderCompress(folder_path, zip_path);
    // FolderUncompress(zip_path, folder_path2);
    return 0;
}