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


double smoother(double raw_ave)
{
    string::size_type n;
    string raw_string = to_string(raw_ave);
    n = raw_string.find(".");
    string decimal = raw_string.substr(n);

    double new_ave = 0;

    


    if (decimal.length() >= 5)
    {
        if (decimal.at(decimal.length() - 1) != '0')
        {
            new_ave = floor(new_ave);
        }
        string cmp = decimal.substr(0, 5);
        if (cmp == ".5000")
        {
            new_ave = floor(raw_ave);
        }
        else if (cmp == ".3333")
        {
            new_ave = floor(raw_ave);
        }
        else
        {
            new_ave = raw_ave;
        }
    }
    else
    {
        new_ave = raw_ave;
    }

    return new_ave;
}

string calculate(int n, vector<double> v)
{

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        v[i] = v[i] * 100;
        sum += v[i];
    }

    double ave = sum / (double)n;

    double new_ave = smoother(ave);

    double result = 0;
    for (double diff : v)
    {
        if (diff < new_ave)
        {
            result += new_ave - diff;
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
            v.push_back(f);
            counter--;
        }
        calculate(n, v);
    }
    return 0;
}
