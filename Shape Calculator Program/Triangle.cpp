#include "Triangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle(double aa, double bb, double cc) : TwoDimens(3) {
	initialize(aa, bb, cc);
}

Triangle::~Triangle() {
	cleanup();
}

void Triangle::initialize(double aa, double bb, double cc) {
	a = new double(aa);
	b = new double(bb);
	c = new double(cc);
}

void Triangle::cleanup() {
	delete a;
	delete b;
	delete c;
}

void Triangle::calculatePerimeter() {
	*perimeter = *a + *b + *c;
}

void Triangle::calculateArea() {
	double s = *perimeter / 2;
	*area = sqrt(s * (s - *a) * (s - *b) * (s - *c));
}

double Triangle::getPerimeter() {
	return TwoDimens::getPerimeter();
}

double Triangle::getArea() {
	return TwoDimens::getArea();
}

