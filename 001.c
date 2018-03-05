/*
某货币在t时刻的价格Rt（t=0,1,2,...,n-1）作为输入数据，计算出价格差Rj-Ri（其中j>i）的最大值。
输入：第1行输入整数n。接下来n行依次给整数Rt（t=0,1,2,...,n-1）赋值。
输出：在单独1行中输出最大值。
限制：2<=n<=200000,1<=Rt<=10^9
*/

#include<stdio.h>

static const int MAX = 200000;

int main()
{
	int R[MAX],i,n,maxv,minv;

	scanf("%d",&n);

	for (i=0; i<n; i++ )
	{
		scanf("%d",&R[i]);
	}

	maxv = -2000000000; minv = R[0];
	for (i=1; i<n; i++ )
	{
		maxv = maxv > R[i]-minv? maxv:R[i]-minv;
		minv = minv < R[i]? minv:R[i];
	}

	printf("最大差为：%d\n",maxv);
	return 0;
}