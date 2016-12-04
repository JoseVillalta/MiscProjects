#include "stdafx.h"
#include "trip.h"

string calculate(int n, vector<double> v)
{

    long long sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        v[i] = v[i] * 100;
        sum += v[i];
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