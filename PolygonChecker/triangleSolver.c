#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

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