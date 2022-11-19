#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int path[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            path[i][j] = -1;
        }
    }
    int A[6][6] = {{0, 4, 3, 999, 999, 999},
                   {999, 0, 5, 2, 999, 999},
                   {999, 999, 0, 7, 5, 12},
                   {999, 999, 999, 0, 2, 999},
                   {4, 999, 999, 999, 0, 6},
                   {999, 999, 999, 999, 999, 0}};
    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
        cout << 'A' << k << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << A[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "path" << k << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << path[i][j] << '\t';
            }
            cout << endl;
        }
    }
    return 0;
}