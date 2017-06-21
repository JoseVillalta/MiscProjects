// PrimaryArithmetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CarryCounter.h"
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string input;
    while(getline(cin, input))
    {
        if(input == "0 0")
        {
            break;
        }
        istringstream s(input);
        string sa;
        string sb;
        s >> sa;
        s >> sb;
        auto a = stoi(sa);
        auto b = stoi(sb);

        auto result = CalculateNumberCarry(a, b);
        if(result > 0)
        {
            cout << result<<" carry operations." << endl;
        }
        else if(result == 0)
        {
            cout << "No carry operations." << endl;
        }
        else
        {
            cout << "Error, something got goofed up" << endl;
        }
    }
    return 0;
}

