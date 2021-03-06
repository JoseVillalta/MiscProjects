#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAXV 9999

using namespace std;

bool legal[MAXV+1];
bool discovered[MAXV+1];
bool processed[MAXV+1];
int steps[MAXV+1];


typedef struct
{
	int p1;
	int p2;
	int p3;
	int p4;
	int decimalVal;
	void GetDecimal()
	{
		decimalVal = p1 * 1000 + p2 * 100 + p3 * 10 + p4;
	}
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

void InitSearch()
{
	for (int i = 0; i <= MAXV; i++)
	{
		legal[i] = true;
		discovered[i] = false;
		processed[i] = false;
		steps[i] = 0;
	}
}

void SetIlegalConfigs(vector<config> v)
{
	for (auto c : v)
	{
		legal[c.decimalVal] = false;
	}
}

config GetNext(config current, int scenario)
{
	config next;
	switch(scenario)
	{
	case 0: //p1 ++
		if (current.p1 + 1 > 9)
		{
			next.p1 = 0;
		}
		else
		{
			next.p1 = current.p1 + 1;
		}
		next.p2 = current.p2;
		next.p3 = current.p3;
		next.p4 = current.p4;
		break;
	case 1: // p1 --
		if (current.p1 - 1 < 0)
		{
			next.p1 = 9;
		}
		else
		{
			next.p1 = current.p1 - 1;
		}
		next.p2 = current.p2;
		next.p3 = current.p3;
		next.p4 = current.p4;
		break;
	case 2: // p2 ++
		if (current.p2 + 1 > 9)
		{
			next.p2 = 0;
		}
		else
		{
			next.p2 = current.p2 + 1;
		}
		next.p1 = current.p1;
		next.p3 = current.p3;
		next.p4 = current.p4;
		break;
	case 3: // p2 --
		if (current.p2 - 1 < 0)
		{
			next.p2 = 9;
		}
		else
		{
			next.p2 = current.p2 - 1;
		}
		next.p1 = current.p1;
		next.p3 = current.p3;
		next.p4 = current.p4;
		break;
	case 4: // p3 ++
		if (current.p3 + 1 > 9)
		{
			next.p3 = 0;
		}
		else
		{
			next.p3 = current.p3 + 1;
		}
		next.p1 = current.p1;
		next.p2 = current.p2;
		next.p4 = current.p4;
		break;
	case 5: // p3 --
		if (current.p3 - 1 < 0)
		{
			next.p3 = 9;
		}
		else
		{
			next.p3 = current.p3 - 1;
		}
		next.p1 = current.p1;
		next.p2 = current.p2;
		next.p4 = current.p4;
		break;
	case 6: // p4 ++
		if (current.p4 + 1 > 9)
		{
			next.p4 = 0;
		}
		else
		{
			next.p4 = current.p4 + 1;
		}
		next.p1 = current.p1;
		next.p2 = current.p2;
		next.p3 = current.p3;
		break;
	case 7: // p4 --
		if (current.p4 - 1 < 0)
		{
			next.p4 = 9;
		}
		else
		{
			next.p4 = current.p4 - 1;
		}
		next.p1 = current.p1;
		next.p2 = current.p2;
		next.p3 = current.p3;
		break;
	}
	next.GetDecimal();
	return next;
}

bool ProcessNum(config current, queue<config> & q, int target)
{
	bool found = false;

	for (int i = 0; i < 8; i++)
	{
		auto next = GetNext(current, i);
		if (!discovered[next.decimalVal])
		{
			discovered[next.decimalVal] = true;
			if (legal[next.decimalVal])
			{
				if (next.decimalVal == target)
				{
					found = true;
				}
				steps[next.decimalVal] = steps[current.decimalVal] + 1;
				q.push(next);
			}
		}
	}
	return found;
}

int BFSearch(config start, config target, vector<config> ilegalConfigs)
{
	InitSearch();
	SetIlegalConfigs(ilegalConfigs);
	int result;
	bool found = false;
	queue<config> q;
	q.push(start);
	discovered[start.decimalVal] = true;

	while (!q.empty())
	{
		if (found) break;
		auto currentConfig = q.front();
		q.pop();
		if (!processed[currentConfig.decimalVal])
		{
			found = ProcessNum(currentConfig, q, target.decimalVal);
			processed[currentConfig.decimalVal] = true;
		}
	}

	if (found)
	{
		result = steps[target.decimalVal];
	}
	else
	{
		result = -1;
	}

	return result;
}



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
		numOfTests--;
		if (numOfTests > 0)
		{
			string s;
			getline(cin, s);
		}
		InitSearch();
		int steps = BFSearch(start, target, v);
		cout << steps << endl;
		
	}
	
	
	return 0;
}