#include "TwoDimens.h"
#include <iostream>
using namespace std;

TwoDimens::TwoDimens(int ns) : Shape(ns) {}

TwoDimens::~TwoDimens() {
	cleanup();
}

void TwoDimens::initialize() {
	*perimeter = 0;
	*area = 0;
}

void TwoDimens::cleanup() {
	delete perimeter;
	perimeter = nullptr;
	delete area;
	area = nullptr;
}

void TwoDimens::calculatePerimeter() { *perimeter = 0; }

void TwoDimens::calculateArea() { *area = 0; }

double TwoDimens::getPerimeter() { return *perimeter; }

double TwoDimens::getArea() { return *area; }

ostream& operator<<(ostream& outStream, const TwoDimens& myObj) {
	outStream << "Number of Sides: " << myObj.getNumSides() << endl;
	outStream << "Perimeter: " << myObj.perimeter << endl;
	outStream << "Area: " << myObj.area << endl;

	return outStream;
} // outstream operator
