// Freckles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "InkCalculator.h"

using namespace std;

int main()
{
	int numOfTestCases;
	cin >> numOfTestCases;
	string blank;
	getline(cin, blank);
	while (numOfTestCases > 0)
	{
		int points;
		cin >> points;
		auto g = new InkCalculator();
		while (points > 0)
		{
			double x;
			double y;
			cin >> x;
			cin >> y;
			g->InsertPoint(x, y);
			points--;
		}
		getline(cin, blank);
		double ink = g->GetSolution();
		cout << fixed << setprecision(2) << ink << endl;
		cout << endl;
	}

    return 0;
}

