/*
希尔排序
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

//指定间隔g的插入排序
void insertionSort(int A[], int N, int g)
{
	int i,j,v;
	for(i = g; i < N; i++)
	{
		v = A[i];
		j = i - g;
		while(j >= 0 && A[j] > v)
		{
			A[j+g] = A[j];
			j -= g;
		}
		A[j+g] = v;
	}
}

//生成数列
int createG(int N, int G[])
{
	int h,len=0;
	for(h = 1; ; )
	{
		if(h > N)	break;
		G[len++] = h;
		h = 3*h+1;
	}
	return len;
}

//希尔排序
void shellSort(int A[], int N, int G[])
{
	int i,G_len;
	G_len = createG(N,G);
	for(i = G_len-1; i >=0 ; i--)
	{
		insertionSort(A,N,G[i]);
		trace(A,N);
	}
}

int main()
{
	int N, i, j;
	int A[100],G[100];

	scanf("%d",&N);

	for (i=0; i<N; i++ )
	{
		scanf("%d",&A[i]);
	}

	trace(A,N);
	shellSort(A,N,G);
	
	return 0;
}