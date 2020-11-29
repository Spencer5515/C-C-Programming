#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int i, int s) {
	id = i;
	startTime = s;
}

int Customer::getId() const { return id; }

int Customer::getStartTime() const { return startTime; } 