// TheTrip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
using namespace std;



double calculate(int n, vector<double> v)
{
    if (n == 1) return 0;
    double sum = 0;
    for (double val : v)
    {
        sum += val;
    }
    double ave = sum / (double)n;
    ave = round(ave);

    double result = 0;
    for (double diff : v)
    {
        if (diff < ave)
        {
            result += ave - diff;
        }
    }
   
    return result;
}

void printResult(double result)
{

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
   /* result = result / 100.00;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "$" << result << endl;*/
}

void testSmallVals()
{
    vector<double> v1;
    double val = 0.01;
    v1.push_back(val);
    double val1 = 0.01;
    v1.push_back(val1);
    double val2 = 0.01; 
    v1.push_back(val2);
    double val3 = 0.09; 
    v1.push_back(val3);
    auto result = calculate(4, v1);
    _ASSERT(result == 6);
    cout << "Result should be $0.06" << endl;
    printResult(result);
}

void test1Kstudents()
{
    vector<double> v1;
    for (int i = 0; i < 999; i++)
    {
        v1.push_back(10001 * 100);
    }
    v1.push_back(9000 * 100);
    auto result = calculate(10000, v1);
    _ASSERT(result = 1001 * 100);
    cout << "Result should be $1000.01" << endl;
    printResult(result);

}
void testEx2()
{

    vector<double> v;
    double val = 15.00;
    double val1 = 15.01;
    double val2 = 3.00;
    double val3 = 3.01;

    v.push_back(val);
    v.push_back(val1);
    v.push_back(val2);
    v.push_back(val3);
    auto result = calculate(4, v);
    _ASSERT(result == 11.99);
    cout << "Result should be $11.99" << endl;
    printResult(result);
}
void testEx1()
{
    vector<double> v;
    double val = 10.00*100;
    double val1 = 20.00*100;
    double val2 = 30.00*100;

    v.push_back(val);
    v.push_back(val1);
    v.push_back(val2);

    auto result = calculate(3, v);
    _ASSERT(result == 10 * 100);
    cout << "Result should be $10.00" << endl;
    printResult(result);

}
void test2Inputs()
{
    vector<double> v;
    double val = 10.00*100;
    double val1 = 15.00*100;

    v.push_back(val);
    v.push_back(val1);
    auto result = calculate(2, v);
    _ASSERT(result == 2.50 * 100);
    cout << "Result should be $2.50" << endl;
    printResult(result);

}
void test()
{
    cout << "*** Testing ***" << endl;
    
    testSmallVals();
    //test1Kstudents();
    testEx2();
    //testEx1();
   // test2Inputs(); 
    cout << "*** All tests pass ***" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    bool dotest = false;

    if (dotest)
    {
        test();
    }
    else
    {
        int n = 0;
        while (scanf_s("%d",&n)==1)
        {
            if (n == 0) break;
            if (n > 1000) break;
            if (n <= 0) break;
            vector<double> v;
            int counter = n;
            while (counter > 0)
            {
                double f;
                scanf_s("%lf", &f);
                if (f < 0 || f >1000) break;
                f = f * 100;
                v.push_back(f);
                counter--;
            }
            auto res = calculate(n, v);
            printResult(res);
        }
    }

    return 0;
}

