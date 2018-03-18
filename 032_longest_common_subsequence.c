/*
最长公共子序列
*/
#include <stdio.h>
#include <string.h>
#define N 100

void insert(char *str, char *pch, int pos) {
	int i;
    int len = strlen(str);
	int n = strlen(pch);
    for (i = len - 1; i >= pos; --i) {
        *(str + i + n) = *(str + i);
    }
	for (i = 0; i < n; i++) {
        *(str + pos + i) = *(pch + i);
    }
    *(str + len + n) = 0;
}

int lcs(char *X,char *Y)
{
	int i,j;
	int c[N+1][N+1];
	int m = strlen(X);
	int n = strlen(Y);
	int maxl = 0;
	char space[2] = " ";
	insert(X,space,0);
	insert(Y,space,0);

	for(i = 1; i <= m; i++)
		c[i][0] = 0;
	for(j = 1; j <= n; j++)	
		c[0][j] = 0;		
	
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)	
		{
			if(X[i] == Y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else
			{
				c[i][j] = c[i-1][j] > c[i][j-1] ? c[i-1][j] : c[i][j-1];
			}
			maxl = maxl > c[i][j] ? maxl:c[i][j];
		}
		return maxl;
}

int main()
{
	int n,i;
	char X[100],Y[100];

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", X);
		scanf("%s", Y);
		printf("%d\n",lcs(X,Y));
	}

	return 0;
}