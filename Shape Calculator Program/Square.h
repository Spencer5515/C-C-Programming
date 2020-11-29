#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "TwoDimens.h"
#include <iostream>
using namespace std;

class Square : public TwoDimens {
	private:
		double* side;

		void initialize(double);
		void cleanup();

		virtual void calculatePerimeter() override;
		virtual void calculateArea() override;
	public:
		Square(double);
		~Square();

		virtual double getPerimeter() override;
		virtual double getArea() override;
};

#endif