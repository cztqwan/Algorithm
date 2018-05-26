/*
最大长方形
*/
#include<stdio.h>
#define MAX 1000
#define max(a,b)	(a)>(b)?(a):(b)

typedef struct Rectangle
{
	int height;
	int pos;
}Rectangle;

/*******************************STACK********************************/
int top;
Rectangle S[MAX];

//入栈操作
void push(Rectangle x)
{
	//top+1后将元素插入top所指的位置
	S[++top] = x;
}

//出栈操作
Rectangle pop()
{
	top--;
	return S[top+1];	//返回原来top所指的原素
}

//栈是否为空
int isempty()
{
	return (top == 0);
}
/********************************END*********************************/

int H, W;
int buffer[MAX][MAX],T[MAX][MAX];

int getlargestRectangle(int size, int buffer[])
{
	int maxv = 0;
	buffer[size] = 0;
	
	//初始化
	for(int i=0; i<size; i++)
	{
		Rectangle rect;
		rect.height = buffer[i];
		rect.pos = i;
		if(isempty())
		{
			push(rect);
		}
		else
		{
			if(S[top].height < rect.height)
			{
				push(rect);
			}
			else if(S[top].height > rect.height)
			{
				int target = i;
				while(!isempty() && S[top].height >= rect.height)
				{
					Rectangle pre = pop();
					int area = pre.height * (i - pre.pos);
					maxv = max(maxv,area);
					target = pre.pos;
				}
				rect.pos = target;
				push(rect);
			}
		}
	}
	
	return maxv;
}

int getlargestRectangle()
{
	for(int j = 0; j < W; j++)
	{
		for(int i = 0; i < H; i++)
		{
			if(buffer[i][j])
				T[i][j] = 0;
			else
				T[i][j] = (i > 0)? T[i-1][j] + 1:1;
		}
	}
	int maxv = 0;
	for(int i = 0; i < H; i++)
	{
		maxv = getlargestRectangle(W, T[i]);
	}
	return maxv;
}

int main()
{
	
	scanf("%d %d",&H, &W);
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
			scanf("%d",&buffer[i][j]);
	}
	
    printf("%d\n", getlargestRectangle());
	
    return 0;
}
/*
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
6
*/