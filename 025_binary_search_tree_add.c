/*
¶ş²æËÑË÷Ê÷¡ª¡ª²åÈë
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int key;
	struct Node *right, *left, *parent;
}Node;

Node *root, *NIL;

void insert(int k)
{
	Node *y = NIL;
	Node *x = root;
	Node *z;
	
	z = (Node *)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;
	
	while( x != NIL )
	{
		y = x;
		if( z->key < x->key )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL )
	{
		root = z;
	}
	else{
		if( z->key < y->key )
		{
			y->left = z;
		}
		else{
			y->right = z;
		}
	}
}

void inorder(Node *u)
{
	if(u == NIL)	return;
	inorder(u->left);
	printf(" %d", u->key);
	inorder(u->right);
}

void preorder(Node *u)
{
	if(u == NIL)	return;
	printf(" %d", u->key);
	preorder(u->left);
	preorder(u->right);
}

void postorder(Node *u)
{
	if(u == NIL)	return;
	postorder(u->left);
	postorder(u->right);
	printf(" %d", u->key);
}

int main()
{
	int i, n, x;
	char com[7];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", com);
		if( strcmp(com,"insert")==0 )
		{
			scanf("%d", &x);
			insert(x);
		}
		else if( strcmp(com,"print")==0 )
		{
			preorder(root);
			printf("\n");
			inorder(root);
			printf("\n");
			postorder(root);
			printf("\n");
		}
	}
	while(1);
	return 0;
}
/*
8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
print
*/