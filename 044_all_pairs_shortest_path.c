/*
所有点对间最短路径（弗洛伊德算法）
*/
#include <stdio.h>
#define MAX 100
#define INFTY (1<<21)

int n;
int d[MAX][MAX];

void floyd()
{
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			if(d[i][k] == INFTY)	continue;
			for(int j = 0; j < n; j++)
			{
				if(d[k][j] == INFTY)	continue;
				d[i][j] = (d[i][j] < (d[i][k] + d[k][j])) ? d[i][j] : (d[i][k] + d[k][j]);
			}
		}
	}
}

int main()
{
	int e, u, v, c;
	int negative = 0;
	scanf("%d %d", &n, &e);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			d[i][j] = ((i == j) ? 0 : INFTY);
		}
	}
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d %d",&u, &v, &c);
		d[u][v] = c;
	}
	
	floyd();
	for(int i = 0; i < n; i++)
		if(d[i][i] < 0)	negative = 1;
	
	if(negative == 1)
	{
		printf("NEGATIVE CYCLE\n");
	}	
	else
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(j)	printf(" ");
				if(d[i][j] == INFTY)	printf("%d %d INF",i,j);
				else	printf("%d",d[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
/*
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
*/