/*
0-1背包问题
*/
#include<stdio.h>
#define NMAX 105
#define WMAX 10005
#define DIAGONAL 1
#define TOP 0

struct Item
{
	int value, weight;
};

int N, W;
struct Item item[NMAX + 1];
int C[NMAX+1][WMAX+1], G[NMAX+1][WMAX+1];

void input()
{
	scanf("%d %d",&N, &W);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d",&(item[i].value), &(item[i].weight));
	}
}

int compute()
{
	for(int w = 0; w <= W; w++)
	{
		C[0][w] = 0;
		G[0][w] = DIAGONAL;
	}
	for(int i = 1;i <= N; i++)	C[i][0] = 0;
	
	for(int i = 1;i <= N; i++)
	{
		for(int w = 1;w <= W; w++)
		{
			C[i][w] = C[i-1][w];
			if(item[i].weight > w)	continue;
			if(item[i].value + C[i-1][w-item[i].weight] > C[i-1][w])
			{
				C[i][w] = item[i].value + C[i-1][w-item[i].weight];
				G[i][w] = DIAGONAL;
			}
		}
	}	
	
	return C[N][W];
}

int main()
{
	int maxValue;
	input();
    maxValue = compute();
    printf("%d\n", maxValue);
	
    return 0;
}