/*
最小成本排序
*/
#include <stdio.h>

#define MAX 1000
#define VMAX 10000
#define min(a,b) (a < b ? a : b)

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

//冒泡排序
void sort(int A[], int N)
{
	int i, j, v;
	int flag = 1;
	for(i = 0; flag; i++)
	{
		flag = 0;
		for(j = N-1; j >= i+1; j--)
		{
			if(A[j] < A[j-1])
			{
				v = A[j];	//交换相邻元素
				A[j] = A[j-1];
				A[j-1] = v;
				flag = 1;
			}
		}
	}
}

int solve()
{
	int i,ans = 0;
	int V[MAX];

	for(i = 0; i < n; i++)
	{
		B[i] = A[i];
		V[i] = 0;
	}
	sort(B,n);//排序
	for(i = 0; i < n; i++)
		T[B[i]] = i;	//元素应该在的位置
	for(i = 0; i < n; i++)
	{
		if(V[i] == 1)	continue;
		int cur = i;
		int S = 0;
		int m = VMAX;
		int an = 0;
		while(1)	//找圆圈
		{
			V[cur] = 1;
			an++;
			int v = A[cur];
			m = min(m, v);
			S += v;
			cur = T[v];		
			if(V[cur] == 1)	break;
		}
		ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
	}
	return ans;
}

int main()
{
	int ans, i;
	scanf("%d",&n);
	s = VMAX;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
		s = min(s,A[i]);
	}

	ans = solve();
	
	printf("%d\n",ans);
	
	return 0;
}