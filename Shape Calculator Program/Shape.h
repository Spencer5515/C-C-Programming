#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape {
	private: 
		int* numSides;
	
		void initialize(int);
		void cleanup(); 
	public:
		Shape(int);
		virtual ~Shape();

		int getNumSides() const;
};

#endif