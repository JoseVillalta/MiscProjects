#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PlayingWithWheels\Explorer.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayingWithWheelsTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCountStepsPlus)
		{
			
			int steps = CountSteps(4, 7);
			Assert::AreEqual(3, steps);
			steps = CountSteps(7, 4);
			Assert::AreEqual(3, steps);
			steps = CountSteps(9, 1);
			Assert::AreEqual(8, steps);
		}

		TEST_METHOD(TestSolution)
		{
			auto init = GetConfig(1111);
			auto target = GetConfig(3455);
			int steps = FindSolution(init, target);
			Assert::AreEqual(13, steps);
		}
		TEST_METHOD(TestSolution1)
		{
			auto init = GetConfig(5555);
			auto target = GetConfig(6464);
			int steps = FindSolution(init, target);
			Assert::AreEqual(4, steps);
		}

		TEST_METHOD(TestGetConfig)
		{
			int val = 2345;
			auto c = GetConfig(2345);
			Assert::AreEqual(2, c.p1);
			Assert::AreEqual(3, c.p2);
			Assert::AreEqual(4, c.p3);
			Assert::AreEqual(5, c.p4);
		}

		TEST_METHOD(TestGetNext)
		{
			auto conf = GetConfig(1234);
			auto target = GetConfig(9999);

			auto result = GetNext(conf, target);
			Assert::AreEqual(2234, result.decimalVal);
		}

		TEST_METHOD(TestGetNext1)
		{
			auto conf = GetConfig(8888);
			auto target = GetConfig(1111);

			auto result = GetNext(conf, target);
			Assert::AreEqual(7888, result.decimalVal);
		}

		TEST_METHOD(TestGetNext2)
		{
			auto conf = GetConfig(1145);
			auto target = GetConfig(1234);

			auto result = GetNext(conf, target);
			Assert::AreEqual(1245, result.decimalVal);

		}
		TEST_METHOD(TestGetNext3)
		{
			auto conf = GetConfig(1225);
			auto target = GetConfig(1234);

			auto result = GetNext(conf, target);
			Assert::AreEqual(1235, result.decimalVal);

		}
		TEST_METHOD(TestGetNext4)
		{
			auto conf = GetConfig(1234);
			auto target = GetConfig(2234);

			auto result = GetNext(conf, target);
			Assert::AreEqual(2234, result.decimalVal);

		}
		TEST_METHOD(TestGetNext5)
		{
			auto conf = GetConfig(4321);
			auto target = GetConfig(1234);

			auto result = GetNext(conf, target);
			Assert::AreEqual(3321, result.decimalVal);

		}
		TEST_METHOD(TestGetNext6)
		{
			auto conf = GetConfig(3345);
			auto target = GetConfig(1234);

			auto result = GetNext(conf, target);
			Assert::AreEqual(2345, result.decimalVal);

		}
		TEST_METHOD(SolutionFinderTest)
		{
			auto conf = GetConfig(1111);
			auto target = GetConfig(2223);

			vector<config> ilegalConfs;

			int result = SolutionFinder(conf, target, ilegalConfs);
			Assert::AreEqual(5, result);
		}
	};
}