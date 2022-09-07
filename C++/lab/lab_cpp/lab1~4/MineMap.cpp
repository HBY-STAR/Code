#include "MineMap.h"

using namespace std;
/******************************MineMap成员函数***********************************/
//无参构造函数
MineMap::MineMap()
{
    m_length = 9;
    m_width = 9;
    m_MineNum = 10;

    m_map = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_map[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_map[i][j] = 0;
        }
    }

    m_mark = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_mark[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_mark[i][j] = 0;
        }
    }

    std::srand((unsigned int)(std::time(NULL) + std::clock()));
    int temp_x, temp_y;
    int count = 0;
    temp_x = std::rand() % m_length;
    temp_y = std::rand() % m_width;
    while (count < m_MineNum)
    {
        if (m_map[temp_x][temp_y] == 0)
        {
            m_map[temp_x][temp_y] = -1;
            count++;
        }
        temp_x = std::rand() % m_length;
        temp_y = std::rand() % m_width;
    }
    int x[3] = {-1, 0, 1};
    int y[3] = {-1, 0, 1};
    for (int i = 0; i < m_length; i++)
    {
        int count;
        for (int j = 0; j < m_width; j++)
        {
            if (m_map[i][j] == -1)
            {
                continue;
            }
            else
            {
                count = 0;
                {
                    for (int m = 0; m < 3; m++)
                    {
                        for (int n = 0; n < 3; n++)
                        {
                            if (i + x[m] >= 0 && i + x[m] < m_length && j + y[n] >= 0 && j + y[n] < m_width && m_map[i + x[m]][j + y[n]] == -1)
                            {
                                count++;
                            }
                        }
                    }
                }
                m_map[i][j] = count;
            }
        }
    }
}

//有参构造函数
MineMap::MineMap(int length, int width, int MineNum)
{
    m_length = length;
    m_width = width;
    m_MineNum = MineNum;

    m_map = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_map[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_map[i][j] = 0;
        }
    }

    m_mark = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_mark[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_mark[i][j] = 0;
        }
    }

    std::srand((unsigned int)(std::time(NULL) + std::clock()));
    int temp_x, temp_y;
    int count = 0;
    temp_x = std::rand() % m_length;
    temp_y = std::rand() % m_width;
    while (count < m_MineNum)
    {
        if (m_map[temp_x][temp_y] == 0)
        {
            m_map[temp_x][temp_y] = -1;
            count++;
        }
        temp_x = std::rand() % m_length;
        temp_y = std::rand() % m_width;
    }

    for (int i = 0; i < m_length; i++)
    {
        int count;
        for (int j = 0; j < m_width; j++)
        {
            if (m_map[i][j] == -1)
            {
                continue;
            }
            else
            {
                count = 0;
                {
                    if (i - 1 >= 0 && j - 1 >= 0 && m_map[i - 1][j - 1] == -1)
                        count++;
                    if (i - 1 >= 0 && m_map[i - 1][j] == -1)
                        count++;
                    if (i - 1 >= 0 && j + 1 < m_width && m_map[i - 1][j + 1] == -1)
                        count++;
                    if (j - 1 >= 0 && m_map[i][j - 1] == -1)
                        count++;
                    if (j + 1 < m_width && m_map[i][j + 1] == -1)
                        count++;
                    if (i + 1 < m_length && j - 1 >= 0 && m_map[i + 1][j - 1] == -1)
                        count++;
                    if (i + 1 < m_length && m_map[i + 1][j] == -1)
                        count++;
                    if (i + 1 < m_length && j + 1 < m_width && m_map[i + 1][j + 1] == -1)
                        count++;
                }
                m_map[i][j] = count;
            }
        }
    }
}

//析构函数
MineMap::~MineMap()
{
    for (int i = 0; i < m_length; i++)
    {
        delete[] m_map[i];
        delete[] m_mark[i];
    }
    delete[] m_map;
    delete[] m_mark;
}

//复制构造函数
MineMap::MineMap(const MineMap &copy)
{
    m_length = copy.m_length;
    m_width = copy.m_width;
    m_MineNum = copy.m_MineNum;
    m_map = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_map[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_map[i][j] = copy.m_map[i][j];
        }
    }

    m_mark = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_mark[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_mark[i][j] = copy.m_map[i][j];
        }
    }
}

