/*
ĳ������tʱ�̵ļ۸�Rt��t=0,1,2,...,n-1����Ϊ�������ݣ�������۸��Rj-Ri������j>i�������ֵ��
���룺��1����������n��������n�����θ�����Rt��t=0,1,2,...,n-1����ֵ��
������ڵ���1����������ֵ��
���ƣ�2<=n<=200000,1<=Rt<=10^9
*/

#include<stdio.h>

static const int MAX = 200000;

int main()
{
	int i,j,R[MAX],n,maxv;

	scanf("%d",&n);

	for (i=0; i<n; i++ )
	{
		scanf("%d",&R[i]);
	}

	maxv = -2000000000;
	for (i=1; i<n; i++)
		for (j=0; j<i; j++ )
			maxv = maxv > (R[i]-R[j])? maxv:(R[i]-R[j]);

	printf("����Ϊ��%d\n",maxv);
	return 0;
}