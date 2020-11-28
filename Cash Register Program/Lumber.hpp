#ifndef LUMBER_HPP
#define LUMBER_HPP

#include "Store.h"
#include <iostream>
#include <string>

template <typename T, typename C, typename D>
class Lumber : public Store {
	private:
		void initialize(T, C, C, D);
		void cleanup();
	protected: 
		// specific attributes for the class
		T* storedValue;
		C* isleNum;
		C* lumberType;
		D ProductID;
	public:
		Lumber(T, C, C, D);
		Lumber(const Lumber&);
		virtual ~Lumber();

		// accessor methods
		T getStoredValue() const;
		C getIsleNum() const;
		C getLumberType() const;
		D getProductID() const;

		// overloaded friend << operator
		friend ostream& operator<<(ostream& outStream, const Lumber& myObj) {
			outStream << "Lumber Type: " << myObj.getLumberType() << endl;
			outStream << "Item Price: $" << myObj.getStoredValue() << endl;
			outStream << "Isle Number: " << myObj.getIsleNum() << endl;
			outStream << "ProductID: " << myObj.getProductID() << endl;

			return outStream;
		} // outstream operator
};

// takes in 3 parameters
// uses 1st one to pass to parent and to use in a derived-class array
template <typename T, typename C, typename D>
Lumber<T, C, D>::Lumber(T f, C isle, C type, D d) : Store(f, d, type) {
	initialize(f, isle, type, d);
}

// copy constructor
template <typename T, typename C, typename D>
Lumber<T, C, D>::Lumber(const Lumber& copyObj) : Store(copyObj.getStoredValue(), copyObj.getProductID(), copyObj.getLumberType()) {
	initialize(copyObj.getStoredValue(), copyObj.getIsleNum(), copyObj.getLumberType(), copyObj.getProductID());
} 

template <typename T, typename C, typename D>
Lumber<T, C, D>::~Lumber() { cleanup(); }

// initializer function
template <typename T, typename C, typename D>
void Lumber<T, C, D>::initialize(T f, C isle, C type, D d) {
	// defaults all stored values to "zero" values
	storedValue = new T(f); 
	isleNum = new C(isle);
	lumberType = new C(type);
	ProductID = d;
}

template <typename T, typename C, typename D>
void Lumber<T, C, D>::cleanup() {
	delete storedValue;
	delete isleNum;
	delete lumberType;
}

// accessor methods
template <typename T, typename C, typename D>
T Lumber<T, C, D>::getStoredValue() const { return *storedValue; }

template <typename T, typename C, typename D>
C Lumber<T, C, D>::getIsleNum() const { return *isleNum; }

template <typename T, typename C, typename D>
C Lumber<T, C, D>::getLumberType() const { return *lumberType; }

template <typename T, typename C, typename D>
D Lumber<T, C, D>::getProductID() const { return ProductID; }

#endif