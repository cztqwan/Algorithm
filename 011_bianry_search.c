/*
��������
*/

#include<stdio.h>

//��������
int binarySearch(int A[], int N, int key)
{
	int left = 0;
	int right = N;
	int mid;
	while(left < right)
	{
		mid = (left + right)/2;
		if(key == A[mid])	return 1;	//����key
		if(key > A[mid])	left = mid+1;	//������벿��
		else if(key < A[mid])	right = mid;	//����ǰ�벿��
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