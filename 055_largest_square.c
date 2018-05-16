/*
最大正方形
*/
#include<stdio.h>
#define MAX 1000
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int n;
int dp[MAX][MAX],G[MAX][MAX];

int getlargestSquare(int H, int W)
{
	int maxWidth = 0;
	int length = 1;
	
	//初始化
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
		{
			dp[i][j] = (G[i][j]+1) % 2;//1代表是干净的一个正方形，0代表脏的
			maxWidth |= dp[i][j];
		}
	}
	
	for(int i=1; i<H; i++)
	{
		for(int j=1; j<W; j++)
		{
			if(G[i][j])
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				maxWidth = max(maxWidth, dp[i][j]);
			}
		}
	}
	
	return maxWidth*maxWidth;
}

int main()
{
	int H, W;
	scanf("%d %d",&H, &W);
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
			scanf("%d",&G[i][j]);
	}
	
    printf("%d\n", getlargestSquare(H, W));
	
    return 0;
}