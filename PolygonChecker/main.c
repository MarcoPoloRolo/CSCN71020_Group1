#include "Utils.h"
#include "mathFunctions.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 0:
			continueProgram = false;
			break;
		case 1:
			printf_s("Triangle Type selected.\n");
			int case1sides[TRIANGLE_SIDES] = { 0, 0, 0 };
			int* triangleSidesPtr1 = getTriangleSides(case1sides);
			char* result1 = analyzeTriangleType(triangleSidesPtr1[0], triangleSidesPtr1[1], triangleSidesPtr1[2]);
			printf_s("%s\n", result1);
			break;
		case 2:
			printf_s("Triangle Angles selected.\n");
			int case2sides[TRIANGLE_SIDES] = { 0, 0, 0 };
			int* triangleSidesPtr2 = getTriangleSides(case2sides);
			char* result2 = analyzeTriangleAngles(triangleSidesPtr2[0], triangleSidesPtr2[1], triangleSidesPtr2[2]);
			printf_s("%s\n", result2);
			break;
		case 3:
			printf_s("Rectangle analysis selected.\n");
			int rectanglePoints[RECTANGLE_POINTS] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			getRectanglePoints(rectanglePoints);
			if (!checkIfRectangle(rectanglePoints))
				printf("Those points do not form a rectangle.\n");
			else
			{
				printf("The perimeter of this rectangle is %f.\n", getRectanglePerimeter(rectanglePoints));
				printf("The area of this rectangle is %f.\n", getRectangleArea(rectanglePoints));
			}


			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

