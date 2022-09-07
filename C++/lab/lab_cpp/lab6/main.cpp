#include <iostream>
#include <fstream>
#include "BigNum.h"

int main()
{
    //文件与流关联
    ifstream input_file;
    ofstream output_file;
    input_file.open("test_in.txt");
    output_file.open("test_out.txt");

    //临时变量声明
    string tempstr;
    string tempch;
    int tempint;
    BigNum temp, temp1, temp2;

    //读取操作个数
    input_file >> tempint;

    for (int i = 0; i < tempint; i++)
    {
        input_file >> tempstr; //读取每行第一个字符串
        if (tempstr == "<<")   // tempstr若为<<
        {
            input_file >> tempstr;
            temp = BigNum(tempstr);
            output_file << temp << endl;
        }
        else if (tempstr == ">>") // tempstr若为>>
        {
            cin >> temp;
            output_file << temp << endl;
        }
        else // tempstr若为大整数
        {
            temp1 = BigNum(tempstr);
            input_file >> tempch >> tempstr;
            temp2 = BigNum(tempstr);
            if (tempch == "-") //若tempch为-
            {
                temp = temp1 - temp2;
            }
            else if (tempch == "+") //若tempch为+
            {
                temp = temp1 + temp2;
            }
            else
            {
                cout << "error" << endl;
            }
            output_file << temp << endl;
        }
    }
    return 0;
}