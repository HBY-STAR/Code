//插入排序，N^2
#include<vector>
#include<iostream>

template<typename Comparable>
void insertsort(vector<Comparable> & a)
{
    for(int p=1;p<a.size();++p)
    {
        Comparable temp = std::move(a[p]);

        int j;
        for(j=p; j>0 && temp<a[j-1]; --j)
            a[j] = std::move(a[j-1]);
        a[j] = std::move(temp);
    }
}

/*
插入排序利用了从0到p-1位置上的元素是已经排过序的特性，然后只需要
将第p个元素不断左移直到找到合适的位置并插入。
*/