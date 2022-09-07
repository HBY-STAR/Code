#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    using namespace std;
    double price;
    char ch;
    string a;
    cin >> a;
    cin.get();
    ch = cin.get();
    if (ch != '\n')
    {
        cin >> price;
    }
    else
    {
        price = 1.0;
    }
    cout << a << endl;
    cout << price << endl;
    system("Pause");
    return 0;
}