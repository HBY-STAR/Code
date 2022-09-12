#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
    if(a<=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maxArea(vector<int> &height)
{
    int length=height.size();
    int max_area=0;
    int temp_area;
    for(int i=0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            temp_area=(j-i)*min(height[i],height[j]);
            if(temp_area>max_area)
            {
                max_area=temp_area;
            }
        }
    }
    return max_area;
}

int main()
{
    int h[9]={1,8,6,2,5,4,8,3,7};
    vector<int> height(h,h+9);
    int max=maxArea(height);

    return 0;
}