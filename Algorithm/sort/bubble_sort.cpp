//冒泡排序，N^2
//通过交换相邻元素进行排序的任何算法平均都需要N^2时间
//本节排序算法均为从小到大进行排序
#include<iostream>
#include<vector>

template<typename Comparable>
void bubblesort(vector<Comparable> & a)
{
    Comparable temp;
    bool isSorted;               //对外循环进行优化
    int lastSwapPosition = 0;  //对内循环进行优化
    int sortBorder = a.size()-1;
    for(int i = 0; i < a.size()-1; i++)
    {
        isSorted = true;
        for(int j = 0; j < sortBorder; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = std::move(a[j]);
                a[j] = std::move(a[j+1]);
                a[j+1] = std::move(temp);
                isSorted = false;
                lastSwapPosition=j;
            } 
        }
        if( isSorted )
            break;
        sortBorder = lastSwapPosition;
    }
}

/*
冒泡排序每一趟只能确定将一个数归位。即第一趟只能确定将末位上的数归位，
第二趟只能将倒数第 2 位上的数归位，依次类推下去。如果有 n 个数进行排序，
只需将 n-1 个数归位，也就是要进行 n-1 趟操作。而 “每一趟 ” 都需要从第一
位开始进行相邻的两个数的比较，将较大的数放后面，比较完毕之后向后挪一位
继续比较下面两个相邻的两个数大小关系，重复此步骤，直到最后一个还没归位
的数。
*/