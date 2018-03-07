/*
逆波兰表示法（用数组实现栈）
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top,S[1000];

//入栈操作
void push(int x)
{
	//top+1后将元素插入top所指的位置
	S[++top] = x;
}

//出栈操作
int pop()
{
	top--;
	return S[top+1];	//返回原来top所指的原素
}

int main()
{
	int a,b,len;
	char s[1];
	top = 0;
	
	while( (s[0]=getchar())!='\n' )
	{
		if (s[0] == ' ')
		{
			continue;
		}
		else if( s[0] == '+' )
		{
			a = pop();
			b = pop();
			push(b+a);
		}
		else if( s[0] == '-' )
		{
			a = pop();
			b = pop();
			push(b-a);
		}
		else if( s[0] == '*' )
		{
			a = pop();
			b = pop();
			push(b*a);
		}
		else
		{
			push(atoi(s));
		}
	}
	
	printf("%d\n",pop());
	
	return 0;
}