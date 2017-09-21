#include "stdafx.h"
#include "LongestIncreasingSubsequence.h"

int _lis_r(int arr[], int n, int * max_ref)
{
	if (n == 1) return 1;

	int res, max_ending_here = 1;

	for(int i = 1; i<n; i++)
	{
		res = _lis_r(arr, i, max_ref);
		if(arr[i-1] < arr[n-1] && res+1 > max_ending_here)
		{
			max_ending_here = res + 1;
		}
	}

	if(*max_ref < max_ending_here)
	{
		*max_ref = max_ending_here;
	}

	return max_ending_here;
}

int lis_r(int arr[], int n)
{
	int max = 1;
	_lis_r(arr, n, &max);
	return max;
}

int lis(int arr[], int n)
{
	int i, j, max = 0;
	auto lis = new int[n]();

	for(i=0;i<n;i++)
	{
		lis[i] = 1;
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i] < lis[j]+1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(max < lis[i])
		{
			max = lis[i];
		}
	}

	delete[] lis;

	return max;
}