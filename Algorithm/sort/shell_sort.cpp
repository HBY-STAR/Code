//希尔排序，最坏为N^2，取决于增量序列
#include<vector>

using namespace std;

template<typename Comparable>
void shellSort(vector<Comparable> & a)
{
    for(int gap=a.size()/2; gap>0; gap /= 2)
        for(int i = gap; i<a.size(); ++i)
        {
            Comparable temp = std::move(a[i]);
            int j=i;

            for( ; j>=gap&&temp<a[j-gap]; j -= gap)
                a[j] = std::move( a[j-gap]);
            a[j] = std::move(temp);
        }
}

/*
希尔排序使用一个增量序列h1,h2,...,hk(h1=1)，在使用增量hk的
一次排序(对hk-N中的任意位置 i 对其朝前以gap=hk为间隔的序
列进行插入排q序)后。对数组中的任意元素 i 有 a[i]<=a[i+hk]。
之后利用了希尔排序的性质：一个hk排序后的文件在此后进行
hk-1排序时也保持其hk排序性。
*/