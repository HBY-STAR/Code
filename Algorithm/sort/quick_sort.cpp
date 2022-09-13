//快速排序，NlogN
//三数中值分割法
#include<iostream>
#include<vector>

//驱动程序
template<typename Comparable>
void quicksort(vertor<Comparable> & a)
{
    quicksort(a, 0, a.size());
}

//执行三数中值分割的代码
template<typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
    int center = (left+right)/2;

    if(a[center] < a[left])
        std::swap(a[left],a[center]);
    if(a[right] < a[left])
        std::swap(a[left],a[right]);
    if(a[right] < a[center])
        std::swap(a[right],a[center]);
    
    //将枢纽元置于right-1处
    std::swap(a[center], a[right-1]);
    return a[right-1];
}

//进行递归调用的内部快速排序方法
template<typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
    if(left + 10 <= right)        //数组较大时才调用快速排序
    {
        //选取枢纽元
        const Comparable & pivot = median3(a, left, right);

        //开始分割
        int i = left, j = right-1;
        for( ; ; )
        {
            while(a[++i] < pivot) { }
            while(pivot < a[--j]) { }
            if(i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        //恢复枢纽元
        std::swap(a[i], a[right-1]);

        //分别对左右的两个数组进行递归
        quicksort(a, left, i-1);
        quicksort(a, i+1, right);
    }
    else
        insertsort(a,left,right); //数组较小时进行插入排序
}

//插入排序1·1
template<typename Comparable>
void insertsort(vector<Comparable> & a, int left, int right)
{
    for(int p=left+1;p<=right;++p)
    {
        Comparable temp = std::move(a[p]);

        int j;
        for(j=p; j>left && temp<a[j-1]; --j)
            a[j] = std::move(a[j-1]);
        a[j] = std::move(temp);
    }
}

/*
快速排序算法首先选取一个枢纽元，再以枢纽元的值为中间值
将数组分成两组。（分组的操作通过在数组两头设置迭代器并
不断向中间靠拢，在两个迭代器都碰到不符合分组规定的元素
时对其进行交换，然后继续不断向中间靠拢直到碰头）然后再
分别对两组进行递归操作。
*/

template<typename Comparable>
void quickselect(vector<Comparable>&a,int left,int right,int k)
{
    if(left+10<=right)
    {
        const Comparable&pivot=median3(a,left,right);

        int i=left,j=right-1;
        for(;;)
        {
            while(a[++i]<pivot){}
            while(pivot<a[--j]){}
            if(i<j)
                std::swap(a[i],a[j]);
            else
                break;
        }
        std::swap(a[i],a[right-1]);
        if(k<=i)
            quickselect(a,left,i-1,k);
        else if(k>i+1)
            quickselect(a,i+1,right,k);
    }
    else
        insertsort(a,left,right);
};