#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TheTouristGuide\TourGuide.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TouristGuideTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCalculation)
		{
			auto tg = new TourGuide(1);
			auto result = tg->CalculateNumTrips(25, 99);
			Assert::AreEqual(5, result);
		}
		TEST_METHOD(TestGivenExample)
		{
			auto tg = new TourGuide(7);
			tg->InsertEdge(1, 2, 30);
			tg->InsertEdge(1, 3, 15);
			tg->InsertEdge(1, 4, 10);
			tg->InsertEdge(2, 4, 25);
			tg->InsertEdge(3, 6, 20);
			tg->InsertEdge(2, 5, 60);
			tg->InsertEdge(4, 7, 35);
			tg->InsertEdge(5, 7, 20);
			tg->InsertEdge(6, 7, 30);

			int result = tg->FindPath(1, 7, 99);
			Assert::AreEqual(5, result);

		}
		TEST_METHOD(AnotherHappyPath)
		{
			auto tg = new TourGuide(7);
			tg->InsertEdge(1, 2, 30);
			tg->InsertEdge(1, 3, 15);
			tg->InsertEdge(1, 4, 10);
			tg->InsertEdge(2, 4, 25);
			tg->InsertEdge(3, 6, 20);
			tg->InsertEdge(2, 5, 60);
			tg->InsertEdge(4, 7, 35);
			tg->InsertEdge(5, 7, 20);
			tg->InsertEdge(6, 7, 30);

			int result = tg->FindPath(3, 7, 99);
			Assert::AreEqual(3, result);
		}

	};
}