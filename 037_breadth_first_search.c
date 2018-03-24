/*
广度优先搜索
*/
#include <stdio.h>
#define N 100
#define INFTY (1<<21)

int n, M[N][N];
int d[N];	//距离

/***********************Queue*************************/
#define LEN 1000	//队列长度

int Q[LEN];	//队列
int head = 0, tail = 0;

//插入队列
void enqueue(int x)
{
	Q[tail] = x;
	tail = (tail + 1) % LEN;
}

//移出队列
int dequeue()
{
	int x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

//队列是否为空
int emptyqueue()
{
	return (head == tail);
}
/*************************END**************************/

void bfs(int s)
{
	int i, u, v;
	enqueue(s);
	for(i = 0; i < n; i++)
	{
		d[i] = INFTY;
	}
	d[s] = 0;
	while( !emptyqueue() )
	{
		u = dequeue();
		for( v = 0; v < n; v++)
		{
			if( M[u][v] == 0)	continue;
			if( d[v] != INFTY)	continue;
			d[v] = d[u] + 1;
			enqueue(v);
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%d %d\n", i+1, ((d[i] == INFTY) ? (-1) : (d[i])));
	}
}

int main()
{
	int i, j, u, k, v;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = 0;
		}
	}
	
	for(i = 0; i < n; i++)
	{
		scanf("%d %d",&u, &k);
		u--;
		for(j = 0; j < k; j++)
		{
			scanf("%d",&v);
			v--;
			M[u][v] = 1;
		}
	}
	bfs(0);
	return 0;
}
/*
4
1 2 2 4
2 1 4
3 0
4 1 3
*/