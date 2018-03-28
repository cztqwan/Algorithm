/*
单源最短路径（邻接矩阵）
*/
#include <stdio.h>

#define MAX 100
#define INFTY (1<<21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[MAX][MAX];

void dijkstra()
{
	int i, minv, u, v;
	int d[MAX], color[MAX];
	
	for(i = 0; i < n; i++)
	{
		d[i] = INFTY;
		color[i] = WHITE;
	}
	
	d[0] = 0;
	color[0] = GRAY;
	while(1)
	{
		minv = INFTY;
		u = -1;
		for(i = 0; i < n; i++)
		{
			if(minv > d[i] && color[i] != BLACK)
			{
				u = i;
				minv = d[i];
			}
		}
		if(u == -1) break;
		color[u] = BLACK;
		for(v = 0; v < n; v++)
		{
			if(color[v] != BLACK && M[u][v] != INFTY)
			{
				
				if(d[v] > d[u]+M[u][v])
				{
					d[v] = d[u]+M[u][v];
					//printf("%d=%d\n",v,d[v]);
					color[v] = GRAY;
				}
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%d %d\n",i,( (d[i] == INFTY)? -1 : d[i]));
	}
}

int main()
{
	int i, j;
	int k, c, u, v;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = INFTY;
		}
	}
	
	for(i = 0; i < n; i++)
	{
		scanf("%d %d",&u, &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d %d",&v, &c);
			M[u][v] = c;
		}
	}
	
	dijkstra();
	
	return 0;
}
/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
*/