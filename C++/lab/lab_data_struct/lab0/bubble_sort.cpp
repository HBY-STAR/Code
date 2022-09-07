#include<iostream>
#include<vector>

using namespace std;

int bubbleSort(vector<int> &nums)
{
    int length=nums.size();
    int temp;
    for(int i=0;i<length;i++)
    {
        for(int j=length-1;j>i;j--)
        {
            if(nums[j]>nums[j-1])
            {
                temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
        }
    }
    return 0;
}

int main()
{
    vector<int> nums(10);
    for(int i=0;i<10;i++)
    {
        nums[i]=i;
    }
    bubbleSort(nums);
    for(int i=0;i<10;i++)
    {
        cout<<nums[i]<<"  ";
    }
    return 0;
}



