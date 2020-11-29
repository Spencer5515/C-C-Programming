#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "TwoDimens.h"
#include <iostream>
using namespace std;

class Triangle : public TwoDimens {
	private:
		double *a, *b, *c;

		void initialize(double, double, double);
		void cleanup();

		virtual void calculatePerimeter() override;
		virtual void calculateArea() override;
	public:
		Triangle(double, double, double);
		~Triangle();

		virtual double getPerimeter() override;
		virtual double getArea() override;
};

#endif