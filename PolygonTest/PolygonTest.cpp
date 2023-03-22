#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangleType(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonTest
{
	TEST_CLASS(PolygonTest)
	{
	public:
		
		TEST_METHOD(AnalyzeTriangleTestONE)
		{
			char* expectedTri = "Isosceles triangle";
			int s1 = 3;
			int s2 = 3;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(AnalyzeTriangleTestTWO)
		{
			char* expectedTri = "Equilateral triangle";
			int s1 = 5;
			int s2 = 5;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(AnalyzeTriangleTestTHREE)
		{
			char* expectedTri = "Scalene triangle";
			int s1 = 5;
			int s2 = 6;
			int s3 = 7;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}

		TEST_METHOD(analyzeTriangleAnglesFOUR)
		{

			char* expectedTri = "Scalene triangle";
			int s1 = 6;
			int s2 = 6;
			int s3 = 7;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
	};
}
