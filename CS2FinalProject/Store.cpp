#include "Store.h"
#include <iostream>
#include <cstddef>
using namespace std;

// holds total price value
float Store::totalPrice = 0.0f;

Store::Store(float f, int d, string t) { initialize(f, d, t); }

Store::~Store() { cleanup(); }

// initializer for Store
void Store::initialize(float f, int d, string t) {
	price = new float(f); // sets f as price 
	totalPrice += (*price); // adds current price to total
	ProdID = d;
	type = t;
}

void Store::cleanup() { 
	delete price; 
	totalPrice = 0.0f;
} 

float Store::getPrice() const { return *price; }

int Store::getProdID() const { return ProdID; }

float Store::getTotalPrice() { return totalPrice; }

void Store::setTotalPrice(float temp) { totalPrice = temp; }

// calculates tax to be added to entire order
float Store::getTax() { return totalPrice * 0.07; } // returns 7% tax value
