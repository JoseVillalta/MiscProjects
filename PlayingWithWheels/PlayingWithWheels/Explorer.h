#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

typedef struct
{
	int p1;
	int p2;
	int p3;
	int p4;
	int decimalVal;
}config;

config GetConfig(int val) 
{
	config c;
	c.decimalVal = val;
	c.p4 = val % 10;
	val = val - c.p4;
	c.p3 = (val % 100) / 10;
	val = val - c.p3;
	c.p2 = (val % 1000) / 100;
	c.p1 = (val - c.p2) / 1000;

	return c;
}


int CountSteps(int init, int target)
{
	int counter = 0;

	if (init == target) return 0;
	if (target > init)
	{
		while (target != init)
		{
			init++;
			counter++;
		}
	}
	else
	{
		while (target != init)
		{
			init--;
			counter++;
		}
	}

	return counter;
}

int FindSolution(config  w, config t)
{
	int steps = 0;

	steps = CountSteps(w.p1, t.p1);
	steps += CountSteps(w.p2, t.p2);
	steps += CountSteps(w.p3, t.p3);
	steps += CountSteps(w.p4, t.p4);

	return steps;
}

config GetNext(config c, config t)
{
	config next;
	
	if (c.decimalVal > t.decimalVal)
	{
		if (c.p4 == t.p4)
		{
			next.p4 = c.p4;
			if (c.p3 == t.p3)
			{
				next.p3 = c.p3;
				if (c.p2 == t.p2)
				{
					next.p2 = c.p2;
					next.p1 = c.p1 - 1;
				}
				else
				{
					next.p2 = c.p2 - 1;
					next.p1 = c.p1;
				}
			}
			else
			{
				next.p3 = c.p3 - 1;
				next.p2 = c.p2;
				next.p1 = c.p1;		
			}
		}
		else
		{
			next.p4 = c.p4 - 1;
			next.p3 = c.p3;
			next.p2 = c.p2;
			next.p1 = c.p1;
		}
	}
	else
	{
		if(c.p4 == t.p4)
		{
			next.p4 = c.p4;
			if (c.p3 == t.p3)
			{
				next.p3 = c.p3;
				if (c.p2 == t.p2)
				{
					next.p2 = c.p2;
					next.p1 = c.p1 + 1;
				}
				else
				{
					next.p2 = c.p2 + 1;
					next.p1 = c.p1;
				}
			}
			else
			{
				next.p3 = c.p3 + 1;
				next.p2 = c.p2;
				next.p1 = c.p1;
			}
		}
		else
		{
			next.p4 = c.p4 + 1;
			next.p3 = c.p3;
			next.p2 = c.p2;
			next.p1 = c.p1;
		}
	}
	next.decimalVal = next.p1 * 1000 + next.p2 * 100 + next.p3 * 10 + next.p4;
	return next;
}

bool isLegalConfig(config c, vector<config> ilegalConfigs)
{
	return true;
}

void GoAroundObstacle(config & c, int & count)
{

}
int SolutionFinder(config w, config t, vector<config> ilegalConfigs)
{
	int counter = 0;
	bool isTarget = (w.decimalVal == t.decimalVal);
	if (isTarget) return 0;
	
	while (!isTarget)
	{
		w = GetNext(w, t);
		counter++;
		if (w.decimalVal == t.decimalVal) break;
		if (!isLegalConfig(w, ilegalConfigs))
		{
			counter--;
			int count;
			GoAroundObstacle(w, count);
			if (count == -1)
			{
				counter = -1;
				break;
			}
			else
			{
				counter += count;
			}
		}
	}

	return counter;
}
