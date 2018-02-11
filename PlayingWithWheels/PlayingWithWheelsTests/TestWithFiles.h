#pragma once
#include "stdafx.h"
#include "fstream"
#include <string>
#include "..\PlayingWithWheels\BFS.h"


using namespace std;

void TestWithFiles(string input, string output)
{
	ifstream infile(input);
	ofstream outputfile;
	outputfile.open(output);
	bool running = true;
	int numOfTest = 0;
	infile >> numOfTest;
	while (numOfTest > 0)
	{
		int p1, p2, p3, p4;
		infile >> p1;
		infile >> p2;
		infile >> p3;
		infile >> p4;
		config start;
		start.p1 = p1;
		start.p2 = p2;
		start.p3 = p3;
		start.p4 = p4;
		start.GetDecimal();
		config target;
		infile >> p1;
		infile >> p2;
		infile >> p3;
		infile >> p4;
		target.p1 = p1;
		target.p2 = p2;
		target.p3 = p3;
		target.p4 = p4;
		target.GetDecimal();
		int ilegalConfig;
		infile >> ilegalConfig;
		vector<config> v;
		while (ilegalConfig > 0)
		{
			config iconfig;
			infile >> p1;
			infile >> p2;
			infile >> p3;
			infile >> p4;
			iconfig.p1 = p1;
			iconfig.p2 = p2;
			iconfig.p3 = p3;
			iconfig.p4 = p4;
			iconfig.GetDecimal();
			v.push_back(iconfig);
			ilegalConfig--;
		}
		numOfTest--;
		if (numOfTest > 0)
		{
			string s;
			getline(infile, s);
		}
		InitSearch();
		int steps = BFSearch(start, target, v);
		outputfile << steps << endl;
	}
}