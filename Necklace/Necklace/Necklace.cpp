// Necklace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Necklace.h"



int main()
{
	int numOfTests;
	cin >> numOfTests;
	int counter = 1;
	while (numOfTests > 0)
	{
		InitG();
		int numOfBeads;
		cin >> numOfBeads;
		while (numOfBeads > 0)
		{
			int start; 
			int end;
			cin >> start >> end;
			Insert(start, end);
			numOfBeads--;
		}
		cout << "Case #" << counter << endl;
		bool valid = CheckValid();
		if (valid)
		{
			Dfs(1);
		}
		else
		{
			cout << "some beads may be lost" << endl;
		}
		counter++;
		numOfTests--;
		cout << endl;
	}
    return 0;
}

