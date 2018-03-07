/*
ģ�������в�����ʵ��˫������
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����Ľڵ�ṹ��
typedef struct node Node;
struct node
{
	int key;
	Node *next, *prev;
};

Node *nil;

//��ʼ��˫������
void init()
{
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

//��ͷ������ӽڵ�
void insert(int key)
{
	Node *x = (Node *)malloc(sizeof(Node));
	x->key = key;
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

//ɾ���ڵ�
int deleteNode(Node *t)
{
	if(t == nil) return 0;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
	return 1;
}

//ɾ����һ���ڵ�
int deleteFirst()
{
	return deleteNode(nil->next);
}

//ɾ�����һ���ڵ�
int deleteLast()
{
	return deleteNode(nil->prev);
}

//��������
Node* linkSearch(int key)
{
	Node *cur = nil->next;
	while(cur != nil && cur->key != key)
	{
		cur = cur->next;
	}
	return cur;
}

//ɾ��ָ��Ԫ�صĽڵ�
int deleteKey(int key)
{
	return deleteNode(linkSearch(key));
}

//�����������
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
			if(isd)	//����ɹ�ɾ��
			{
				size--;
				nd++;
				isd = 0;
			}
		}
	}
	printf("�����ȣ�%d �ɹ����������%d �ɹ�ɾ��������%d\n",size,np,nd);
	printList();
	
	return 0;
}