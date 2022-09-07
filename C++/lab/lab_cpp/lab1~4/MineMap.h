#ifndef MINEMAP_H
#define MINEMAP_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

/************************************MineMap类********************************************/
class MineMap
{
private:
    int m_length;
    int m_width;
    int m_MineNum;
    clock_t start, end;

    //对于地雷图，-1表示有雷，其余数字表示周围雷的数量
    int **m_map;

    //对于标记图，1表示该位置已被打开，10表示被标记，0表示未被打开也未被标记
    int **m_mark;

public:
    MineMap();
    MineMap(int length, int width, int MineNum);
    ~MineMap();
    MineMap(const MineMap &copy);
    MineMap &operator=(const MineMap &copy);
    void Open(int x, int y);
    void AutoOpen(int x, int y);
    void Mark(int x, int y);
    void CancelMark(int x, int y);
    void ShowMap();
    void Endshow();
    int JudgeWin();
    int JudgeLose();
    void SetTime() { start = clock(); }
    void ShowTime();
};
/****************************************************************************************/

/***********************************其他函数声明******************************************/
void PrintMain();
void PrintHelp();
void InputCheck(bool &CinFail, int &length, int &width, int &MineNum);
void InputCheck(bool &CinFail, char &order, char a);
void InputCheck(bool &CinFail, int &x, int &y, int &length, int &width);
void Open(MineMap &map, int &first, int &win, int &lose, int &x, int &y, bool &CinFail, char &order, int &length, int &width, int &MineNum, char a);
void HelpInterface(bool &CinFail);
void Test(MineMap &map, bool &Cinfail, char &order);
void CancelMark(MineMap &map, bool &CinFail, char &order, int &x, int &y);
void Mark(MineMap &map, bool &CinFail, char &order, int &x, int &y);
void Remind();
/****************************************************************************************/

#endif
