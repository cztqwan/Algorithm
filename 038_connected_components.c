/*
连通分量
*/
#include <stdio.h>
#define N 100
#define MAX 1000
#define NIL -1

//邻接表
typedef struct vector
{
	int num[N];
	int size;
} vector;

/************************STACK*************************/
int top = 0,S[500];

//入栈操作
void push(int x)
{
	//top+1后将元素插入top所指的位置
	S[++top] = x;
}

//出栈操作
int pop()
{
	top--;
	return S[top+1];	//返回原来top所指的原素
}

int empty()
{
	if(top == 0)
		return 1;
	else
		return 0;
}
/*************************END**************************/

int n;
vector G[MAX];
int color[MAX];

void dfs(int r, int c)
{
	int i, u, v;

	push(r);
	color[r] = c;
	while( !empty() )
	{
		u = pop();

		for(i = 0; i < G[u].size; i++)
		{
			int v = G[u].num[i];
			if(color[v] == NIL)
			{
				color[v] = c;
				push(v);
			}
		}
	}
}

void assignColor()
{
	int i,u;
	int id = 1;
	for(i = 0; i < n; i++)
		color[i] = NIL;
	for(u = 0; u < n; u++)
	{
		if(color[u] == NIL)
			dfs(u,id++);
	}
}

int main()
{
	int i, j, s, t, m, q;

	scanf("%d %d",&n, &m);
	
	for(i = 0; i < n; i++)
	{
		G[i].size = 0;
	}

	for(i = 0; i < m; i++)
	{
		scanf("%d %d",&s, &t);
		G[s].num[G[s].size] = t;
		G[s].size++;
		G[t].num[G[t].size] = s;
		G[t].size++;
	}
	
	assignColor();
	
	scanf("%d",&q);
	for(i = 0; i < q; i++)
	{
		scanf("%d %d",&s, &t);
		if(color[s]==color[t])
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
/*
10 9
0 1
0 2
3 4
5 7
6 7
6 8
7 8
8 9
3
0 1
5 9
1 3
*/