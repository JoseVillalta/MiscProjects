#include "stdafx.h"
#include "PartitionProblem.h"
#include <algorithm>
#include <iostream>
#define MAXN 100
#define MAXK 100
#define MAX_INT 10000

int m[MAXN + 1][MAXK + 1];  // DP Table for values
int d[MAXN + 1][MAXK + 1];  // DP Table for dividers

void print_partitions(int s[], int start, int end)
{
	for(int i = start; i<=end; i++)
	{
		std::cout << s[i] << " ";
	}
	std::cout << std::endl;
}

void reconstruct_partition(int s[], int d[MAXN+1][MAXN+1], int n, int k)
{
	if(k==1)
	{
		print_partitions(s, 1, n);
	}
	else
	{
		reconstruct_partition(s, d, d[n][k], k - 1);
		print_partitions(s, d[n][k] + 1, n);
	}
}

void partition(int s[], int n, int k)
{
	
	int p[MAXN + 1];            // prefix sum array
	int cost;
	int i, j, x;

	p[0] = 0;
	for (i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] + s[i];  // init prefix sums
	}

	for (i = 1; i <= n; i++)
	{
		m[i][1] = p[i];          // construct boundaries
	}
	for (j = 1; j <= k; j++)
	{
		m[1][j] = s[1];
	}

	for(i=2; i<=n; i++)
	{
      for(j=2; j<=k; j++)
      {
		  m[i][j] = MAX_INT;
		  for(x=1; x<=(i-1);x++)
		  {
			  cost = std::max(m[x][j - 1], p[i] - p[x]);
			  if( m[i][j] > cost)
			  {
				  m[i][j] = cost;
				  d[i][j] = x;
			  }
		  }
      }
		
	}

	reconstruct_partition(s, d, n, k);

}