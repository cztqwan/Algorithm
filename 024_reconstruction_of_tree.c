/*
Ê÷µÄÖØ½¨
*/
#include <stdio.h>
#define MAX 1000

int n, pos1, pos2;
int pre[MAX], in[MAX], post[MAX];

int find(int u)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(in[i] == u)
			return i;
	}
	return -1;
}

void rec(int l, int r)
{
	if(l >= r)	return;
	int root = pre[pos1++];
	int m = find(root);
	rec(l, m);
	rec(m+1, r);
	post[pos2++] = root;
}

void solve()
{
	int i;
	pos1 = 0;
	pos2 = 0;
	rec(0, n);
	for(i = 0; i < n; i++)
	{
		if(i) printf(" ");
		printf("%d",post[i]);
	}
	printf("\n");
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	
	solve();
	
	return 0;
}
