/*
优先级队列
*/
#include <stdio.h>
#define MAX 100000
#define INFIY (1<<30)

int H, A[MAX+1];
	
void maxHeapify(int i)
{
	int l, r, largest,t;
	l = 2 * i;
	r = 2 * i + 1;
	
	if(l <= H && A[l] > A[i])
		largest = l;
	else
		largest = i;
	
	if(r <= H && A[r] > A[largest])
		largest = r;
	
	if(largest != i)
	{
		t = A[i]; A[i] = A[largest]; A[largest] = t;
		maxHeapify(largest);
	}
}

int extract()
{
	int maxv;
	if(H < 1)
		return -INFIY;
	maxv = A[1];
	A[1] = A[H--];
	maxHeapify(1);
	return maxv;
}

void increaseKey(int i, int key)
{
	int t;
	if(key < A[i])
		return;
	A[i] = key;
	while(i > 1 && A[i/2] < A[i])
	{
		t = A[i]; A[i] = A[i/2]; A[i/2] = t;
		i = i/2;
	}
}

void insert(int key)
{
	H++;
	A[H] = -INFIY;
	increaseKey(H,key);
}

int main()
{
	int key;
	char com[10];
	while(1)
	{
		scanf("%s",com);
		if(com[0] == 'e' && com[1] == 'n')
			break;
		if(com[0] == 'i')
		{
			scanf("%d",&key);
			insert(key);
		}
		else
		{
			printf("%d\n",extract());
		}
	}
	return 0;
}