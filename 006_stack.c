/*
�沨����ʾ����������ʵ��ջ��
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top,S[1000];

//��ջ����
void push(int x)
{
	//top+1��Ԫ�ز���top��ָ��λ��
	S[++top] = x;
}

//��ջ����
int pop()
{
	top--;
	return S[top+1];	//����ԭ��top��ָ��ԭ��
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