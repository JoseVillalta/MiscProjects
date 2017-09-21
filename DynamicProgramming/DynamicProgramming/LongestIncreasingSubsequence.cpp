#include "stdafx.h"
#include "LongestIncreasingSubsequence.h"
#include <iostream>
#define MAXV 100



cell lis_arr[MAXV];

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

cell lis(int arr[], int n)
{
	int i, j, par = 0;

	cell result;
	result.val = 0;
	result.parent = -1;

	for(i=0;i<n;i++)
	{
		lis_arr[i].val = 1;
		lis_arr[i].parent = -1;
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis_arr[i].val < lis_arr[j].val + 1)
			{
				lis_arr[i].val = lis_arr[j].val + 1;
				lis_arr[i].parent = j;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(result.val < lis_arr[i].val)
		{
			result.val = lis_arr[i].val;
			result.parent = i;
		}
	}

	return result;
}

void printLIS(int parent, int * arr)
{
	if (parent == -1) return;

	printLIS(lis_arr[parent].parent,arr);
	std::cout << arr[parent] << " ,";
}