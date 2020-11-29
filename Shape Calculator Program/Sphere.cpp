#include "Sphere.h"
#include <cmath>
#include <iostream>
using namespace std;

Sphere::Sphere(double r) : ThreeDimens(1) {
	initialize(r);
}

Sphere::~Sphere() {
	cleanup();
}

void Sphere::initialize(double r) {
	radius = new double(r);
}

void Sphere::cleanup() { delete radius; }

void Sphere::calculateSurfaceArea() {
	*surfaceArea = 4 * M_PI * pow(*radius, 2);
}

void Sphere::calculateVolume() {
	*volume = M_PI * pow(*radius, 2);
}

double Sphere::getSurfaceArea() {
	return ThreeDimens::getSurfaceArea();
}

double Sphere::getVolume() {
	return ThreeDimens::getVolume();
}

