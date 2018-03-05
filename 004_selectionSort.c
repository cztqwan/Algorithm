/*
选择排序
*/

#include<stdio.h>

//按顺序输出数组元素
void trace(int A[], int N)
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(i > 0)	printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

//选择排序
void selectionSort(int A[], int N)
{
	int i, j, v, minj;
	int flag = 1;
	for(i = 0; i < N-1; i++)
	{
		minj = i;
		for(j = i; j < N; j++)
		{
			if(A[j] < A[minj]) minj = j;
		}
		v = A[i]; A[i] = A[minj]; A[minj] = v;
		trace(A,N);
	}
}

int main()
{
	int N, i, j;
	int A[100];

	scanf("%d",&N);

	for (i=0; i<N; i++ )
	{
		scanf("%d",&A[i]);
	}

	trace(A,N);
	selectionSort(A,N);
	
	return 0;
}