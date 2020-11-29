#include "Barista.h"
#include "Customer.h"
#include <iostream>
using namespace std;

Barista::Barista(int i) { id = i; }

int Barista::getId() const { return id; }

int Barista::getStartTime() const { return startTime; }

int Barista::getEndTime() const { return endTime; }

int Barista::getTotal() const { return totalCustomers; }

Customer* Barista::getCurrentCustomer() const { return currentCustomer; }

void Barista::setStartTime(int s) { startTime = s; }

void Barista::setEndTime(int e) { endTime = e; }

void Barista:: setCurrentCustomer(Customer* c) { currentCustomer = c; }

void Barista::updateTotal() { totalCustomers += 1; }
