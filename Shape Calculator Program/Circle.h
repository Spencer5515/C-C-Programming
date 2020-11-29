#ifndef CIRCLE_H 
#define	CIRCLE_H

// #include "Shape.h"
#include "TwoDimens.h"
#include <iostream>
using namespace std;

class Circle : public TwoDimens {
	private:
		double* radius;

		void initialize(double);
		void cleanup();

		virtual void calculatePerimeter() override;
		virtual void calculateArea() override;
	public:
		Circle(double);
		~Circle();

		virtual double getPerimeter() override;
		virtual double getArea() override;
};

#endif