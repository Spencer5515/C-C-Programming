#include "Pyramid.h"
#include <cmath>
#include <iostream>
using namespace std;

Pyramid::Pyramid(double s) : ThreeDimens(5) {
	initialize(s);
}

Pyramid::~Pyramid() {
	cleanup();
}

void Pyramid::initialize(double s) {
	side = new double(s);
}

void Pyramid::cleanup() { delete side; }

void Pyramid::calculateSurfaceArea() {
	*surfaceArea = sqrt(3) * pow(*side, 2);
}

void Pyramid::calculateVolume() {
	*volume = (sqrt(2) / 12) * pow(*side, 3);
}

double Pyramid::getSurfaceArea() {
	return ThreeDimens::getSurfaceArea();
}

double Pyramid::getVolume() {
	return ThreeDimens::getVolume();
}