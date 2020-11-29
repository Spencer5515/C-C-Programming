#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyVector {
	private: 
		T* buffer;
		T bufferSize;

		void initialize(int);
		void cleanup();
	public:
		MyVector();
		MyVector(int);
		MyVector(const MyVector&);
		virtual ~MyVector();

		void add(T);
		T back() const;
		int find(T) const;
		T front() const;
		void remove(T);
		void reset();
		int size() const;
		T& operator[](int) const;

		// inner class
		class VectorError {
			private:
				string e;
			public:
				VectorError(string = "");
				string what() const;
		};
};

template <typename T>
MyVector<T>::MyVector() {
	initialize(0);
}

template <typename T>
MyVector<T>::MyVector(int a) {
	initialize(a);
}

template <typename T>
MyVector<T>::MyVector(const MyVector& copyObj) {
	initialize(copyObj.size());
}

template <typename T>
MyVector<T>::~MyVector() {
	cleanup();
}

template <typename T>
void MyVector<T>::initialize(int a) {
	buffer = new T[a];
	bufferSize = a;
}

template <typename T>
void MyVector<T>::cleanup() {
	delete[] buffer;
}

// this works fine I knwo that
template <typename T>
void MyVector<T>::add(T item) {
	int capacity = bufferSize;

	if (bufferSize == capacity) {
		T* tempArr = new T[2 * capacity];
		for (int i = 0; i < capacity; i++) {
			tempArr[i] = buffer[i];
		} // for loop
		delete[] buffer;
		capacity *= 2;
		buffer = tempArr;
	} // if

	buffer[bufferSize] = item;
	bufferSize++;
}

template <typename T>
T MyVector<T>::back() const {
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot call back() method!");
	} // if
	else {
		return buffer[bufferSize - 1];
	} // else
}

// there is something wrong with this function
// no matter what I change I cannot determine the issue at hand
// I honestly give up with this one
template <typename T>
int MyVector<T>::find(T item) const {
	bool found = false;
	int foundIndex = 0;

	// this if statement works and throws an error
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot call find(T) method!");
	} // if
	else if (bufferSize > 0) {
		for (int i = 0; i < bufferSize; i++) {
			// if i just return here buffer[i] it kills the progam after the find() call
			if (buffer[i] == item) {
				foundIndex = i;
				found = true;
			} // if
		} // for loop
	} // else 
	if (found == true) {
		return foundIndex;
	} // if
	else if (found == false) {
		throw VectorError("Given item cannot be found in find(T) method!");
	} // if
} 

template <typename T>
T MyVector<T>::front() const {
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot call front() method!");
	} // if
	else {
		return buffer[0];
	} // else
}

template <typename T>
void MyVector<T>::remove(T item) {
	bool found = false;
	int foundIndex = 0;
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot call remove(T) method!");
	} // if
	else {
		for (int i = 0; i < bufferSize; i++) {
			if (buffer[i] == item) {
				found = true;
			} // if
		} // for loop
		if (found == false) {
			throw VectorError("Given item cannot be found in remove(T) method!");
		} // if
		else if (found == true) {
			T* tempBuffer = new T[bufferSize];
			for (int i = 0; i < bufferSize; i++) {
				tempBuffer[i] = buffer[i];
			} // for loop
			delete[] buffer;

			for (int i = 0; i < bufferSize; i++) {
				if (tempBuffer[i] == item) {
					foundIndex = i;
				} // if
				else if (i >= foundIndex) {
					tempBuffer[i] = tempBuffer[i + 1];
				} // else if
			} // for loop

			bufferSize--;
			for (int i = 0; i < bufferSize; i++) {
				buffer[i] = tempBuffer[i];
			} // for loop
			delete[] tempBuffer;
		} // else
	} // else
}

template <typename T>
void MyVector<T>::reset() {
	cleanup();
	initialize(0);
}

template <typename T>
int MyVector<T>::size() const {
	return bufferSize;
}

// not sure how to fix this weird error
template <typename T>
T& MyVector<T>::operator[](int index) const {
	if (bufferSize == 0) {
		throw VectorError("Vector is empty, cannot use [] operator!");
	} // if
	else if (index < 0 || index > bufferSize) {
		throw VectorError("Given Index is out of range!");
	} // else if
	else {
		return buffer[index];
	} // else 
}

template <typename T>
MyVector<T>::VectorError::VectorError(string s) : e(s) { }

template <typename T>
string MyVector<T>::VectorError::what() const { return e; }

#endif
