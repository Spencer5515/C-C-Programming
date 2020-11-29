#ifndef BARISTA_H
#define BARISTA_H

#include "Customer.h"
#include <iostream>

class Barista {
	private:
		int id;
		int startTime;
		int endTime;
		int totalCustomers;
		Customer* currentCustomer;
	public:
		Barista(int = -1);

		int getId() const;
		int getStartTime() const;
		int getEndTime() const;
		int getTotal() const;
		Customer* getCurrentCustomer() const;

		void setStartTime(int);
		void setEndTime(int);
		void setCurrentCustomer(Customer*);

		void updateTotal();
};

#endif