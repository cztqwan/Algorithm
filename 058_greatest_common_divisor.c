/*
最大公约数
*/
#include<stdio.h>

//用递归求最大公约数，辗转相除法
int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a,b));
	
    return 0;
}