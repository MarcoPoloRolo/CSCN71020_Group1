#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangleType(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonProgramTest
{
	TEST_CLASS(TriangleTypeTests)
	{
	public:
		
		TEST_METHOD(TestONE)
		{
			char* expectedTri = "Isosceles triangle";
			int s1 = 3;
			int s2 = 3;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(TestTWO)
		{
			char* expectedTri = "Equilateral triangle";
			int s1 = 5;
			int s2 = 5;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(TestTHREE)
		{
			char* expectedTri = "Scalene triangle";
			int s1 = 5;
			int s2 = 6;
			int s3 = 7;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}

		TEST_METHOD(TestFOUR)
		{

			char* expectedTri = "Not a triangle";
			int s1 = 3;
			int s2 = 3;
			int s3 = 12;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
	};
	TEST_CLASS(TriangleAngleTests)
	{
		TEST_METHOD(TestONE)
		{

		}

		TEST_METHOD(TestTWO)
		{

		}

		TEST_METHOD(TestTHREE)
		{

		}

		TEST_METHOD(TestFOUR)
		{

		}

	};
	TEST_CLASS(FourPointsTest)
	{
		TEST_METHOD(TestONE)
		{

		}

		TEST_METHOD(TestTWO)
		{

		}

		TEST_METHOD(TestTHREE)
		{

		}

		TEST_METHOD(TestFOUR)
		{

		}
	};
}
