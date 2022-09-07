#include<stdio.h>
void solution(int A[10][10], int n)
{
	int i, j, k;
	i = 0;
	//n需要为基数
	if (n % 2 == 0) n++;
	j = n / 2;
	A[i][j] = 1;
	for (k = 2; k <= 25; ++k) {
		int i0, j0;
		//下一数在上一数的右上方，越界就回到起始行/列
		i0 = (i - 1 >= 0) ? (i - 1) : (n - 1);//必须大于等于0，临界点包括0
		j0 = (j + 1 < n) ? (j + 1) : 0;
		//上一数为n的倍数，下一数在上一数下方
		if ((k - 1 )% n == 0) {//上一个数是n的整数倍，下一个数在上一个数下面；求余运算要括号
			i0 = (i + 1 < n) ? (i + 1) : 0;
			j0 = j;
		}
		//放置下一数
		A[i0][j0] = k;
		//记录下一数位置
		i = i0;
		j = j0;
	}
}
int main() {
	int A[10][10];
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			A[i][j] = 0;
	solution(A, 5);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
