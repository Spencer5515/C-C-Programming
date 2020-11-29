#ifndef STORE_H
#define STORE_H

#include <string>

class Store {
	private:
		float price;
		int productID;
		std::string name;
		static float totalPrice;
	public:
		Store(float, int, std::string);
		float getPrice() const;
		int getProductID() const;
		static float getTotalPrice();
		static void setTotalPrice(float);
		static float getTax();
};

#endif
