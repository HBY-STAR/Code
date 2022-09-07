//归并排序，NlogN
#include<iostream>
#include<vertor>

//驱动程序
template<typename Comparable>
void mergesort(vertor<Comparable> & a)
{
    vertor<Comparable> tempArray(a.size());
    mergesort(a, tempArray, 0, a.size()-1);
}

//进行递归调用的内部方法
template<typename Comparable>
void mergesort(vector<Comparable> & a, 
                   vector<Comparable> & tempArray, int left, int right)
{
    if(left < right)
    {
        int center = (left+right)/2;
        mergesort(a, tempArray, left, center);
        mergesort(a, tempArray, center+1, right);
        merge(a, tempArray, left, center+1, right);
    }
}

//合并两个数组的操作
template<typename Comparable>
void merge(vertor<Comparable> & a,vector<Comparable> & tempArray,
              int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos-1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if(a[leftPos] <= a[rightPos])
            tempArray[tempPos++] = std::move(a[leftPos++]);
        else
            tempArray[tempPos++] = std::move(a[rightPos++]);
    }

    while(leftPos <= leftEnd)
        tempArray[tempPos++] = std::move(a[leftPos++]);
    while(rightPos <= rightEnd)
        tempArray[tempPos++] = std::move(a[rightPos++]);

    for(int i=0; i < numElements; ++i,--rightEnd)
    {
        a[rightEnd] = std::move(tempArray[rightEnd]);
    }   
}

/*
归并排序基本操作是合并两个已排序的表。
通过递归地将前半部分数据和后半部分数据归并排序,
得到排序后的两部分数据，再通过合并两个已排序
的表的操作对整个表进行排序。
主要缺点为使用了一个附加表占用空间以及在线性表中
的进行移动和复制操作消耗时间
*/