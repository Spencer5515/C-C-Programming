#ifndef PYRAMID_H
#define	PYRAMID_H

#include "Shape.h"
#include "ThreeDimens.h"
#include <iostream>
using namespace std;

class Pyramid : public ThreeDimens {
	private:
		double* side;

		void initialize(double);
		void cleanup();

		virtual void calculateSurfaceArea() override;
		virtual void calculateVolume() override;
	public:
		Pyramid(double);
		~Pyramid();

		virtual double getSurfaceArea() override;
		virtual double getVolume() override;
};

#endif