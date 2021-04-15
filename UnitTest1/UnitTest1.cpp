#include "pch.h"
#include "CppUnitTest.h"
#include "../9.3/9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			route* n = new route[2];

			n[0].start = "abc";
			n[0].end = "b";
			n[0].nomer = 123;

			n[1].start = "acb";
			n[1].end = "agh";
			n[1].nomer = 33;

			Assert::AreEqual(1, Search(n, 2, 33));
		}
	};
}
