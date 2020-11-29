#ifndef THREEDIMENS_H
#define THREEDIMENS_H

#include "Shape.h"
#include <iostream>
using namespace std;

class ThreeDimens : public Shape {
	private:
		void initialize();
		void cleanup();
	protected:
		double* surfaceArea;
		double* volume;

		virtual void calculateSurfaceArea();
		virtual void calculateVolume();

	public:
		ThreeDimens(int);
		virtual ~ThreeDimens();	

		virtual double getSurfaceArea();
		virtual double getVolume();

		friend ostream& operator<<(ostream&, const ThreeDimens&);
};

#endif