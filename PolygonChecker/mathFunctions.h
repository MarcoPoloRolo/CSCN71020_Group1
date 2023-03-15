#pragma once
#define RADIANS_TO_DEGREES = 57.29557795131
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
char* analyzeTriangleType(int side1, int side2, int side3);
char* analyzeTriangleAngles(int side1, int side2, int side3);
int* getTriangleSides(int* triangleSides);
int getRectanglePoints(int[]);
bool checkIfRectangle(int[]);
double getRectanglePerimeter(int[]);
double getRectangleArea(int[]);