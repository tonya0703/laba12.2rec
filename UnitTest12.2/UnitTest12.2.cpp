#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR 12.2 рек/12.2 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* tmp = first;
			AddElem(1);
			AddElem(2);
			AddElem(3);
			AddElem(4);

			AddAfterElem(first, 2, 5);

			Assert::AreEqual(first->info, 1.0);
			Assert::AreEqual(first->link->info, 2.0);
			Assert::AreEqual(first->link->link->info, 5.0);
			Assert::AreEqual(first->link->link->link->info, 3.0);
			Assert::AreEqual(first->link->link->link->link->info, 4.0);

		}
	};
}
