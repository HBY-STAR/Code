#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 100000

int main()
{
    using namespace std;
    int n;
    double p1 = 1.0, p2 = 1.0;
    cout << "请输入同学的人数：";
    cin >> n;
    while (n > 366)
    {
        cout << "你tm故意找茬是不是？" << endl;
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        p1 = p1 * (double)(365 - i) / (double)365;
    }

    srand((unsigned int)(time(NULL) + clock()));
    int count = 0;
    int flag;
    int day[365];
    for (int i = 0; i < N; i++)
    {
        flag = 0;
        for (int j = 0; j < 365; j++)
        {
            day[j] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            day[j] = (int)(rand() % 366);
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (day[j] == day[k])
                {
                    flag++;
                    count++;
                    break;
                }
            }
            if (flag != 0)
            {
                break;
            }
        }
    }
    p2 = 1 - ((double)count) / N;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    return 0;
}