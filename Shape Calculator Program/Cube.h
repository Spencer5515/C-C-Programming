#ifndef CUBE_H
#define	CUBE_H

#include "Shape.h"
#include "ThreeDimens.h"
#include <iostream>
using namespace std;

class Cube : public ThreeDimens {
	private:
		double* side;

		void initialize(double);
		void cleanup();

		virtual void calculateSurfaceArea() override;
		virtual void calculateVolume() override;
	public:
		Cube(double);
		~Cube();

		virtual double getSurfaceArea() override;
		virtual double getVolume() override;
};

#endif