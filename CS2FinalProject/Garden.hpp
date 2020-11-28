#ifndef GARDEN_HPP
#define GARDEN_HPP

#include "Store.h"
#include <iostream>
#include <string>

template <typename T, typename C, typename D>
class Garden : public Store {
	private:
		void initialize(T, C, C, D);
		void cleanup();
	protected: 
		// specific attributes for the class
		T* storedValue;
		C* isleNum;
		C* plantType;
		D ProductID;
	public:
		Garden(T, C, C, D);
		Garden(const Garden&);
		virtual ~Garden();

		// accessor methods
		T getStoredValue() const;
		C getIsleNum() const;
		C getPlantType() const;
		D getProductID() const;

		// overloaded friend << operator
		friend ostream& operator<<(ostream& outStream, const Garden& myObj) {
			outStream << "Plant Type: " << myObj.getPlantType() << endl;
			outStream << "Item Price: $" << myObj.getStoredValue() << endl;
			outStream << "Isle Number: " << myObj.getIsleNum() << endl;
			outStream << "ProductID: " << myObj.getProductID() << endl;

			return outStream;
		} // outstream operator
};

// takes in 3 parameters
// uses 1st one to pass to parent and to use in a derived-class array
template <typename T, typename C, typename D>
Garden<T, C, D>::Garden(T f, C isle, C type, D d) : Store(f, d, type) {
	initialize(f, isle, type, d);
}

// copy constructor
template <typename T, typename C, typename D>
Garden<T, C, D>::Garden(const Garden& copyObj) : Store(copyObj.getStoredValue(), copyObj.getProductID(), copyObj.getPlantType()) {
	initialize(copyObj.getStoredValue(), copyObj.getIsleNum(), copyObj.getPlantType(), copyObj.getProductID());
} 

template <typename T, typename C, typename D>
Garden<T, C, D>::~Garden() { cleanup(); }

// initializer function
template <typename T, typename C, typename D>
void Garden<T, C, D>::initialize(T f, C isle, C type, D d) {
	// defaults all stored values to "zero" values
	storedValue = new T(f); 
	isleNum = new C(isle);
	plantType = new C(type);
	ProductID = d;
}

template <typename T, typename C, typename D>
void Garden<T, C, D>::cleanup() {
	delete storedValue;
	delete isleNum;
	delete plantType;
}

// accessor methods
template <typename T, typename C, typename D>
T Garden<T, C, D>::getStoredValue() const { return *storedValue; }

template <typename T, typename C, typename D>
C Garden<T, C, D>::getIsleNum() const { return *isleNum; }

template <typename T, typename C, typename D>
C Garden<T, C, D>::getPlantType() const { return *plantType; }

template <typename T, typename C, typename D>
D Garden<T, C, D>::getProductID() const { return ProductID; }

#endif