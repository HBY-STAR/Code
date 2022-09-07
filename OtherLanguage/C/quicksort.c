#include<stdio.h>

int fast(int* y,int begin,int end)
{
	int temp=y[begin];
	//将结尾位置保存一下,因为之后的运算会改变end值,end会逐渐向前移动
	//,而最后递归的时候end还得是数组的尾元素,不能发生变化
	int endTemp=end;
	//设定递归条件,左右不可相等(重合)如果相等那就return
	if(end>begin)
	{
		//循环条件,左右不可相等(重合),如果相等,那就一次排序分组完毕,开始将分好的两组数组再递归进行排序
		while(begin<end)
		{
			//向左移动
			while((begin<end)&&(temp<=y[end]))
				end--;
			y[begin]=y[end];
			//向右移动
			while((begin<end)&&(temp>y[begin]))
				begin++;
			y[end]=y[begin];
		}
		//基准元素放到中间左右重合的位置上
		y[begin]=temp;
		//分组递归,前一组数组为首元素到
		fast(y,0,begin-1);
		fast(y,begin+1,endTemp);
	}
	return 0;
}


int main()
{
	int y[]={22,12,1,33,17,5,10,89,88,30,21,11,11};
	fast(y,0,(sizeof(y)/sizeof(int))-1);
	for(int i=0;i<sizeof(y)/sizeof(int);i++)
		printf("%d ",y[i]);
	return 0;
}
