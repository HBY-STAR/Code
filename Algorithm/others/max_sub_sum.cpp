//求最大子序列和
#include<iostream>
#include<vector>

using namespace std;

//N^3
int maxSubSum1(const vector<int> &a)
{
    int maxSum=0;
    for(int i=0;i<a.size();i++)
        for(int j=i;j<a.size();++j)
        {
            int thisSum=0;
            for(int k=i;k<=j;++k)
                thisSum+=a[k];

            if(thisSum>maxSum)
                maxSum=thisSum;
        }

    return maxSum;
}

//N^2
int maxSubSum2(const vector<int> &a)
{
    int maxSum=0;

    for(int i=0;i<a.size();i++)
    {
        int thisSum=0;
        for(int j=i;j<a.size();++j)
        {
            thisSum+=a[j];

            if(thisSum>maxSum)
                maxSum=thisSum;
        }
    }

    return maxSum;
}

//NlogN
int max3(int a,int b,int c)
{
    if(a>=b)
    {
        if(a>=c)
            return a;
        else
            return c;
    }
    else
    {
        if(b>=c)
            return b;
        else
            return c; 
    }
}

int maxSumRec(const vector<int> & a,int left,int right)
{
    if(left==right)
        if(a[left]>0)
            return a[left];
        else
            return 0;

    int center = (left+right)/2;
    int maxLeftSum = maxSumRec(a,left,center);
    int maxRightSum = maxSumRec(a,center+1,right);

    int maxLeftBorderSum=0,leftBorderSum=0;
    for(int i=center;i>=left;--i)
    {
        leftBorderSum += a[i];
        if(leftBorderSum>maxLeftBorderSum)
            maxLeftBorderSum=leftBorderSum;
    }

    int maxRightBorderSum=0,rightBorderSum=0;
    for(int j= center+1;j<=right;++j)
    {
        rightBorderSum += a[j];
        if(rightBorderSum>maxRightBorderSum)
            maxRightBorderSum=rightBorderSum;
    }

    return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum);
}

int maxSubSum3(const vector<int> &a)
{
    return maxSumRec(a,0,a.size()-1);
}

//N
int maxSubSum4(const vector<int> &a)
{
    int maxSum=0,thisSum=0;

    for(int j=0;j<a.size();++j)
    {
        thisSum += a[j];

        if(thisSum>maxSum)
            maxSum=thisSum;
        else if(thisSum<0)
            thisSum=0;
    }

    return maxSum;
}
