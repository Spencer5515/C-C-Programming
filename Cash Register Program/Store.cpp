#include "Store.h"

float Store::totalPrice = 0.0f;

Store::Store(float price, int productID, std::string name) {
	this->price = price;
	this->totalPrice += price;
	this->productID = productID;
	this->name = name;
}

int Store::getProductID() const { return productID; }
float Store::getPrice() const { return price; }
float Store::getTotalPrice() { return totalPrice; }
float Store::getTax() { return totalPrice * 0.07; } // returns 7% tax value
void Store::setTotalPrice(float temp) { totalPrice = temp; }
