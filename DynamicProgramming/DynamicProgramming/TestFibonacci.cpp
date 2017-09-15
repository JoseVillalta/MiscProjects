#include "stdafx.h"
#include "TestFibonacci.h"
#include "Fibonacci.h"
#include <crtdbg.h>
#include <iostream>

using namespace std;

void RunTests(void)
{
	std::cout << " Running Fibbonacci tests" << std::endl;
	auto val = fib_r(6);
	_ASSERT(val == 8);

	// This takes a long time. Let's do better. 
	// auto val_long = fib_r(45);
	// cout << "Fib of 45 is " << val_long << endl;

	cout << " Fib of the first 45 numbers" << endl;
	auto val1 = fib_driver(45);
	_ASSERT(val1 == 1134903170);
	cout << " Fib of 45 is " << val1 << endl;
	
	auto val2 = fib_dp(45);
	_ASSERT(val1 == val2);

	auto val3 = fib_ultimate(45);
	_ASSERT(val2 == val3);
	std::cout << " Done" << endl;
}
