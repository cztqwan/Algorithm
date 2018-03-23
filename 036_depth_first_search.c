/*
�����������(ջʵ��)
*/
#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;
int nt[N];

/************************STACK*************************/
int top = 0,S[500];

//��ջ����
void push(int x)
{
	//top+1��Ԫ�ز���top��ָ��λ��
	S[++top] = x;
}

//��ջ����
int pop()
{
	top--;
	return S[top+1];	//����ԭ��top��ָ��ԭ��
}

int empty()
{
	if(top == 0)
		return 1;
	else
		return 0;
}
/*************************END**************************/

//�����˳���ȡ��u���ڵ�v
int next(int u)
{
	int v;
	for(v = nt[u]; v < n; v++)
	{
		nt[u] = v + 1;
		if(M[u][v])
			return v;
	}
	return -1;
}

void dfs_visit(int r)
{
	int i, u, v;
	for(i = 0; i < n; i++)
		nt[i] = 0;
	
	push(r);
	color[r] = GRAY;
	d[r] = ++tt;	//�������ʱ��
	while( !empty() )
	{
		u = S[top];
		v = next(u);
		if(v != -1)
		{
			if(color[v] == WHITE)
			{
				color[v] = GRAY;
				d[v] = ++tt;
				push(v);
			}
		}
		else
		{
			pop();
			color[u] = BLACK;
			f[u] = ++tt;
		}
	}
}

void dfs()
{
	int u;
	for(u = 0; u < n; u++)
	{
		color[u] = WHITE;
	}
	tt = 0;
	
	for(u = 0; u < n; u++)
	{
		if(color[u] == WHITE)
		{
			dfs_visit(u);
		}
	}
	for(u = 0; u < n; u++)
	{
		printf("%d %d %d\n", u+1, d[u], f[u]);
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
	dfs();
	return 0;
}
/*
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
*/