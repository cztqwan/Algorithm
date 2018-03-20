/*
¾ØÕóÁ´³Ë·¨
*/
#include <stdio.h>
#define N 100
#define min(a,b) a < b ? a : b

int matrixChainMultplication(int *p,int n)
{
	int i, j, l,k, m[N+1][N+1];
	for(i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for(l = 2; l <= n; l++)
	{
		for(i = 1; i <= n-l+1; i++)
		{
			j = i + l - 1;
			m[i][j] = (1<<21);
			for(k = i; k <= j-1; k++)
			{
				m[i][j] = min(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
			}
		}
	}
	return m[1][n];
}

int main()
{
	int i, n, p[N+1],res;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &p[i-1], &p[i]);
	}

	res = matrixChainMultplication(p,n);
	
	printf("%d\n",res);
	
	return 0;
}