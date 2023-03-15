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
			int triangleSides1[3] = { 0, 0, 0 };
			int* triangleSidesPtr1 = getTriangleSides(triangleSides1);
			char* result1 = analyzeTriangleType(triangleSidesPtr1[0], triangleSidesPtr1[1], triangleSidesPtr1[2]);
			printf_s("%s\n", result1);
			break;
		case 2:
			printf_s("Triangle Angles selected.\n");
			int triangleSides2[3] = { 0, 0, 0 };
			int* triangleSidesPtr2 = getTriangleSides(triangleSides2);
			char* result2 = analyzeTriangleAngles(triangleSidesPtr2[0], triangleSidesPtr2[1], triangleSidesPtr2[2]);
			printf_s("%s\n", result2);
			break;
		case 3:
			printf_s("Rectangle analysis selected.\n");
			int rectanglePoints[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			


			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

