#include "MineMap.h"

int main()
{
    using namespace std;

    int length, width, MineNum; //地雷图的长、宽和地雷数量
    char Order;                 //存放主界面内的命令
    int flag = 1;               //程序终止的标签
    bool CinFail;               //用于检验输入
    char order;                 //存放游戏界面的命令
    int x, y;                   //存放游戏界面中进行操作的坐标
    int first = 0;              //标记游戏界面中第一次打开某个格子的操作，使第一次打开的格子不为地雷
    int win = 0, lose = 0;      //标记游戏的成功与失败

    //总while循环，控制程序一直运行
    while (flag == 1)
    {
        //打印主界面
        system("CLS");
        PrintMain();

        //在主界面中读取命令，并检查主界面的输入
        cin >> Order;
        CinFail = cin.fail();
        InputCheck(CinFail, Order, 'O');

        //对主界面内的命令进行选择
        switch (Order)
        {

        /************************************游戏界面****************************************/
        //开始游戏
        case 's': // s意为start，进入游戏界面
        {
            Remind(); //对用户的输入进行提示

            //读取地雷图有关参数，并检查用户输入
            cin >> length >> width >> MineNum;
            CinFail = cin.fail();
            InputCheck(CinFail, length, width, MineNum);

            //创建一个随机地雷图对象map
            MineMap map = MineMap(length, width, MineNum);
            system("CLS");
            map.ShowMap();

            //每进行一次游戏，都要对以下值进行初始化
            first = 0;
            win = 0;
            lose = 0;

            //读取游戏界面的命令，并检查用户的输入
            cin >> order;
            CinFail = cin.fail();
            InputCheck(CinFail, order, 'o');

            //游戏界面内的循环，控制本次游戏的进行
            while (order != 'q') // q意为quit
            {
                //读取要进行操作的坐标，并检查用户输入
                cin >> x >> y;
                CinFail = cin.fail();
                InputCheck(CinFail, x, y, length, width);

                //对游戏界面的命令进行选择
                switch (order)
                {
                //打开单个格子
                case 'o': // o意为open
                {
                    Open(map, first, win, lose, x, y, CinFail, order, length, width, MineNum, 'o');
                    break;
                }
                //标记地雷
                case 'm': // m意为mark
                {
                    Mark(map, CinFail, order, x, y);
                    break;
                }
                //取消标记
                case 'c': // c意为cancel_mark
                {
                    CancelMark(map, CinFail, order, x, y);
                    break;
                }
                //自动打开周围格子
                case 'a': // a意为auto_open
                {
                    Open(map, first, win, lose, x, y, CinFail, order, length, width, MineNum, 'a');
                    break;
                }
                    /*   测试用，直接展示整个地图
                        case 't':
                        {
                            Test(map,CinFail,order);
                            break;
                        }
                    */
                }
            }
            break;
        }
        /********************************************************************************/

        //帮助界面
        case 'h': // h意为help
        {
            HelpInterface(CinFail);
            break;
        }

        //退出程序
        case 'q': // q意为quit
        {
            flag = 0;
            break;
        }
        }
    }
    return 0;
}