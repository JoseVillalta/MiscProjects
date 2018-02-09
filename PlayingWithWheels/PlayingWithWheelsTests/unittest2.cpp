#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PlayingWithWheels\BFS.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BFS
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestGetNext)
		{
			auto c = GetConfig(1111);
			auto next = GetNext(c, 0);
			Assert::AreEqual(2111, next.decimalVal);
			next = GetNext(c, 1);
			Assert::AreEqual(111, next.decimalVal);
			next = GetNext(c, 2);
			Assert::AreEqual(1211, next.decimalVal);
			next = GetNext(c, 3);
			Assert::AreEqual(1011, next.decimalVal);
			next = GetNext(c, 4);
			Assert::AreEqual(1121, next.decimalVal);
			next = GetNext(c, 5);
			Assert::AreEqual(1101, next.decimalVal);
			next = GetNext(c, 6);
			Assert::AreEqual(1112, next.decimalVal);
			next = GetNext(c, 7);
			Assert::AreEqual(1110, next.decimalVal);
		}
		TEST_METHOD(TestGetNext1)
		{
			auto c = GetConfig(111);
			auto next = GetNext(c, 1);
			Assert::AreEqual(9111, next.decimalVal);

			c = GetConfig(2292);
			next = GetNext(c, 4);
			Assert::AreEqual(2202, next.decimalVal);
		}
		TEST_METHOD(TestProcessNum)
		{
			InitSearch();
			queue<config> q;
			auto currentConfig = GetConfig(1234);
			bool found = ProcessNum(currentConfig, q, 1244);
			Assert::AreEqual(true, !q.empty());
			Assert::AreEqual(true, found);
			Assert::AreEqual(1, steps[1244]);
		}
		TEST_METHOD(TestProcessNum1)
		{
			InitSearch();
			queue<config> q;
			auto currentConfig = GetConfig(1234);
			bool found = ProcessNum(currentConfig, q, 5555);
			Assert::AreEqual(true, !q.empty());
			Assert::AreEqual(false, found);
			Assert::AreEqual(1, steps[1244]);
			Assert::AreEqual(1, steps[2234]);
			Assert::AreEqual(1, steps[1334]);
			Assert::AreEqual(0, steps[5555]);
		}
		TEST_METHOD(TestBfs)
		{
			InitSearch();
			vector<config> v;
			auto start = GetConfig(1111);
			auto target = GetConfig(2222);
			auto steps = BFSearch(start, target, v);
			Assert::AreEqual(4, steps);
		}
		TEST_METHOD(TestBfs1)
		{
			InitSearch();
			vector<config> v;
			v.push_back(GetConfig(8057));
			v.push_back(GetConfig(8047));
			v.push_back(GetConfig(5508));
			v.push_back(GetConfig(7508));
			v.push_back(GetConfig(6408));
			auto start = GetConfig(8056);
			auto target = GetConfig(6508);
			auto steps = BFSearch(start, target, v);
			Assert::AreEqual(14, steps);

		}
		TEST_METHOD(TestBfs2)
		{
			InitSearch();
			vector<config> v;
			v.push_back(GetConfig(1));
			v.push_back(GetConfig(9));
			v.push_back(GetConfig(10));
			v.push_back(GetConfig(90));
			v.push_back(GetConfig(100));
			v.push_back(GetConfig(900));
			v.push_back(GetConfig(1000));
			v.push_back(GetConfig(9000));
			auto start = GetConfig(0000);
			auto target = GetConfig(5317);
			auto steps = BFSearch(start, target, v);
			Assert::AreEqual(-1, steps);
		}
	};
}