#include "Simulation.h"
#include "Barista.h"
#include "ArrayQueue.hpp"
#include "Customer.h"
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

Simulation::Simulation(int e, int c) {
	epochs = e; 
	custQ = new ArrayQueue<Customer*>(c);
	bari1 = new Barista(1);
	bari2 = new Barista(2);
}

Simulation::~Simulation() {
	for (int i = 0; i < custQ->getMaxSize(); i++) {
		custQ[i] = 0;
	} // for loop
	delete custQ;

	delete bari1;
	delete bari2;	
}

void Simulation::run() {
	int avg = 0;
	int ctr = 1;
	int bari1Ctr = 0;
	int bari2Ctr = 0;

	for (int i = 1; i < epochs; i++) {
		int temp = rand() % 10 + 1;
		if (temp < 4 && !(custQ->isFull())) { // 30% chance and queue is not full
			Customer* tempCustomer = new Customer(ctr, i);
			custQ->enqueue(tempCustomer); // enqueue tempCustomer

			cout << "Customer #" << ctr << " entered the Queue at time " << i << endl;

			if (!(custQ->isEmpty()) && bari1->getCurrentCustomer() == 0) { // if bari1 is free
				// takes front index customer and sets it too current
				bari1->setCurrentCustomer(custQ->front());
				// removes from queue
				custQ->dequeue();
				int tempT = i + (rand() % 10 + 5);
				avg += tempT;
				bari1->setStartTime(i);
				bari1->setEndTime(tempT);

				cout << "Barista #1 is helping customer #" << ctr << " at time " << tempT << endl;
			} // if
			else if (!(custQ->isEmpty()) && bari2->getCurrentCustomer() == 0) { // if bari2 is free
				// takes front index customer and sets it too current
				bari2->setCurrentCustomer(custQ->front());
				// removes from queue
				custQ->dequeue();
				int tempT = i + (rand() % 10 + 5);
				avg += tempT;
				bari2->setStartTime(i);
				bari2->setEndTime(tempT);

				cout << "Barista #2 is helping customer #" << ctr << " at time " << tempT << endl;
			} // else if
			ctr++;
		} // if	

		if (bari1->getEndTime() == i) {
			bari1->updateTotal();
			cout << "Customer #" << ctr << " finished at time " <<bari1->getEndTime() << endl;
			bari1->setCurrentCustomer(0);
		} // if
		else if (bari2->getEndTime() == i) {
			bari2->updateTotal();
			cout << "Customer #" << ctr << " finished at time " << bari2->getEndTime() << endl;
			bari2->setCurrentCustomer(0);
		} // else if
	} // for loop

	avgWaitTime = avg / ctr;

	cout << "\nSIMULATION FINISHED\n\n";
	cout << "Barista #1 helped " << bari1->getTotal() << " customers." << endl;
	cout << "Barista #2 helped " << bari2->getTotal() << " customers." << endl;
	cout << "Average wait time for a customer: " << avgWaitTime << endl;
}

