#include "ThreeDimens.h"
#include <iostream>
using namespace std;

ThreeDimens::ThreeDimens(int ns) : Shape(ns) {
}

ThreeDimens::~ThreeDimens() {
	cleanup();
}

void ThreeDimens::initialize() {
	*surfaceArea = 0;
	*volume = 0;
}

void ThreeDimens::cleanup() {
	delete surfaceArea;
	surfaceArea = nullptr;
	delete volume;
	volume = nullptr;
}

void ThreeDimens::calculateSurfaceArea() { *surfaceArea = 0; }

void ThreeDimens::calculateVolume() { *volume = 0; }

double ThreeDimens::getSurfaceArea() { return *surfaceArea; }

double ThreeDimens::getVolume() { return *volume; }

ostream& operator<<(ostream& outStream, const ThreeDimens& myObj) {
	outStream << "Number of Sides: " << myObj.getNumSides() << endl;
	outStream << "Surface Area: " << myObj.surfaceArea << endl;
	outStream << "volume: " << myObj.volume << endl;

	return outStream;
} // outstream operator
