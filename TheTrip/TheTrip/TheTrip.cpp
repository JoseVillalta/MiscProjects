// TheTrip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;


string calculate(int n, vector<double> v)
{
    
    long long sum = 0;
    for (double val : v)
    {
        sum += val;
    }
    double ave = sum / (float)n;

    long long result = 0;
    for (double diff : v)
    {
        if (diff < ave)
        {
            result += ave - diff;
        }
    }

    string wholeResult = to_string((int)result);
    if (wholeResult.length() == 1)
    {
        wholeResult = "00" + wholeResult;
    }
    else if (wholeResult.length() == 2)
    {
        wholeResult = "0" + wholeResult;
    }
    string decimal = wholeResult.substr(wholeResult.length() - 2);
    wholeResult = wholeResult.substr(0, wholeResult.length() - 2);


    cout << "$" << wholeResult << "." << decimal << endl;

    string output;
    output = "$" + wholeResult + "." + decimal;
    return output;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        if (n == EOF) break;
        if (n <= 0) break;
        vector<double> v;
        int counter = n;
        while (counter > 0)
        {
            double f;
            cin >> f;
            f = f * 100;
            v.push_back(f);
            counter--;
        }
        calculate(n, v);
    }
    return 0;
}