//重载赋值运算符
MineMap &MineMap::operator=(const MineMap &copy)
{
    if (this == &copy)
    {
        return *this;
    }
    m_length = copy.m_length;
    m_width = copy.m_width;
    m_MineNum = copy.m_MineNum;

    for (int i = 0; i < m_length; i++)
    {
        delete[] m_map[i];
        delete[] m_mark[i];
    }
    delete[] m_map;
    delete[] m_mark;

    m_map = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_map[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_map[i][j] = copy.m_map[i][j];
        }
    }

    m_mark = new int *[m_length];
    for (int i = 0; i < m_length; i++)
    {
        m_mark[i] = new int[m_width];
    }
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            m_mark[i][j] = copy.m_mark[i][j];
        }
    }
    return *this;
}

//打开单个格子
void MineMap::Open(int x, int y)
{
    if (m_mark[x][y] != 10)
        m_mark[x][y] = 1;
}

//自动打开周围格子
void MineMap::AutoOpen(int x, int y)
{
    m_mark[x][y] = 1;
    if (m_map[x][y] == 0)
    {
        static int a[3] = {-1, 0, 1};
        static int b[3] = {-1, 0, 1};
        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 3; n++)
            {
                if (x + a[m] >= 0 && x + a[m] < m_length && y + b[n] >= 0 && y + b[n] < m_width && m_mark[x + a[m]][y + b[n]] != 10 && m_mark[x + a[m]][y + b[n]] != 1)
                {
                    m_mark[x + a[m]][y + b[n]] = 1;
                    MineMap::AutoOpen(x + a[m], y + b[n]);
                }
            }
        }
    }
}

//标记地雷
void MineMap::Mark(int x, int y)
{
    m_mark[x][y] = 10;
}

//取消标记
void MineMap::CancelMark(int x, int y)
{
    m_mark[x][y] = 0;
}

//展示表层地雷图
void MineMap::ShowMap()
{
    int count = 0;
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            if (m_mark[i][j] == 10)
                count++;
        }
    }
    std::cout << "地雷数量：" << m_MineNum << "  标记数量：" << count << std::endl;
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            if (m_mark[i][j] == 0)
            {
                std::cout << '#' << ' ';
            }
            else if (m_mark[i][j] == 10)
            {
                std::cout << '&' << ' ';
            }
            else if (m_mark[i][j] == 1)
            {
                std::cout << m_map[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}

//展示底层地雷图
void MineMap::Endshow()
{
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            if (m_map[i][j] == -1)
            {
                std::cout << '*' << ' ';
            }
            else
            {
                std::cout << m_map[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}

//判断是否成功，成功返回1，继续则返回0.
int MineMap::JudgeWin()
{
    int count = 0;
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            if (m_map[i][j] != -1 && m_mark[i][j] == 1)
                count++;
        }
    }
    if (count == m_length * m_width - m_MineNum)
        return 1;
    else
        return 0;
}

//判断是否失败，失败返回-1，继续则返回0.
int MineMap::JudgeLose()
{
    for (int i = 0; i < m_length; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            if (m_map[i][j] == -1 && m_mark[i][j] == 1)
                return -1;
        }
    }
    return 0;
}

//展示一次游戏所用的时间
void MineMap::ShowTime()
{
    end = clock();
    std::cout << "本次游戏用时 " << int((end - start) / CLOCKS_PER_SEC) << " s。" << std::endl;
}
/*******************************************************************************/

/***********************************其他函数*************************************/
//打印主界面
void PrintMain()
{
    cout << "##欢迎来到侯斌洋制作的扫雷游戏！##" << endl;
    cout << "#        s  开始游戏             #" << endl;
    cout << "#        h  帮助界面             #" << endl;
    cout << "#        q  退出游戏             #" << endl;
    cout << "##################################" << endl;
}

//帮助界面
void HelpInterface(bool &CinFail)
{
    system("CLS");
    cout << "############帮助界面############" << endl;
    cout << "#      o x y 打开(x,y)格子     #" << endl;
    cout << "#      m x y 标记(x,y)格子     #" << endl;
    cout << "#      c x y 取消(x,y)标记     #" << endl;
    cout << "#  a x y 自动打开(x,y)周围格子 #" << endl;
    cout << "#        q  返回主界面         #" << endl;
    cout << "################################" << endl;
    char temporder;
    cin >> temporder;
    CinFail = cin.fail();
    InputCheck(CinFail, temporder, 't');
}

//检查输入的函数的第一个重载
void InputCheck(bool &CinFail, int &length, int &width, int &MineNum)
{
    while (length > 24 || width > 30 || MineNum > length * width || cin.fail() || length < 1 || width < 1)
    {
        cout << "输入数据不满足要求，请重新输入。" << endl;
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
        cin >> length >> width >> MineNum;
        CinFail = cin.fail();
    }
}

