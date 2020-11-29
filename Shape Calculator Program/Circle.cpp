#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(double r) : TwoDimens(1) {
	initialize(r);
}

Circle::~Circle() {
	cleanup();
}

void Circle::initialize(double r) {
	radius = new double(r);
}

void Circle::cleanup() { delete radius; }

void Circle::calculatePerimeter() {
	*perimeter = 2 * M_PI * (*radius);
}

void Circle::calculateArea() {
	*area = M_PI * pow(*radius, 2);
}

double Circle::getPerimeter() {
	return TwoDimens::getPerimeter();
}

double Circle::getArea() {
	return TwoDimens::getArea();
}

