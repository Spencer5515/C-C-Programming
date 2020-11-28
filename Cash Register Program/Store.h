#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
using namespace std;

class Store {
	private:
		float* price;	
		int ProdID;	
		string type;

		void initialize(float, int, string);
		void cleanup();
	protected:
		// static attirbute for total overall price
		static float totalPrice;
	public:
		Store(float, int, string);
		virtual ~Store();

		// just gets price and tax from product and whole order
		float getPrice() const;
		int getProdID() const;
		static float getTotalPrice();
		static void setTotalPrice(float);
		static float getTax();
};

#endif