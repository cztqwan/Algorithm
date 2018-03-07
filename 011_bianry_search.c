/*
二分搜素
*/

#include<stdio.h>

//线性搜索
int binarySearch(int A[], int N, int key)
{
	int left = 0;
	int right = N;
	int mid;
	while(left < right)
	{
		mid = (left + right)/2;
		if(key == A[mid])	return 1;	//发现key
		if(key > A[mid])	left = mid+1;	//搜索后半部分
		else if(key < A[mid])	right = mid;	//搜索前半部分
	}
	return 0;
}

int main()
{
	int i, N, A[100],q,key,sum = 0;
	
	scanf("%d",&N);

	for (i=0; i<N; i++ )
	{
		scanf("%d",&A[i]);
	}

	scanf("%d",&q);

	for (i=0; i<q; i++ )
	{
		scanf("%d",&key);
		if(binarySearch(A, N, key)) sum++;
	}
	
	printf("%d\n",sum);
	
	return 0;
}