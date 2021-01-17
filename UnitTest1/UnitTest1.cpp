#include "pch.h"
#include "CppUnitTest.h"
#include <Windows.h>
#include  "../Project1/functions.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace UnitTest1
	{
		TEST_CLASS(UnitTest1)
		{
		public:

			TEST_METHOD(TestMethodSortingMax)
			{
				const int size = 20001;
				int a[size];
				int expected = 1000;
				generateArray(a, size);
				sortingMax(a, size);
				int actual = a[size - 1];
				Assert::AreEqual(expected, actual);
			}
		};
	}

	namespace UnitTest2
	{
		TEST_CLASS(UnitTest2)
		{
		public:

			TEST_METHOD(TestMethodSortingMin)
			{
				const int size = 20001;
				int a[size];
				int expected = 1;
				generateArray(a, size);
				sortingMin(a, size);
				int actual = a[size - 1];
				Assert::AreEqual(expected, actual);

			}
		};
	}

	namespace UnitTest3
	{
		TEST_CLASS(UnitTest3)
		{
		public:

			TEST_METHOD(TestMethodSortingMinError)
			{
				const int size = 20001;
				int a[size];
				int expected = 2;
				generateArray(a, size);
				sortingMin(a, size);
				int actual = a[size - 1];
				Assert::AreEqual(expected, actual);

			}
		};
	}

