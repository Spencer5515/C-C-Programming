#include "Cube.h"
#include <cmath>
#include <iostream>
using namespace std;

Cube::Cube(double s) : ThreeDimens(6) {
	initialize(s);
}

Cube::~Cube() {
	cleanup();
}

void Cube::initialize(double s) {
	side = new double(s);
}

void Cube::cleanup() { delete side; }

void Cube::calculateSurfaceArea() {
	*surfaceArea = 6 * pow(*side, 2);
}

void Cube::calculateVolume() {
	*volume = pow(*side, 3);
}

double Cube::getSurfaceArea() {
	return ThreeDimens::getSurfaceArea();
}

double Cube::getVolume() {
	return ThreeDimens::getVolume();
}