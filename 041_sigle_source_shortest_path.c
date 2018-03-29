/*
单源最短路径（优先级队列）
*/
#include <stdio.h>
#define N 100
#define MAX 100
#define INFTY (1<<21)
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct Node
{
	int first;
	int second;
}Node;

/***********************priority_queue*********************/
int H = 0;
Node A[MAX+1];
	
void maxHeapify(int i)
{
	int l, r, largest;
	Node t;
	l = 2 * i;
	r = 2 * i + 1;
	
	if(l <= H && A[l].first > A[i].first)
		largest = l;
	else
		largest = i;
	
	if(r <= H && A[r].first > A[largest].first)
		largest = r;
	
	if(largest != i)
	{
		t.first = A[i].first;
		t.second = A[i].second;
		A[i].first = A[largest].first;
		A[i].second = A[largest].second;
		A[largest].first = t.first;
		A[largest].second = t.second;
		maxHeapify(largest);
	}
}

Node extract()
{
	Node maxv;
	maxv.first = -INFTY;
	maxv.second = -INFTY;
	if(H < 1)
		return maxv;
	maxv.first = A[1].first;
	maxv.second = A[1].second;
	A[1].first = A[H--].first;
	A[1].second = A[H--].second;
	maxHeapify(1);
	return maxv;
}

void increaseKey(int i, Node key)
{
	Node t;
	if(key.first < A[i].first)
		return;
	A[i].first = key.first;
	A[i].second = key.second;
	while(i > 1 && A[i/2].first < A[i].first)
	{
		t.first = A[i].first;
		t = A[i];
		A[i].first = A[i/2].first;
		A[i].second = A[i/2].second;
		A[i/2].first = t.first;
		A[i/2].second = t.second;
		i = i/2;
	}
}

void insert(Node key)
{
	H++;
	A[H].first = -INFTY;
	A[H].second = -INFTY;
	increaseKey(H,key);
}

int isempty()
{
	if(H < 1)
		return 1;
	return 0;
}
/***************************END****************************/
//邻接表
typedef struct vector
{
	Node num[N];
	int size;
} vector;

int n;
vector adj[MAX];

void dijkstra()
{
	int i, j, u ,v;
	int color[MAX];
	int d[MAX];
	Node pair,f;
	
	for(i = 0; i < n; i++)
	{
		d[i] = INFTY;
		color[i] = WHITE;
	}
	
	d[0] = 0;
	pair.first = 0;
	pair.second = 0;
	insert(pair);
	color[0] = GRAY;
	while(!isempty())
	{
		f = extract();
		u = f.second;
		color[u] = BLACK;
		
		if(d[u] < f.first*(-1))	continue;
		
		for(j = 0; j < adj[u].size; j++)
		{
			v = adj[u].num[j].first;
			if(color[v] == BLACK)	continue;
			if(d[v] > d[u] + adj[u].num[j].second)
			{
				d[v] = d[u] + adj[u].num[j].second;
				pair.first = d[v]*(-1);
				pair.second = v;
				insert(pair);
				color[v] = 	GRAY;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%d %d\n",i,( (d[i] == INFTY)? -1 : d[i]));
	}
}

int main()
{
	int i, j, k, u, v, c;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		adj[i].size = 0;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d %d",&u, &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d %d",&v, &c);
			adj[u].num[adj[u].size].first = v;
			adj[u].num[adj[u].size].second = c;
			adj[u].size++;
		}
	}
	dijkstra();
	return 0;
}
/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
*/