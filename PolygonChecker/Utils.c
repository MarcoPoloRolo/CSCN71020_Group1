#include "Utils.h"

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("0. Exit\n");
	printf_s("1. Triangle Type\n");
	printf_s("2. Triangle Angles\n");
	printf_s("3. Rectangle analysis\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}