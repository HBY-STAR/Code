#include <iostream>
#include <fstream>
#include <filesystem>
#include <graphics.h>
#include <wchar.h>
#include <string>
#include <ege/sys_edit.h>
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
    setrendermode(RENDER_MANUAL); //不使用自动刷新，减少闪烁
    ege_enable_aa(true);          //开启抗锯齿

    setbkcolor(EGERGB(0x8c, 0xe5, 0xfb)); //背景颜色为浅蓝色

    PIMAGE images[8];
    loadImages(images, 8);

    mouse_msg msg = {0};
    for (; is_run(); delay_fps(60))
    {
        cleardevice();
        drawMainInterface(images);
        //获取鼠标消息，此函数不会等待，运行后会立即返回
        while (mousemsg())
        {
            msg = getmouse();
        }
        if (msg.is_down())
        {
            //文件压缩
            if (msg.x > init_x - 250 && msg.x < init_x - 50 && msg.y > init_y - 30 && msg.y < init_y + 38)
            {
                while (msg.is_up() == false)
                {
                    msg = getmouse();
                }
                sys_edit editBox1, editBox2, editBox3;
                initEditBox(&editBox1, 100, 100, 450, 100);
                initEditBox(&editBox2, 100, 250, 450, 100);
                initEditBox(&editBox3, 180, 390, 370, 60);
                editBox3.setreadonly(true);

                const int buffSize = 100;
                wchar_t strBuffer1[100] = L"";
                wchar_t strBuffer2[100] = L"";
                editBox1.gettext(buffSize, strBuffer1);
                editBox1.gettext(buffSize, strBuffer2);
                wstring state_str = L"";

                for (; is_run(); delay_fps(60))
                {
                    const wchar_t *state = state_str.data();
                    editBox3.settext(state);

                    cleardevice();
                    drawFileCompressInterface(images);

                    while (mousemsg())
                    {
                        msg = getmouse();
                    }
                    if (msg.is_down())
                    {
                        if (msg.x > 500 && msg.x < 620 && msg.y > 20 && msg.y < 81)
                        {
                            while (msg.is_up() == false)
                            {
                                msg = getmouse();
                            }
                            flushkey();
                            break;
                        }
                        else if (msg.x > 40 && msg.x < 160 && msg.y > 380 && msg.y < 444)
                        {
                            while (msg.is_up() == false)
                            {
                                msg = getmouse();
                            }
                            wstring file_path_str = strBuffer1;
                            wstring zip_path_str = strBuffer2;
                            while (file_path_str.find('\\') != file_path_str.npos)
                            {
                                file_path_str = file_path_str.replace(file_path_str.find('\\'), 1, 1, '/');
                            }
                            while (zip_path_str.find('\\') != zip_path_str.npos)
                            {
                                zip_path_str = zip_path_str.replace(zip_path_str.find('\\'), 1, 1, '/');
                            }
                            fs::path file_path = file_path_str;
                            fs::path zip_path = zip_path_str;
                            FileCompress(file_path, zip_path);
                            wstring state_str = L"压缩完成！";
                        }
                    }
                }
            }
            //文件夹压缩
            else if (msg.x > init_x + 50 && msg.x < init_x + 250 && msg.y > init_y - 30 && msg.y < init_y + 38)
            {
                while (msg.is_up() == false)
                {
                    msg = getmouse();
                }
                sys_edit editBox1, editBox2, editBox3;
                initEditBox(&editBox1, 100, 100, 450, 100);
                initEditBox(&editBox2, 100, 250, 450, 100);
                initEditBox(&editBox3, 180, 390, 370, 60);
                editBox3.setreadonly(true);

                const int buffSize = 100;
                wchar_t strBuffer1[100] = L"";
                wchar_t strBuffer2[100] = L"";
                editBox1.gettext(buffSize, strBuffer1);
                editBox1.gettext(buffSize, strBuffer2);
                wstring state_str = L"";

                for (; is_run(); delay_fps(60))
                {
                    const wchar_t *state = state_str.data();
                    editBox3.settext(state);

                    cleardevice();
                    drawFolderCompressInterface(images);

                    while (mousemsg())
                    {
                        msg = getmouse();
                    }
                    if (msg.is_down())
                    {
                        if (msg.x > 500 && msg.x < 620 && msg.y > 20 && msg.y < 81)
                        {
                            while (msg.is_up() == false)
                            {
                                msg = getmouse();
                            }
                            flushkey();
                            break;
                        }
                        else if (msg.x > 40 && msg.x < 160 && msg.y > 380 && msg.y < 444)
                        {
                            while (msg.is_up() == false)
                            {
                                msg = getmouse();
                            }
                            wstring folder_path_str = strBuffer1;
                            wstring zip_path_str = strBuffer2;
                            while (folder_path_str.find('\\') != folder_path_str.npos)
                            {
                                folder_path_str = folder_path_str.replace(folder_path_str.find('\\'), 1, 1, '/');
                            }
                            while (zip_path_str.find('\\') != zip_path_str.npos)
                            {
                                zip_path_str = zip_path_str.replace(zip_path_str.find('\\'), 1, 1, '/');
                            }
                            fs::path folder_path = folder_path_str;
                            fs::path zip_path = zip_path_str;
                            FolderCompress(folder_path, zip_path);
                            wstring state_str = L"压缩完成！";
                        }
                    }
                }
            }
            //压缩包预览
            else if (msg.x > init_x - 250 && msg.x < init_x - 50 && msg.y > init_y + 90 && msg.y < init_y + 158)
            {
            }
            //解压缩
            else if (msg.x > init_x + 50 && msg.x < init_x + 250 && msg.y > init_y + 90 && msg.y < init_y + 158)
            {
            }
            else
            {
                continue;
            }
        }
    }

    releaseImages(images, 8);
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