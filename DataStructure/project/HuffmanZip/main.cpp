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
    setcaption("HuffmanZip"); //设置窗口标题

    initgraph(640, 480, 0);
    const int init_x = 320;
    const int init_y = 240;

    ege_enable_aa(true); //开启抗锯齿

    setbkcolor(EGERGB(0x8c, 0xe5, 0xfb)); //背景颜色为浅蓝色

    setfont(30, 0, "隶书", 0, 0, 6, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    setcolor(EGERGB(0x00, 0x00, 0x00));

    outtextxy(30, 30, "本程序基于哈夫曼编码实现对于单个文件以及");
    outtextxy(30, 70, "文件夹的压缩与解压缩，压缩包后缀为.hby。");
    setfont(18, 0, "微软雅黑", 0, 0, FW_DONTCARE, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    outtextxy(30, 120, "https://github.com/HBY-STAR/Code/tree/master/DataStructure/project/HuffmanZip");

    PIMAGE rect1 = newimage();
    PIMAGE rect2 = newimage();
    PIMAGE rect3 = newimage();
    PIMAGE rect4 = newimage();
    PIMAGE rect5 = newimage();
    getimage(rect1, "image/rect1.png");
    getimage(rect2, "image/rect2.png");
    getimage(rect3, "image/rect3.png");
    getimage(rect4, "image/rect4.png");
    getimage(rect5, "image/rect5.png");

    putimage_withalpha(NULL, rect1, init_x - 250, init_y - 30);
    putimage_withalpha(NULL, rect2, init_x + 50, init_y - 30);
    putimage_withalpha(NULL, rect3, init_x - 250, init_y + 90);
    putimage_withalpha(NULL, rect4, init_x + 50, init_y + 90);

    

















    delimage(rect1);
    delimage(rect2);
    delimage(rect3);
    delimage(rect4);
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