#include "StoreObject.hpp"

StoreObject::StoreObject(std::string className, float storedValue, std::string isleNum, std::string name, int ProductID) : Store(storedValue, ProductID, name) {
	this->className = className;
	this->storedValue = storedValue;
	this->isleNum = isleNum;
	this->name = name;
	this->ProductID = ProductID;
}

StoreObject::StoreObject(const StoreObject& copyObj): Store(copyObj.getStoredValue(), copyObj.getProductID(), copyObj.getName()) {
	*this = copyObj;
}

float StoreObject::getStoredValue() const { return storedValue; }
std::string StoreObject::getIsleNum() const { return isleNum; }
std::string StoreObject::getName() const { return name; }
int StoreObject::getProductID() const { return ProductID; }
