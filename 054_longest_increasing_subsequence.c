/*
最长递增子序列
*/
#include<stdio.h>
#define MAX 100000

int n;
int A[MAX+1],L[MAX];

//L[j]（j=0-length-1）中第一个大于等于a的元素=a
void loweer_bound(int length, int a)
{
	for(int i = 0; i < length; i++)
	{
		if(L[i] >= a)	L[i] = a;
	}
}

int lis()
{
	L[0] = A[0];
	int length = 1;
	
	for(int i = 1; i < n; i++)
	{
		if(L[length-1] < A[i])
			L[length++] = A[i];
		else
			loweer_bound(length,A[i]);
	}
	return length;
}

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&A[i]);
	}
	
    printf("%d\n", lis());
	
    return 0;
}