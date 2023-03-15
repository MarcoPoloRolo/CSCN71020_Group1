#include <stdio.h>
#include <stdbool.h>

#include "Utils.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Triangle Angles selected.\n");
			int triangleSides2[3] = { 0, 0, 0 };
			int* triangleSidesPtr2 = getTriangleSides(triangleSides2);
			char* result2 = analyzeTriangleAngles(triangleSidesPtr2[0], triangleSidesPtr2[1], triangleSidesPtr2[2]);
			printf_s("%s\n", result2);
			break;
		case 1:
			printf_s("Triangle Type selected.\n");
			int triangleSides1[3] = { 0, 0, 0 };
			int* triangleSidesPtr1 = getTriangleSides(triangleSides1);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result1 = analyzeTriangleType(triangleSidesPtr1[0], triangleSidesPtr1[1], triangleSidesPtr1[2]);
			printf_s("%s\n", result1);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

