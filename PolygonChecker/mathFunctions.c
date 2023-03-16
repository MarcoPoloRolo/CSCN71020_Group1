#include "mathFunctions.h"

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

char* analyzeTriangleType(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

char* analyzeTriangleAngles(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= (side2 + side3) && side2 <= (side3 + side1) && side3 <= (side1 + side2)) //Checking if it would form a triangle
	{
		double angle1, angle2, angle3;
		angle1 = acos((pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) / ( 2 * side1 * side2)) * (180 / M_PI); //Cos law reaarranged to find angle
		angle2 = acos((pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / ( 2 * side2 * side3)) * (180 / M_PI);
		angle3 = acos((pow(side3, 2) + pow(side1, 2) - pow(side2, 2)) / ( 2 * side3 * side1)) * (180 / M_PI);
		printf("The three inside angles are: %f, %f, %f", angle1, angle2, angle3);
	}
	else
		result = "Not a triangle.";
	return result;
}

bool checkIfRectangle(int points[])
{
	//Get vectors of every possible set of two points (6 total)
	int vector1[2] = { points[2] - points[0], points[3] - points[1] };
	int vector2[2] = { points[4] - points[0], points[5] - points[1] };
	int vector3[2] = { points[6] - points[0], points[7] - points[1] };
	int vector4[2] = { points[4] - points[2], points[5] - points[3] };
	int vector5[2] = { points[6] - points[2], points[7] - points[3] };
	int vector6[2] = { points[6] - points[4], points[7] - points[5] };
	//Check dot product against each of other 3 points (2 values should result in 0 for it to be a rectangle)
	int dotProductList[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	dotProductList[0] = vector1[0] * vector2[0] + vector1[1] * vector2[1]; //If exactly 4 of these dot products result in 0, the points form a rectangle
	dotProductList[1] = vector1[0] * vector3[0] + vector1[1] * vector3[1];
	dotProductList[2] = vector2[0] * vector3[0] + vector2[1] * vector3[1];
	dotProductList[3] = vector1[0] * vector4[0] + vector1[1] * vector4[1];
	dotProductList[4] = vector1[0] * vector5[0] + vector1[1] * vector5[1];
	dotProductList[5] = vector4[0] * vector5[0] + vector4[1] * vector5[1];
	dotProductList[6] = vector2[0] * vector4[0] + vector2[1] * vector4[1];
	dotProductList[7] = vector2[0] * vector6[0] + vector2[1] * vector6[1];
	dotProductList[8] = vector4[0] * vector6[0] + vector4[1] * vector6[1];
	dotProductList[9] = vector3[0] * vector5[0] + vector3[1] * vector5[1];
	dotProductList[10] = vector3[0] * vector6[0] + vector3[1] * vector6[1];
	dotProductList[11] = vector5[0] * vector6[0] + vector5[1] * vector6[1];
	//Count how many values in array are 0
	int dotProductCounter = 0;
	for (int i = 0; i < 12; i++)
	{
		if (dotProductList[i] == 0)
			dotProductCounter++;
	}
	//Check if there are 4 zeroes
	bool isRectangle;
	if (dotProductCounter == 4)
		isRectangle = true;
	else
		isRectangle = false;
	return isRectangle;
}

int getRectanglePoints(int rectanglePoints[])
{
	for (int i = 0; i < 4; i++) //4 sets of x/y coords
	{
		printf("Enter the x coordinate of point %d: \n", i+1);
		scanf_s("%d", &rectanglePoints[i*2]);
		printf("Enter the y coordinate of point %d: \n", i+1);
		scanf_s("%d", &rectanglePoints[(i*2)+1]);
	}
	return rectanglePoints;
}

double getRectanglePerimeter(int points[]) //Need to create function still
{
	double rectanglePerimeter = 0;
	//Get the three side lengths
	double length1 =  sqrt(pow(points[2] - points[0], 2) + pow(points[3] - points[1], 2));
	double length2 =  sqrt(pow(points[4] - points[0], 2) + pow(points[5] - points[1], 2));
	double length3 =  sqrt(pow(points[6] - points[0], 2) + pow(points[7] - points[1], 2));
	//The longest of these 3 is the hypotenuse and should not be used
	if (length1 > length2 && length1 > length3)
		rectanglePerimeter = (2 * length2) + (2 * length3);
	else if (length2 > length3 && length2 > length1)
		rectanglePerimeter = (2 * length1) + (2 * length3);
	else
		rectanglePerimeter = (2 * length1) + (2 * length2);
	return (rectanglePerimeter);
}

double getRectangleArea(int points[]) //Need to create function still
{
	double rectangleArea = 0;
	//Get the three side lengths
	double length1 = sqrt(pow(points[2] - points[0], 2) + pow(points[3] - points[1], 2));
	double length2 = sqrt(pow(points[4] - points[0], 2) + pow(points[5] - points[1], 2));
	double length3 = sqrt(pow(points[6] - points[0], 2) + pow(points[7] - points[1], 2));
	//The longest of these 3 is the hypotenuse and should not be used
	if (length1 > length2 && length1 > length3)
		rectangleArea = length2 * length3;
	else if (length2 > length3 && length2 > length1)
		rectangleArea = length1 * length3;
	else
		rectangleArea = length1 * length2;
	return(rectangleArea);
}