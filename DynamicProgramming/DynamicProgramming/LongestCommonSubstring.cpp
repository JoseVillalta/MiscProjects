#include "stdafx.h"
#pragma once
#include "LongestCommonSubstring.h"

string GetLongestCommonSubstring(string s, string t)
{
	string result;
	int m[NMAX][NMAX];
	int i, j;
	for(i=0;i<NMAX;i++)
	{
		for(j=0;j<NMAX;j++)
		{
			m[i][j] = 0;
		}
	}
	int s_size = s.size();
	int t_size = t.size();
	int max = 0;
	int s_indexMax = 0;

	for(i=1;i<=s_size;i++)
	{
		for(j=1;j<=t_size;j++)
		{
			if(s[i] == t[j])
			{
				m[i][j] = 1 + m[i - 1][j - 1];
				if(m[i][j] > max)
				{
					max = m[i][j];
					s_indexMax = i;
				}
			}
		}
	}

	for(i = 1 + s_indexMax - max; i<= s_indexMax;i++)
	{
		result += s[i];
	}


	return result;
}
