#ifndef TWODIMENS_H
#define TWODIMENS_H

#include "Shape.h"
#include <iostream>
using namespace std;

class TwoDimens : public Shape {
	private:
		void initialize();
		void cleanup();
	protected:
		double* perimeter;
		double* area;

		virtual void calculatePerimeter();
		virtual void calculateArea();
	public:
		TwoDimens(int);
		virtual ~TwoDimens();

		virtual double getPerimeter();
		virtual double getArea();

		friend ostream& operator<<(ostream&, const TwoDimens&);
};

#endif