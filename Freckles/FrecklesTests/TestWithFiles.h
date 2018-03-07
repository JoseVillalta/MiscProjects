#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include "../Freckles/InkCalculator.h"

using namespace std;
void TestWFiles(string input, string output)
{
	ifstream infile(input);
	ofstream outputfile;
	outputfile.open(output);
	int numOfTest;
	infile >> numOfTest;
	string blank;
	getline(infile, blank);
	while (numOfTest > 0)
	{
		int numOfPoints;
		infile >> numOfPoints;
		auto g = new InkCalculator();
		while (numOfPoints > 0)
		{
			double x;
			double y;
			infile >> x;
			infile >> y;
			g->InsertPoint(x, y);
			numOfPoints--;
		}
		double result = g->GetSolution();
		outputfile << fixed << setprecision(2) << result << endl;
		outputfile << endl;
		numOfTest--;
		delete g;
	}
}