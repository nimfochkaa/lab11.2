#include "pch.h"
#include "CppUnitTest.h"
#include "../11.2/11.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string testString1 = "Hello world";
			string testString2 = "   Multiple   spaces    ";
			string testString3 = "";
			string testString4 = "OneWord";

			Assert::AreEqual((size_t)2, CountWords(testString1));
			Assert::AreEqual((size_t)2, CountWords(testString2));
			Assert::AreEqual((size_t)0, CountWords(testString3));
			Assert::AreEqual((size_t)1, CountWords(testString4));
		}
	};
}
