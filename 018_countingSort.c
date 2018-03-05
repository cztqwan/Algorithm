/*
¼ÆÊýÅÅÐò
*/
#include <stdio.h>

#define MAX 200000
#define VMAX 10000

int C[VMAX+1];

void countingSort(int A[],int B[],int n)
{
	int i,max = 0;
	for(i = 0; i < n; i++)
	{
		if(A[i] > max) max = A[i];
		C[A[i]]++;
	}
	for(i = 1; i <= max; i++)
	{
		C[i] = C[i] + C[i-1];
	}
	for(i = 0; i < n; i++)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

int main()
{
	int A[MAX],B[MAX], n, i;

	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
	}

	countingSort(A, B, n);

	for(i = 0; i < n; i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");
	
	return 0;
}