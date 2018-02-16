#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Freckles\InkCalculator.h"
#include "TestWithFiles.h"
#include "CompareFiles.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FrecklesTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDistance)
		{
			coord a;
			coord b;
			a.x = 0.0;
			a.y = 0.0;

			b.x = 1.0;
			b.y = 1.0;

			auto g = new InkCalculator();
			auto result = g->GetDistance(a, b);
			Assert::AreEqual(1.41421, result,0.01);
		}

		TEST_METHOD(TestDistance2)
		{
			coord a;
			coord b;
			a.x = 0.0;
			a.y = 0.0;

			b.x = 1.0;
			b.y = 0.0;

			auto g = new InkCalculator();
			auto result = g->GetDistance(a, b);
			Assert::AreEqual(1, result, 0.01);
		}

		TEST_METHOD(TestDistance3)
		{
			coord a;
			coord b;
			a.x = 0.0;
			a.y = 3.0;

			b.x = 4.0;
			b.y = 0.0;

			auto g = new InkCalculator();
			auto result = g->GetDistance(a, b);
			Assert::AreEqual(5.0, result, 0.01);
		}
		TEST_METHOD(TestEdgeInit)
		{
			auto g = new InkCalculator();
			g->InsertPoint(1.0, 1.0);
			g->InsertPoint(2.0, 2.0);
			g->InsertPoint(2.0, 4.0);
			g->numOfVertices = 3;
			g->GetEdges();
			auto e = g->edges[0];
			_ASSERT(e != nullptr);
			e = g->edges[1];
			_ASSERT(e != nullptr);
			e = g->edges[2];
			_ASSERT(e != nullptr);
			e = g->edges[3];
			_ASSERT(e == nullptr);

		}
		TEST_METHOD(TestEdgeSort)
		{
			auto g = new InkCalculator();
			g->InsertPoint(0.0, 0.0);
			g->InsertPoint(1.0, 0.0);
			g->InsertPoint(2.0, 0.0);
			g->InsertPoint(5.0, 0.0);
			g->numOfVertices = 4;
			g->GetEdges();
			g->GetSortedEdgeArray();
			Assert::AreNotEqual(0, (int)g->sortedEdges.size());
			double w = g->sortedEdges.at(0)->weight;
			Assert::AreEqual(1.0, w, 0.01);

		}
		TEST_METHOD(TestTheWholeThing)
		{
			auto g = new InkCalculator();
			g->InsertPoint(1.0, 1.0);
			g->InsertPoint(2.0, 2.0);
			g->InsertPoint(2.0, 4.0);
			auto result = g->GetSolution();
		    Assert::AreEqual(3.41, result, 0.01);
		}
		TEST_METHOD(TestTheWholeThing2)
		{
			auto g = new InkCalculator();
			g->InsertPoint(1.0, 0.0);
			g->InsertPoint(2.0, 0.0);
			g->InsertPoint(5.0, 0.0);
			auto result = g->GetSolution();
			Assert::AreEqual(4.0, result, 0.01);
		}
		TEST_METHOD(Input1)
		{
			TestWFiles("Input1.txt", "Output1.txt");
			bool match = CompareFiles("Output1.txt", "ExpectedOutput1.txt");
			Assert::AreEqual(true, match);

		}
	};
}