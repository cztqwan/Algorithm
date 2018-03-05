/*
线性搜素
*/

#include<stdio.h>

//线性搜索
int search(int A[], int N, int key)
{
	int i = 0;
	A[N] = key;
	while(A[i] != key)	i++;
	return i != N;
}

int main()
{
	int i, N, A[100+1],q,key,sum = 0;
	
	scanf("%d",&N);

	for (i=0; i<N; i++ )
	{
		scanf("%d",&A[i]);
	}

	scanf("%d",&q);

	for (i=0; i<q; i++ )
	{
		scanf("%d",&key);
		if(search(A, N, key)) sum++;
	}
	
	printf("%d\n",sum);
	
	return 0;
}