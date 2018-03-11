#include "stdafx.h"
#include "knapsack_tests.h"

void KnapsackTests()
{
	cout << "Starting Knapsack tests" << endl;

	vector<int> values = { 0,1,6,10 };
	Knapsack(values, 14);

	cout << "Test #2 Knapsack" << endl;
	Knapsack(values, 17);

	cout << " Test #3" << endl;
	Knapsack(values, 6);

	cout << " Test #4" << endl;
	Knapsack(values, 7);

	cout << " Test #5" << endl;
	vector<int> values2 = { 0,1,2,5,9,10 };
	Knapsack(values2, 22);

	cout << " Test #6" << endl;
	Knapsack(values2, 23);
}