//检查输入的函数的第二个重载
void InputCheck(bool &CinFail, char &order, char a)
{
    if (a == 'o')
    {
        while (cin.fail() || (order != 'q' && order != 'o' && order != 'm' && order != 'c' && order != 'a'))
        {
            cout << "输入数据不满足要求，请重新输入。" << endl;
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cin >> order;
            CinFail = cin.fail();
        }
    }
    else if (a == 'O')
    {
        while (CinFail || (order != 's' && order != 'h' && order != 'q'))
        {
            cout << "输入数据不满足要求，请重新输入。" << endl;
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cin >> order;
            CinFail = cin.fail();
        }
    }
    else if (a == 't')
    {
        while (cin.fail() || order != 'q')
        {
            cout << "输入数据不满足要求，请重新输入。" << endl;
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cin >> order;
        }
    }
}

//检查输入的函数的第三个重载
void InputCheck(bool &CinFail, int &x, int &y, int &length, int &width)
{
    while (x >= length || y >= width || cin.fail() || x < 0 || y < 0)
    {
        cout << "输入坐标不满足要求,请重新输入x和y。" << endl;
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
        cin >> x >> y;
        CinFail = cin.fail();
    }
}

//打开某个格子的一系列操作的整合，包括了open和auto_open，同时还会对游戏状态进行判断
void Open(MineMap &map, int &first, int &win, int &lose, int &x, int &y, bool &CinFail, char &order, int &length, int &width, int &MineNum, char a)
{
    if (a == 'o')
    {
        map.Open(x, y);
        //判断游戏成功失败情况
        // lose==-1失败，win==1成功，lose==win==0继续
        lose = map.JudgeLose();
        win = map.JudgeWin();

        //使第一次打开的格子不为地雷
        while (lose == -1 && first == 0)
        {
            map = MineMap(length, width, MineNum);
            map.Open(x, y);
            lose = map.JudgeLose();
            win = map.JudgeWin();
            if (lose == 0)
            {
                map.SetTime(); //设置起始时间
                first = 1;
            }
        }
    }
    else if (a == 'a')
    {
        map.AutoOpen(x, y);

        //判断游戏成功失败情况
        // lose==-1失败，win==1成功，lose==win==0继续
        lose = map.JudgeLose();
        win = map.JudgeWin();

        //使第一次打开的格子不为地雷
        while (lose == -1 && first == 0)
        {
            map = MineMap(length, width, MineNum);
            map.AutoOpen(x, y);
            lose = map.JudgeLose();
            win = map.JudgeWin();
            if (lose == 0)
            {
                map.SetTime(); //设置起始时间
                first = 1;
            }
        }
    }
    if (first == 0)
    {
        map.SetTime(); //设置起始时间
    }
    first = 1;

    //游戏继续进行
    if (lose == 0 && win == 0)
    {
        system("CLS");
        map.ShowMap();
        cin >> order;
        CinFail = cin.fail();
        InputCheck(CinFail, order, 'o');
    }
    //游戏失败
    else if (lose == -1)
    {
        cout << "You Lose ~\n";
        map.ShowTime();
        system("Pause");

        //给玩家展示完整地雷图
        system("CLS");
        map.Endshow();
        system("Pause");

        //自动返回主界面
        order = 'q';
        return;
    }
    //游戏成功
    else if (win == 1)
    {
        cout << "You win ~\n";
        map.ShowTime();
        system("Pause");

        //给玩家展示完整地雷图
        system("CLS");
        map.Endshow();
        system("Pause");

        //自动返回主界面
        order = 'q';
        return;
    }
}

//测试用，可以直接打开地雷图
void Test(MineMap &map, bool &CinFail, char &order)
{
    // system("CLS");
    map.Endshow();
    system("Pause");
    cin >> order;
    CinFail = cin.fail();
    InputCheck(CinFail, order, 'o');
}

//取消标记的一系列操作的整合
void CancelMark(MineMap &map, bool &CinFail, char &order, int &x, int &y)
{
    map.CancelMark(x, y);
    system("CLS");
    map.ShowMap();
    cin >> order;
    CinFail = cin.fail();
    InputCheck(CinFail, order, 'o');
}

//对某个格子进行标记的操作的整合
void Mark(MineMap &map, bool &CinFail, char &order, int &x, int &y)
{
    map.Mark(x, y);
    system("CLS");
    map.ShowMap();
    cin >> order;
    CinFail = cin.fail();
    InputCheck(CinFail, order, 'o');
}

//在输入地雷图参数时对用户的输入进行提示
void Remind()
{
    cout << "现在请输入雷区的长（小于24）、宽（小于30）和地雷数量" << endl;
    cout << "输入格式类似于:9 9 10\n";
}

/*******************************************************************************/