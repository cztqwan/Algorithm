/*
ģ��ѭ�����ȷ���������ʵ�ֶ��У�
*/

#include<stdio.h>
#include<string.h>

#define LEN 1000	//���г���

//��������Ľṹ��
typedef struct
{
	char name[100];
	int t;
}P;

P Q[LEN];	//����
int head, tail, n;

//�������
void enqueue(P x)
{
	Q[tail] = x;
	tail = (tail + 1) % LEN;
}

//�Ƴ�����
P dequeue()
{
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int elaps = 0, c;
	int i, q;
	P u;
	
	scanf("%d %d", &n, &q);	//��������������ʱ��Ƭ����
	
	for(i = 0; i < n; i++)
	{
		scanf("%s",Q[i].name);
		scanf("%d",&Q[i].t);
	}
	head = 0; tail = n;
	
	//ģ��ѭ�����ȷ�
	while( head != tail )
	{
		u = dequeue();
		c = min(q, u.t);
		u.t -= c;	//����ʣ�������ʱ��
		elaps += c;	//�ۼ��ѹ���ʱ��
		if(u.t > 0) enqueue(u);
		else printf("%s��%dʱ����\n",u.name, elaps);
	}
		
	return 0;
}