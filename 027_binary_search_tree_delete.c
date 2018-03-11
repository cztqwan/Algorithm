/*
¶þ²æËÑË÷Ê÷¡ª¡ªÉ¾³ý
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

Node * find(Node *u, int k)
{
	while( u != NIL && k != u->key )
	{
		if(k < u->key)
			u = u->left;
		else
			u = u->right;
	}
	return u;
}

Node * treeMinimum(Node *x)
{
	while( x->left != NIL)
		x = x->left;
	return x;
}

Node * treeSuccessor(Node *x)
{
	if(x->right != NIL)
		return treeMinimum(x->right);
	Node *y = x->parent;
	while(y != NIL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

void treeDelete(Node *z)
{
	Node *y;
	Node *x;
	
	if( z->left == NIL || z->right == NIL )	
		y = z;
	else
		y = treeSuccessor(z);
	if(y->left != NIL)
	{
		x = y->right;
	}
	else
	{
		x = y->right;
	}
	
	if(x != NIL)
	{
		x->parent = y->parent;
	}
	
	if(y->parent == NIL)
	{
		root = x;
	}
	else
	{
		if(y == y->parent->left)
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}
	}
	
	if( y != z )
	{
		z->key = y->key;
	}
	
	free(y);
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
		else if( strcmp(com,"find")==0 )
		{
			scanf("%d", &x);
			Node *t = find(root, x);
			if(t!=NIL)	printf("yes\n");
			else	printf("no\n");
		}
		else if( strcmp(com,"delete")==0 )
		{
			scanf("%d", &x);
			treeDelete(find(root, x));
		}
	}
	while(1);
	return 0;
}
/*
18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
print
*/