#include "stdafx.h"
#include "PartitionTest.h"
#include "PartitionProblem.h"

void RunPartitionProblemTest()
{
	//int s[] = { 1,1,1,1,1,1,1,1,1 };
	int * s = new int[10];
	for(int i =0; i<=9; i++)
	{
		s[i] = 1;
	}

	partition(s, 9, 3);
	//int s1[] = { 1,2,3,4,5,6,7,8,9 };
	//partition(s1, 9, 3);
}