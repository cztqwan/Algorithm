/*
模拟命令行操作（实现双向链表）
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链表的节点结构体
typedef struct node Node;
struct node
{
	int key;
	Node *next, *prev;
};

Node *nil;

//初始化双向链表
void init()
{
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

//在头结点后添加节点
void insert(int key)
{
	Node *x = (Node *)malloc(sizeof(Node));
	x->key = key;
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

//删除节点
int deleteNode(Node *t)
{
	if(t == nil) return 0;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
	return 1;
}

//删除第一个节点
int deleteFirst()
{
	return deleteNode(nil->next);
}

//删除最后一个节点
int deleteLast()
{
	return deleteNode(nil->prev);
}

//搜索链表
Node* linkSearch(int key)
{
	Node *cur = nil->next;
	while(cur != nil && cur->key != key)
	{
		cur = cur->next;
	}
	return cur;
}

//删除指定元素的节点
int deleteKey(int key)
{
	return deleteNode(linkSearch(key));
}

//输出链表内容
void printList()
{
	Node *cur = nil->next;
	int isf = 0;
	while(1)
	{
		if(cur == nil) break;
		if(isf++ > 0) printf(" ");
		printf("%d",cur->key);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	int key, n, i;
	int size = 0;
	char com[20];
	int np = 0, nd = 0, isd = 0;
	scanf("%d",&n);
	init();
	
	for(i = 0 ;i < n; i++)
	{
		scanf("%s%d",com, &key);
		if(com[0] == 'i')
		{
			insert(key);
			np++;
			size++;
		}
		else if(com[0] == 'd')
		{
			if(strlen(com) > 6)
			{
				if(com[6] == 'F')
					isd = deleteFirst();
				else
					isd = deleteLast();
			}
			else
			{
				isd = deleteKey(key);
				
			}
			if(isd)	//如果成功删除
			{
				size--;
				nd++;
				isd = 0;
			}
		}
	}
	printf("链表长度：%d 成功插入次数：%d 成功删除次数：%d\n",size,np,nd);
	printList();
	
	return 0;
}