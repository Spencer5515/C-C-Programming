#include "Square.h"
#include <cmath>
#include <iostream>
using namespace std;

Square::Square(double r) : TwoDimens(4) {
	initialize(r);
}

Square::~Square() {
	cleanup();
}

void Square::initialize(double r) {
	side = new double(r);
}

void Square::cleanup() { delete side; }

void Square::calculatePerimeter() {
	*perimeter = 4 * (*side);
}

void Square::calculateArea() {
	*area = pow(*side, 2);
}

double Square::getPerimeter() {
	return TwoDimens::getPerimeter();
}

double Square::getArea() {
	return TwoDimens::getArea();
}

