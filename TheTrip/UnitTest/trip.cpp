#include "stdafx.h"
#include "trip.h"
#include <string>
#include <math.h>
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