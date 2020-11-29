#include "Shape.h"
#include <cstddef>
#include <iostream>
using namespace std;

Shape::Shape(int ns) {
	initialize(ns);
}

Shape::~Shape() {
	cleanup();
}

void Shape::initialize(int ns) {
	numSides = new int(ns);
}

void Shape::cleanup() { delete numSides; }

int Shape::getNumSides() const {
	return *numSides;
}