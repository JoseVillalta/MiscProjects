#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LightMoreLight/CalcOnOrOff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestThree)
		{
            auto result = CalcOnOrOff(3);
            Assert::AreEqual(false,result);
		}
        TEST_METHOD(Test6241)
		{
            auto result = CalcOnOrOff(6241);
            Assert::AreEqual(true, result);
		}
        TEST_METHOD(Test8191)
		{
            auto result = CalcOnOrOff(8191);
            Assert::AreEqual(false, result);
		}
        TEST_METHOD(Test1426539184)
		{
            auto result = CalcOnOrOff(1426539184);
            Assert::AreEqual(false, result);
		}
        TEST_METHOD(Test4294967295)
		{
            auto result = CalcOnOrOff(4294967295);
            Assert::AreEqual(false, result);
		}
        TEST_METHOD(Test287793520)
        {
            auto result = CalcOnOrOff(287793520);
            Assert::AreEqual(false, result);
        }
        TEST_METHOD(Test1523277147)
        {
            auto result = CalcOnOrOff(1523277147);
            Assert::AreEqual(false, result);
        }
        TEST_METHOD(Test930243425)
        {
            auto result = CalcOnOrOff(930243425);
            Assert::AreEqual(false, result);
        }
        TEST_METHOD(Test4294705156)
		{
            auto result = CalcOnOrOff(4294705156);
            Assert::AreEqual(true, result);
		}
	};
}