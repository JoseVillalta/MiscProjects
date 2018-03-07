#pragma once
#include <string>
#include <fstream>
using namespace std;

bool CompareFiles(string file1, string file2)
{
	ifstream f1, f2;
	f1.open(file1, ios::binary);
	f2.open(file2, ios::binary);
	bool areEqual = true;

	ofstream reportFile;
	reportFile.open(file1 + "report.txt");

	char string1[256], string2[256];
	int j = 0;
	while (!f1.eof())
	{
		f1.getline(string1, 256);
		f2.getline(string2, 256);
		j++;
		if (strcmp(string1, string2) != 0)
		{
			areEqual = false;
			reportFile << "Expected: " << string2 << "at line: " << j << endl;
		}
	}

	return areEqual;
}