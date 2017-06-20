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
            Assert::AreEqual(1, HasCarry(5, 5, 0));
		}
        TEST_METHOD(HasCarryisFalse)
		{
            Assert::AreEqual(0, HasCarry(4, 4, 1));
		}

	};
    TEST_CLASS(ConvertToArrayTests)
    {
    public:
        TEST_METHOD(ConvertTest)
        {
            int number = 356;
            int* result = ConvertToArray(number);
            Assert::AreEqual( 6, result[0]);
            Assert::AreEqual( 5, result[1]);
            Assert::AreEqual( 3, result[2]);
        }
        TEST_METHOD(ConvertZero)
        {
            int number = 0;
            int* result = ConvertToArray(number);
            Assert::AreEqual(0, result[0]);
        }
        TEST_METHOD(ConvertLarge)
        {
            int number = 1234567890;
            int* result = ConvertToArray(number);
            Assert::AreEqual(0, result[0]);
            Assert::AreEqual(9, result[1]);
            Assert::AreEqual(8, result[2]);
            Assert::AreEqual(7, result[3]);
            Assert::AreEqual(6, result[4]);
            Assert::AreEqual(5, result[5]);
            Assert::AreEqual(4, result[6]);
            Assert::AreEqual(3, result[7]);
            Assert::AreEqual(2, result[8]);
            Assert::AreEqual(1, result[9]);
            Assert::AreEqual(0, result[10]);
        }
    };
    TEST_CLASS(CarryCounterTests)
    {
    public:
        TEST_METHOD(NominalCase)
        {
            int a = 3;
            int b = 2;
            int result = CalculateNumberCarry(a, b);
            Assert::AreEqual(0, result);
        }
        TEST_METHOD(OneCarryTest)
        {
            int a = 5;
            int b = 6;
            int result = CalculateNumberCarry(a, b);
            Assert::AreEqual(1, result);
        }
        TEST_METHOD(TwoCarryTest)
        {
            int a = 85;
            int b = 56;
            int result = CalculateNumberCarry(a, b);
            Assert::AreEqual(2, result);
        }
        
    };
}