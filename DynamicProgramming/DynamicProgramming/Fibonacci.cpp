#include "stdafx.h"
#include "Fibonacci.h"
#define MAX_FIB 45
#define UNKNOWN -1
long f[MAX_FIB + 1];

long fib_cached(int n)
{
	if(f[n] == UNKNOWN)
	{
		f[n] = fib_cached(n - 1) + fib_cached(n - 2);
	}
	
	return f[n];	
}

long fib_driver(int n)
{
	f[0] = 0;
	f[1] = 1;

	for(int i = 2; i<=n; i++)
	{
		f[i] = UNKNOWN;
	}

	return fib_cached(n);
}

long fib_r(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fib_r(n - 1) + fib_r(n - 2);
}

long fib_dp(int n)
{
	long f[MAX_FIB + 1];

	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i<=n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

long fib_ultimate(int n)
{
	long back1 = 0;
	long back2 = 1;
	long next;

	if (n == 0) return 0;

	for(int i = 2; i<n; i++)
	{
		next = back1 + back2;
		back1 = back2;
		back2 = next;
	}

	return(back1 + back2);
}