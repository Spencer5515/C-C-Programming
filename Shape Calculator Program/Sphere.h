#ifndef SPHERE_H 
#define	SPHERE_H

#include "Shape.h"
#include "ThreeDimens.h"
#include <iostream>
using namespace std;

class Sphere : public ThreeDimens {
	private:
		double* radius;

		void initialize(double);
		void cleanup();

		virtual void calculateSurfaceArea() override;
		virtual void calculateVolume() override;
	public:
		Sphere(double);
		~Sphere();

		virtual double getSurfaceArea() override;
		virtual double getVolume() override;
};

#endif