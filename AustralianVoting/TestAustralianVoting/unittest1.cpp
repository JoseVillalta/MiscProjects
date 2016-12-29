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
            auto result = CountVotes(candidates, votes);
            string expectedResult = "John Doe";
            Assert::AreEqual(get<1>(result), expectedResult);
        }

    };
}