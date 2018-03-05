/*
树的遍历
*/
#include <stdio.h>

#define MAX 10000
#define NIL -1

typedef struct Node
{
	int parent, left, right;
}Node;

Node T[MAX];
int n;

//前序遍历
void preParse(int u)
{
	if(u == NIL)	return;
	printf(" %d",u);
	preParse(T[u].left);
	preParse(T[u].right);
}

//中序遍历
void inParse(int u)
{
	if(u == NIL)	return;
	inParse(T[u].left);
	printf(" %d",u);
	inParse(T[u].right);
}

//后序遍历
void postParse(int u)
{
	if(u == NIL)	return;
	postParse(T[u].left);
	postParse(T[u].right);
	printf(" %d",u);
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
	
	printf("Preorder\n");
	preParse(root);
	printf("\n");
	
	printf("Inorder\n");
	inParse(root);
	printf("\n");
	
	printf("Postorder\n");
	postParse(root);
	printf("\n");
	
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