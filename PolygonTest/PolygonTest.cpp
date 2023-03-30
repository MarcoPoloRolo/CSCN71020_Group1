#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangleType(int side1, int side2, int side3);
extern "C" bool checkIfRectangle(int points[]);
extern "C" double getRectangleArea(int points[]);
extern "C" double getRectanglePerimeter(int points[]);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonProgramTest
{
	TEST_CLASS(TriangleTypeTests)
	{
	public:
		
		TEST_METHOD(TestIsoseles)
		{
			char* expectedTri = "Isosceles triangle";
			int s1 = 3;
			int s2 = 3;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(TestEquilateral)
		{
			char* expectedTri = "Equilateral triangle";
			int s1 = 5;
			int s2 = 5;
			int s3 = 5;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}
		TEST_METHOD(TestScalene)
		{
			char* expectedTri = "Scalene triangle";
			int s1 = 5;
			int s2 = 6;
			int s3 = 7;
			char* actualTri = analyzeTriangleType(s1, s2, s3);
			Assert::AreEqual(expectedTri, actualTri);
		}

		TEST_METHOD(TestNoTriangle)
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

			TEST_METHOD(TestOnAngle)
			{

				bool expected1 = true;
				int CheckIfRectangle1[8] = { -1, 0, 0, 2, 3, -2, 4, 0 };
				bool Actual1 = checkIfRectangle(CheckIfRectangle1);
				Assert::AreEqual(expected1, Actual1);
			}

			TEST_METHOD(TestSquare)
			{
				bool expected2 = true;
				int CheckIfRectangle2[8] = { 4,4,2,2,4,2,2,4 };
				bool Actual2 = checkIfRectangle(CheckIfRectangle2);
				Assert::AreEqual(expected2, Actual2);
			}

			TEST_METHOD(TestNotRectangle)
			{
				bool expected3 = false;
				int CheckIfRectangle3[8] = { 8,5,7,9,12,4,8,9 };
				bool Actual3 = checkIfRectangle(CheckIfRectangle3);
				Assert::AreEqual(expected3, Actual3);

			}

			TEST_METHOD(TestNegativePoints)
			{
				bool expected4 = true;
				int CheckIfRectangle4[8] = { -2,-2, - 4, -4, -2, -4,-4, -2 };
				bool Actual4 = checkIfRectangle(CheckIfRectangle4);
				Assert::AreEqual(expected4, Actual4);

			}

	};
	TEST_CLASS(RectangleArea)
	{
		TEST_METHOD(AreaNegatives)
		{
			double ExpectedArea1 = 10;
			int Rectangle1[8] = { -1, 0, 0, 2, 3, -2, 4, 0 };
			double Actual1 = round(getRectangleArea(Rectangle1));
			Assert::AreEqual(ExpectedArea1, Actual1);
			//printf("lf", Actual1);
		}
		TEST_METHOD(AreaSquare)
		{
			double ExpectedArea2 = 4;
			int Rectangle2[8] = { 4,4,2,2,4,2,2,4 };
			double Actual2 = getRectangleArea(Rectangle2);
			Assert::AreEqual(ExpectedArea2, Actual2);
		}
	};
	TEST_CLASS(RectanglePerimeter)
		{
			TEST_METHOD(PerimeterNegatives)

			{    
				double ExpectedPerimeter1 = 13.4164;
				int Rectangle1[8] = { -1, 0, 0, 2, 3, -2, 4, 0 };
				double Actual1 = getRectanglePerimeter(Rectangle1);
				
				Assert::AreEqual(ExpectedPerimeter1, Actual1, 0.00001);
				
			}
			TEST_METHOD(PerimeterSquare)
			{
				double ExpectedPerimeter2 = 8;
				int Rectangle2[8] = { 4,4,2,2,4,2,2,4 };
				double Actual2 = round(getRectanglePerimeter(Rectangle2));
				Assert::AreEqual(ExpectedPerimeter2, Actual2);
			}




	};
}
