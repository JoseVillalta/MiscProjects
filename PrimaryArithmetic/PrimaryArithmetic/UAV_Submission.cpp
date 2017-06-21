// PrimaryArithmetic.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int HasCarry(int a, int b, int c)
{
    if( a + b + c >= 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int * ConvertToArray(int a)
{
    int *  array = new int[11];

    for(int j=0; j<11; j++)
    {
        array[j] = 0;
    }
   
    int i = 0;
    while(a > 0)
    {
        int digit = a % 10;
        array[i] = digit;
        a -= digit;
        a = a / 10;
        i++;
    }

    return array;
}

int CalculateNumberCarry(int a, int b)
{
    auto arrA = ConvertToArray(a);
    auto arrB = ConvertToArray(b);

    int counter = 0;
    int hasCarry = 0;

    for(int i = 0; i<11; i++)
    {
        hasCarry = HasCarry(arrA[i], arrB[i], hasCarry);
        if(hasCarry == 1)
        {
            counter++;
        }
    }

    delete[] arrA;
    delete[] arrB;
    return counter;
}

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
       
        if(result == 0)
        {
            cout << "No carry operation." << endl;
        }
		else if(result == 1)
		{
			cout<<"1 carry operation."<<endl;
		}
        else if(result > 1)
        {
            cout << result<<" carry operations." << endl;
        }
		else
        {
            cout << "Error, something got goofed up" << endl;
        }
    }
    return 0;
}

