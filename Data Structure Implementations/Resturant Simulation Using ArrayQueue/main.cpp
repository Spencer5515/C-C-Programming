#include "Simulation.h"
#include "ArrayQueue.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
	srand(time(0));
	Simulation(100, 10).run();

	cout << "\nProgram Ending...\n";
	return 0;
}