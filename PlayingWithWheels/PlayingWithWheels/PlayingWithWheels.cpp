#include "stdafx.h"
#include <iostream>
#include <string>
#include "BFS.h"

using namespace std;

int main()
{
	int numOfTests = 0;
	cin >> numOfTests;
	while (numOfTests > 0)
	{
		int p1, p2, p3, p4;
		cin >> p1;
		cin >> p2;
		cin >> p3;
		cin >> p4;
		config start;
		start.p1 = p1;
		start.p2 = p2;
		start.p3 = p3;
		start.p4 = p4;
		start.GetDecimal();
		config target;
		cin >> p1;
		cin >> p2;
		cin >> p3;
		cin >> p4;
		target.p1 = p1;
		target.p2 = p2;
		target.p3 = p3;
		target.p4 = p4;
		target.GetDecimal();
		int ilegalConfig;
		cin >> ilegalConfig;
		vector<config> v;
		while (ilegalConfig > 0)
		{
			config iconfig;
			cin >> p1;
			cin >> p2;
			cin >> p3;
			cin >> p4;
			iconfig.p1 = p1;
			iconfig.p2 = p2;
			iconfig.p3 = p3;
			iconfig.p4 = p4;
			iconfig.GetDecimal();
			v.push_back(iconfig);
			ilegalConfig--;
		}
		InitSearch();
		numOfTests--;
		if (numOfTests > 0)
		{
			string s;
			getline(cin, s);
		}
		int steps = BFSearch(start, target, v);
		cout << steps << endl;
		
		
	}
	
	
	return 0;
}