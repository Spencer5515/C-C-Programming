#ifndef SIMULATION_H
#define SIMULATION_H

#include "Barista.h"
#include "ArrayQueue.hpp"
#include <iostream>

class Simulation {
	private:
		ArrayQueue<Customer*>* custQ;
		Barista* bari1;
		Barista* bari2;
		int epochs;
		double avgWaitTime;
	public:
		Simulation(int, int);
		~Simulation();
		void run();
};

#endif