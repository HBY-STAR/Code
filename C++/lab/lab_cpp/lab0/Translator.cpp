#include <iostream>
#include <fstream>
int main()
{
    using namespace std;

    //声明对象并将其与文件关联起来
    ifstream inFileDict;
    ifstream inFileResult;
    ofstream outFileText;
    inFileDict.open("dict.txt");
    inFileResult.open("result.txt");
    outFileText.open("text.txt");

    //工具变量及数组
    int num;
    int count = 0;
    char ch;
    char a[50];
    
    //将dict.txt文件读入到数组中然后及时关闭
    inFileDict.getline(a, 50);
    inFileDict.close();

    //程序主体
    /*这是第一次写的主体：
      do
      {  
          inFileResult >> num;
          ch = a[num];
          outFileText << ch;
      } while (inFileResult.fail() == false);
      由于先使用了inFileResult，然后再用outFileText，导致即使
      failbit已经设置成1，但此时的ch仍旧是最后一个字符，因此在
      最后会多打印一个字符下面的代码很好地解决了这个问题，要把
      inFileResult放在outFileText之前，就需要在循环开始前加一
      个inFileResult输入
    */
    inFileResult >> num;
    do{  
        ch = a[num];
        outFileText << ch;
        inFileResult >> num;
    } while (inFileResult.fail() == false);
    
    //及时关闭文件
    inFileResult.close();
    outFileText.close();
    return 0;
}