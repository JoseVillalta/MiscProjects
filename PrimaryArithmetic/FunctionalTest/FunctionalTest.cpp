// FunctionalTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../PrimaryArithmetic/CarryCounter.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("SampleInput.txt");
    ofstream outputfile;
    outputfile.open("output.txt");
    int a, b;
    while(infile >> a >> b)
    {
        if (a == 0 && b == 0) break;

        auto result = CalculateNumberCarry(a, b);
        if(result == 0)
        {
            outputfile << "No carry operation." << endl;
        }
        else if(result == 1)
        {
            outputfile << "1 carry operation." << endl;
        }
        else if(result > 1)
        {
            outputfile << result << " carry operations." << endl;
        }
        else
        {
            outputfile << result << " carry operations" << endl;
        }

    }
    return 0;
}

