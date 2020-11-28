#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "Store.h"
#include <iostream>
#include <string>

template <typename T, typename C, typename D>
class Tools : public Store {
	private:
		void initialize(T, C, C, D);
		void cleanup();
	protected: 
		// specific attributes for the class
		T* storedValue;
		C* isleNum;
		C* toolName;
		D ProductID;
	public:
		Tools(T, C, C, D);
		Tools(const Tools&);
		virtual ~Tools();

		// accessor methods
		T getStoredValue() const;
		C getIsleNum() const;
		C getToolName() const;
		D getProductID() const;

		// overloaded friend << operator
		friend ostream& operator<<(ostream& outStream, const Tools& myObj) {
			outStream << "Tool Name: " << myObj.getToolName() << endl;
			outStream << "Item Price: $" << myObj.getStoredValue() << endl;
			outStream << "Isle Number: " << myObj.getIsleNum() << endl;
			outStream << "ProductID: " << myObj.getProductID() << endl;

			return outStream;
		} // outstream operator
};

// takes in 3 parameters
// uses 1st one to pass to parent and to use in a derived-class array
template <typename T, typename C, typename D>
Tools<T, C, D>::Tools(T f, C isle, C type, D d) : Store(f, d, type) {
	initialize(f, isle, type, d);
}

// copy constructor
template <typename T, typename C, typename D>
Tools<T, C, D>::Tools(const Tools& copyObj) : Store(copyObj.getStoredValue(), copyObj.getProductID(), copyObj.getToolName()) {
	initialize(copyObj.getStoredValue(), copyObj.getIsleNum(), copyObj.getToolName(), copyObj.getProductID());
} 

template <typename T, typename C, typename D>
Tools<T, C, D>::~Tools() { cleanup(); }

// initializer function
template <typename T, typename C, typename D>
void Tools<T, C, D>::initialize(T f, C isle, C type, D d) {
	// defaults all stored values to "zero" values
	storedValue = new T(f); 
	isleNum = new C(isle);
	toolName = new C(type);
	ProductID = d;
}

template <typename T, typename C, typename D>
void Tools<T, C, D>::cleanup() {
	delete storedValue;
	delete isleNum;
	delete toolName;
}

// accessor methods
template <typename T, typename C, typename D>
T Tools<T, C, D>::getStoredValue() const { return *storedValue; }

template <typename T, typename C, typename D>
C Tools<T, C, D>::getIsleNum() const { return *isleNum; }

template <typename T, typename C, typename D>
C Tools<T, C, D>::getToolName() const { return *toolName; }

template <typename T, typename C, typename D>
D Tools<T, C, D>::getProductID() const { return ProductID; }

#endif