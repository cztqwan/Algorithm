/*
模拟循环调度法（用数组实现队列）
*/

#include<stdio.h>
#include<string.h>

#define LEN 1000	//队列长度

//代表任务的结构体
typedef struct
{
	char name[100];
	int t;
}P;

P Q[LEN];	//队列
int head, tail, n;

//插入队列
void enqueue(P x)
{
	Q[tail] = x;
	tail = (tail + 1) % LEN;
}

//移出队列
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
	
	scanf("%d %d", &n, &q);	//输入任务数量及时间片长度
	
	for(i = 0; i < n; i++)
	{
		scanf("%s",Q[i].name);
		scanf("%d",&Q[i].t);
	}
	head = 0; tail = n;
	
	//模拟循环调度法
	while( head != tail )
	{
		u = dequeue();
		c = min(q, u.t);
		u.t -= c;	//计算剩余所需的时间
		elaps += c;	//累计已过的时间
		if(u.t > 0) enqueue(u);
		else printf("%s在%d时结束\n",u.name, elaps);
	}
		
	return 0;
}