#ifndef STOREOBJECT_HPP
#define STOREOBJECT_HPP

#include "Store.h"
#include <iostream>
#include <string>

class StoreObject: public Store {
	private:
		std::string className;
		float storedValue;
		std::string isleNum;
		std::string name;
		int ProductID;
	public:
		StoreObject(std::string, float, std::string, std::string, int);
		StoreObject(const StoreObject&);
		float getStoredValue() const;
		std::string getIsleNum() const;
		std::string getName() const;
		int getProductID() const;
		friend std::ostream& operator<<(std::ostream& outStream, const StoreObject& myObj)
		{
            outStream << myObj.className << " Name: " << myObj.getName() << std::endl;
            outStream << "Item Price: $" << myObj.getStoredValue() << std::endl;
            outStream << "Isle Number: " << myObj.getIsleNum() << std::endl;
            outStream << "ProductID: " << myObj.getProductID() << std::endl;
            return outStream;
        }
};

#endif
