// TheTrip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

string calculate(int n, vector<double> v)
{

    double sum = 0;
    double high = 0.0;
    double low = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }

    double ave = sum / n;

    double temp = 0;
    for (double diff : v)
    {
        double temp = diff - ave;
        if (temp >= 0)
        {
            high += floor(temp * 100) / 100;
        }
        else
        {
            low -= ceil(temp * 100) / 100;
        }
    }
    double result = max(high, low);

    string raw_string = to_string(result);
    string::size_type s;
    s = raw_string.find(".");
    string output = "$" + raw_string.substr(0, s + 3);
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
        string result = calculate(n, v);
        cout << result << endl;
    }
    return 0;
}
