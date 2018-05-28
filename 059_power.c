/*
幂乘
*/
#include<stdio.h>

typedef long long llong;
typedef unsigned long long ullong;

llong mod_pow(ullong x, ullong n, ullong mod)
{
	ullong res = 1;
	while (n > 0)
	{
		if (n & 1)	res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	ullong m,n;
	scanf("%lld %lld", &m, &n);
    printf("%lld\n", mod_pow(m,n, 1000000007));
	
    return 0;
}