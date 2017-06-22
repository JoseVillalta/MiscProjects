// FuntionalTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../LightMoreLight/CalcOnOrOff.h"
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    cout << "Starting functional Test" << endl;
    std::ifstream infile("SampleInput.txt");
    ofstream outputfile;
    outputfile.open("output.txt");
    unsigned int n;
    while(infile >> n)
    {
        if (n == 0) break;
        auto result = CalcOnOrOff(n);
        if(result)
        {
            outputfile << "yes" << endl;
        }
        else
        {
            outputfile << "no" << endl;
        }
    }
    outputfile.close();
    cout << "Test is finished" << endl;
    return 0;
}

