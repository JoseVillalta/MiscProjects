#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

struct cell
{
	int val;
	int parent;
};

void Knapsack(vector<int> values, int target);