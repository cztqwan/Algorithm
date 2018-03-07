/*
¿ìËÙÅÅĞò
*/
#include <stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];

int partition(int A[],int n,int p,int r)
{
	int x,i,j,t;
	x = A[r];
	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(A[j] <= x)
		{
			i++;
			t = A[i]; A[i] = A[j]; A[j] = t;
		}
	}
	t = A[i+1]; A[i+1] = A[r]; A[r] = t;
	return i+1;
}

void quickSort(int A[],int n,int p,int r)
{
	int q;
	if(p < r)
	{
		q = partition(A, n, p, r);
		quickSort(A, n, p, q - 1);
		quickSort(A, n, q + 1, r);
	}
}

int main()
{
	int A[MAX], n, i;

	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
	}

	quickSort(A, n, 0, n-1);

	for(i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	
	return 0;
}