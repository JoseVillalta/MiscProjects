#include "stdafx.h"
#include "CppUnitTest.h"
#include "AustralianVoting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAustralianVoting
{		
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(2, 2);
            vector<string> candidates;
            vector<vector<int>> votes;
            candidates.push_back("John Doe");
            candidates.push_back("Jane Smith");
            candidates.push_back("Jane Austen");

            vector<int> v1 = { 1, 2, 3 };
            vector<int> v2 = { 2, 1, 3 };
            vector<int> v3 = { 2, 3, 1 };
            vector<int> v4 = { 1, 2, 3 };
            vector<int> v5 = { 3, 1, 2 };


            auto result = CountVotes(candidates, votes);
            string expectedResult = "John Doe";
            vector <string> v = get<1>(result);
            Assert::AreEqual(v.at(0), expectedResult);
        }

    };
}