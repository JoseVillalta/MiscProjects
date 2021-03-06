// TheTouristGuide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TourGuide.h"
#include "iostream"

using namespace std;

int main()
{
	bool running = true;
	int sn = 1;
	while (running)
	{
		int n, r;
		cin >> n;
		cin >> r;
		if (n == 0 && r == 0) break;
		auto tg = new TourGuide(n);
		while (r > 0)
		{
			int x, y, cap;
			cin >> x;
			cin >> y;
			cin >> cap;
			tg->InsertEdge(x, y, cap);
			r--;
		}
		int start, end, passengers;
		cin >> start;
		cin >> end;
		cin >> passengers;
		int result = tg->FindPath(start, end, passengers);
		cout << "Scenario #" << sn << endl;
		cout << "Minimum Number of Trips = " << result << endl;
		cout << endl;
		delete tg;
	}
    return 0;
}

