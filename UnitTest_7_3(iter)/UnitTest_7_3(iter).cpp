#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_7_3(iter)\Lab_7_3(iter)\Lab_7_3(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73iter
{
	TEST_CLASS(UnitTest73iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;

			int **Z = new int *[n];
			for (int i = 0; i < n; i++)
				Z[i] = new int[n];

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					Z[i][j] = 3;

			Assert::AreEqual(Sum(Z, n), 9);

			for (int i = 0; i < n; i++)
				delete[] Z[i];
			delete[] Z;
		}
	};
}
