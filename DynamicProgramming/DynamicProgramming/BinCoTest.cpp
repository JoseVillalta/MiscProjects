#include "stdafx.h"
#include "BinCoTest.h"
#include "BinomialCoefficient.h"
#include <crtdbg.h>
#include <iostream>

using namespace std;

void RunBinCoTest()
{
	std::cout << " Running Binomial Coefficient Test " << endl;
	auto val = binomial_coefficient(5, 3);
	_ASSERT(val == 10);

	auto val1 = binomial_coefficient(5, 4);
	_ASSERT(val1 == 5);
	cout << " Done with Binomail Coefficient" << endl;
}
