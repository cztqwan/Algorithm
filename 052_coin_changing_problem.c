/*
硬币问题
*/
#include<stdio.h>
#define MMAX 20
#define NMAX 10000
#define INFTY (1<<29)

int main()
{
	int n, m;
	int C[MMAX+1];
	int T[NMAX+1];
	
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &C[i]);
    }
	
    for (int i = 1; i <= NMAX; i++)
    {
        T[i] = INFTY;
    }
	T[0] = 0;
	
	for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j + C[i] <= n; j++)
		{
			T[j + C[i]] = (T[j + C[i]]) < (T[j] + 1)? (T[j + C[i]]):(T[j] + 1);
		}
    }

    printf("%d\n", T[n]);
	
    return 0;
}