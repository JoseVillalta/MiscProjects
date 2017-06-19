#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PrimaryArithmetic/CarryCounter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(HasCarryTets)
	{
	public:
		
		TEST_METHOD(HasCarryTest)
		{
            Assert::AreEqual(0, HasCarry(1, 1, 1));
		}
        TEST_METHOD(HasCarryisTrue)
		{
            Assert::AreEqual(HasCarry(5, 5, 0), 1);
		}
        TEST_METHOD(HasCarryisFalse)
		{
            Assert::AreEqual(HasCarry(4, 4, 1), 0);
		}

	};
    TEST_CLASS(ConvertToArrayTests)
    {
    public:
        TEST_METHOD(ConvertTest)
        {
            int number = 356;
            int* result = ConvertToArray(number);
            Assert::AreEqual(result[0], 6);
            Assert::AreEqual(result[1], 5);
            Assert::AreEqual(result[2], 3);
        }    
    };
}