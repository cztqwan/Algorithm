/*
最小生成树
*/
#include <stdio.h>
#define MAX 100
#define INFTY (1<<21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[MAX][MAX];
int color[MAX];

int prim()
{
	int i, u, v, minv;
	int d[MAX], p[MAX], color[MAX];
	
	for(i = 0; i < n; i++)
	{
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}
	
	d[0] = 0;	
	
	while( 1 )
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
		if( u == -1) break;
		color[u] = BLACK;
		
		for(v = 0; v < n; v++)
		{
			if(color[v] != BLACK && M[u][v] != INFTY)
			{
				if(d[v] > M[u][v])
				{
					d[v] = M[u][v];
					p[v] = u;
					color[v] = GRAY;
				}
			}
		}
	}
}

int main()
{
	int i, j, e;

	scanf("%d",&n);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d",&e);
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}

	printf("%d\n",prim());
	return 0;
}
/*
5
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1
*/