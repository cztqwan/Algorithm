/*
������������
*/

#include<stdio.h>
#include<string.h>

#define Len 100

//S2
typedef struct
{
	int i;
	int area;
}Stack2;

int S1[Len];
Stack2 S2[Len];
int S1_top = 0,S2_top = 0;

//S1��ջ����
void S1_push(int x)
{
	//top+1��Ԫ�ز���top��ָ��λ��
	S1[++S1_top] = x;
}

//S1��ջ����
int S1_pop()
{
	S1_top--;
	return S1[S1_top+1];	//����ԭ��top��ָ��ԭ��
}

//S2��ջ����
void S2_push(int i, int area)
{
	//top+1��Ԫ�ز���top��ָ��λ��
	S2[++S2_top].i = i;
	S2[S2_top].area = area;
}

//S2��ջ����
Stack2 S2_pop()
{
	Stack2 S;
	S2_top--;
	S.i = S2[S2_top+1].i;
	S.area = S2[S2_top+1].area;
	return S;	//����ԭ��top��ָ��ԭ��
}

int main()
{
	char ch;
	int i,j,a,sum = 0;
	int ans[Len],a_len;
	
	for(i = 0; (ch = getchar()) != '\n'; i++)
	{
		if(ch == '\\') S1_push(i);	//ת�壬��ջ
		else if(ch == '/' && S1_top > 0)
		{
			j = S1_pop();
			sum += i - j;
			a = i - j;
			while(S2_top > 0)
			{
				Stack2 S = S2_pop();
				if(S.i <= j)
				{
					S2_push(S.i, S.area);
					break;
				}
				else
				{
					a += S.area;
				}
			}
			S2_push(j,a);
		}
	}
	
	a_len = S2_top;
	for(i = S2_top-1; i >= 0 ;i--)
	{
		ans[i] = S2_pop().area;
	}
		
	printf("%d\n",sum);
	printf("%d ",a_len);
	for(j = 0; j < a_len; j++)
	{
		printf(" ");
		printf("%d",ans[j]);
	}
	printf("\n");
	return 0;
}