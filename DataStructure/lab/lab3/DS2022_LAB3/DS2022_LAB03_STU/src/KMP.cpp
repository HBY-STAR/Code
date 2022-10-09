#include "KMP.h"

using namespace std;

int KMP::strStr(const string &haystack, const string &needle)
{
    int n_length = needle.size();
    int hay_length = haystack.size();
    vector<int> nextpos(n_length, 0);
    nextpos = getNextArr(needle);
    int i = 0, j = 0;
    while (i < hay_length && j < n_length)
    {
        if (j == -1 || haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextpos[j];
        }
    }
    if (j >= n_length)
    {
        return i - n_length;
    }
    else
        return -1;

    // TODO
}

std::vector<int> KMP::getNextArr(const string &needle)
{
    int length = needle.size();
    vector<int> nextpos(length, 0); // nextpos即为对于needle中每个位置前的字符串的最长相等前后缀的长度
    nextpos[0] = -1;                //虽然很容易也能得到nextpos[1]=0,但我们无法确保needle的长度是否至少为2。

    int i = -1, j = 0; //这里i为前缀最大相等字符串的下一个字符下标，j为后缀最大相等字符串的下一个字符下标
                       //因为接下来将要测的第一个值为needle[1]，故j应从0开始。
                       //这里的i=-1是因为刚开始测试时i应该与j错开且比j小

    while (j < length)
    {

        if (i == -1 || needle[i] == needle[j]) //这里在前面的测试i==-1防止访问越界，同时也为对于下标j的最大字符串的查找的结束。
        {                                      //这里i为前缀最大相等字符串的下一个字符下标，j为后缀最大相等字符串的下一个字符下标
            i++;                               //故可以直接通过测试
            j++;
            nextpos[j] = i;
        }
        else                //若needle[i]和needle[j]的值不同，则i要重设为前面字符串的最大前缀相等字符串的下一个值的下标，
        {                   //即needle[i],因为目前已知从j开始往前的字符串中第二长的最大前缀字符串前面的部分即为needle[needle[i]]
            i = nextpos[i]; //前面的部分，故重设i之后可以直接测试needle[i]和needle[j]来确定nextpos[j]的取值
        }
    }
    return nextpos;
}
