#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4рек/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64рек
{
	TEST_CLASS(UnitTest64рек)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1, 2, 3, 4 };
			int size = 4;
			(SumAbsAfterFirstZero(a, size), 10);
		}
	};
}
