#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> data;

int is_x_exist(int *a, int x, int length)
{
    for (int i = 1; i <= length; i++)
    {
        if (a[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

void permute(int k)
{
    static int a[10000] = {0};
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_x_exist(a, i, n) == 0)
        {
            a[k] = i;
            permute(k + 1);
            a[k] = 0;
        }
    }
}

int main()
{
    cin >> n;
    data = vector<int>(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        data[i] = i;
    }
    permute(1);
    return 0;
}