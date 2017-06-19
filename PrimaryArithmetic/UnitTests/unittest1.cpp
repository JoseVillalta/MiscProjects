#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PrimaryArithmetic/CarryCounter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Assert::AreEqual(CalculateNumberCarry(1,1), 0);
		}

	};
}