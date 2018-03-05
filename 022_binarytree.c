/*
二叉树的表达
*/
#include <stdio.h>

#define MAX 10000
#define NIL -1

typedef struct Node
{
	int parent, left, right;
}Node;

Node T[MAX];
int n, D[MAX], H[MAX];

//返回兄弟节点
int getSibling(int u)
{
	if(T[u].parent == NIL)
		return NIL;
	if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
		return T[T[u].parent].left;
	if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
		return T[T[u].parent].right;
	return NIL;
}

void print(int u)
{
	int deg = 0, c;
	printf("node %d: ",u);
	printf("parent = %d, ",T[u].parent);
	printf("sibling = %d, ",getSibling(u));
	
	if(T[u].left != NIL)	deg++;
	if(T[u].right != NIL)	deg++;
	printf("degree = %d, ",deg);
	printf("depth = %d, ",D[u]);
	printf("height = %d, ",H[u]);
	
	if(T[u].parent == NIL)
	{
		printf("root\n");
	}
	else if(T[u].left == NIL && T[u].right == NIL)
	{
		printf("leaf\n");
	}
	else
	{
		printf("internal node\n");
	}
}

//递归求深度
void setDepth(int u,int d)
{
	if(u == NIL)	return;
	D[u] = d;
	setDepth(T[u].left, d+1);
	setDepth(T[u].right, d+1);
}

//递归求高
int setHeight(int u)
{
	int h1 = 0, h2 = 0;
	if(T[u].left != NIL)
		h1 = setHeight(T[u].left)+1;
	if(T[u].right != NIL)
		h2 = setHeight(T[u].right)+1;
	return H[u] = (h1 > h2? h1 : h2);
}

int main()
{
	int i, j, root, v, l, r;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		T[i].parent = T[i].left = T[i].right = NIL;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &v, &l, &r);
		T[v].left = l;
		T[v].right = r;
		if(l != NIL)	T[l].parent = v;
		if(r != NIL)	T[r].parent = v;
	}
	for(i = 0; i < n; i++)
	{
		if(T[i].parent == NIL)	root = i;
	}
	
	setDepth(root, 0);
	setHeight(root);

	for(i = 0; i < n; i++)
		print(i);
	while(1);
	return 0;
}
/*
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
*/