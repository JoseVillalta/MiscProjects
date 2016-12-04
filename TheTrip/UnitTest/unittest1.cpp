#include "stdafx.h"
#include "CppUnitTest.h"
#include "trip.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{		
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            vector<double> v;
            v.push_back(10.00);
            v.push_back(20.00);
            v.push_back(30.00);
            string result = calculate(3, v);
            string expectedVal = "$10.00";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod2)
        {
            vector<double>v;
            v.push_back(15.01);
            v.push_back(15.00);
            v.push_back(3.01);
            v.push_back(3.00);
            string result = calculate(4, v);
            string expectedVal = "$11.99";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod3)
        {
            vector<double>v;
            v.push_back(5000.00);
            v.push_back(11.11);
            v.push_back(11.11);
            v.push_back(11.11);
            v.push_back(11.11);
            string result = calculate(5, v);
            string expectedVal = "$3991.11";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod4)
        {
            vector<double>v;
            v.push_back(0.01);
            v.push_back(0.03);
            v.push_back(0.03);
            string result = calculate(3, v);
            string expectedVal = "$0.01";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod5)
        {
            vector<double>v;
            v.push_back(25.00);
            v.push_back(25.00);
            v.push_back(25.00);
            v.push_back(28.00);
            string result = calculate(4, v);
            string expectedVal = "$2.25";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod6)
        {
            vector<double>v;
            v.push_back(10.01);
            v.push_back(15.25);
            v.push_back(18.96);
            string result = calculate(3, v);
            string expectedVal = "$4.73";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod7)
        {
            vector<double>v;
            v.push_back(25.03);
            v.push_back(25.00);
            v.push_back(25.00);
            v.push_back(25.00);
            string result = calculate(4, v);
            string expectedVal = "$0.02";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod8)
        {
            vector<double>v;
            for (int i = 0; i < 20; i++)
            {
                v.push_back(0.01);
            }
            v.push_back(0.03);
            string result = calculate(21, v);
            string expectedVal = "$0.01";
            Assert::AreEqual(expectedVal, result);
        }
        TEST_METHOD(TestMethod9)
        {
            vector<double>v;
            v.push_back(123.12);
            v.push_back(6.13);
            v.push_back(9.44);
            v.push_back(89.08);
            v.push_back(278.78);
            v.push_back(223.78);
            v.push_back(78.45);
            v.push_back(912.89);
            v.push_back(554.76);
            v.push_back(547.57);
            v.push_back(1781.89);
            v.push_back(907.07);
            string result = calculate(12, v);
            string expectedVal = "$2407.09";
            Assert::AreEqual(expectedVal, result);
        }
    };
}