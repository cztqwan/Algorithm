/*
ð������
*/

#include<stdio.h>

//��˳���������Ԫ��
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

//ð������
void bubbleSort(int A[], int N)
{
	int i, j, v;
	int flag = 1;
	for(i = 0; flag; i++)
	{
		flag = 0;
		for(j = N-1; j >= i+1; j--)
		{
			if(A[j] < A[j-1])
			{
				v = A[j];	//��������Ԫ��
				A[j] = A[j-1];
				A[j-1] = v;
				flag = 1;
			}
		}
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
	bubbleSort(A,N);
	
	return 0;
}