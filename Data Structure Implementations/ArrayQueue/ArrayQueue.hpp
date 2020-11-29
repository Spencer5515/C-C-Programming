#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue : public Queue<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the queue
        int maxSize;

        // the current position of the front element in the queue
        int frontIndex;

        // the current position of the back element in the queue
        int backIndex;

        // copy the values from the argument queue to `this`
        void copy(const ArrayQueue<T>&);

    public:
        // default constructor
        ArrayQueue(int = 100);

        // copy constructor
        ArrayQueue(const ArrayQueue<T>&);

        // overloaded assignment operator
        ArrayQueue<T>& operator=(const ArrayQueue<T>&);

        // destructor
        virtual ~ArrayQueue();

        // return the element at the back of the queue
        virtual T back() const override;

        // remove all elements in the queue
        virtual void clear() override;

        // remove the front element from the queue
        virtual void dequeue() override;

        // add the argument to the back of the queue
        virtual void enqueue(const T&) override;

        // return the element at the front of the queue
        virtual T front() const override;

        // return the current length of the queue
        virtual int getLength() const override;

        // return the maximum size of the queue
        int getMaxSize() const;

        // determine if the queue is currently empty
        virtual bool isEmpty() const override;

        // determine if the queue is currently full
        bool isFull() const;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O()
*******************************************************************************/
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
	maxSize = i;
	buffer = new T[maxSize];
	frontIndex = 0;
	backIndex = 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O()
*******************************************************************************/
template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    clear();
	copy(rightObj);
	return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::back() const {
    return backIndex;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::clear() {
    for (int i = 0; i < maxSize; i++) {
		buffer[i] = 0;
	} // for loop
	this->length = 0;
	delete buffer;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    this->length = copyObj.length;
	buffer = copyObj.buffer;
	maxSize = copyObj.maxSize;
	frontIndex = copyObj.frontIndex;
	backIndex = copyObj.backIndex;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->length != 0) {
		if (frontIndex == maxSize - 1) {
			frontIndex = 0;
		} // else if
		else {
			frontIndex++;
		} // else
		this->length--;
	} // if
	else {
		cout << "Nothing to delete\n";
	} // else
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
	if (this->length == maxSize) {
		cerr << "ERROR: Queue is full\n";
	} // if
	else {
		if (backIndex == maxSize - 1) {
			backIndex = 0;
			buffer[backIndex] = elem;
		} // if
		else {
			backIndex++;
			buffer[backIndex] = elem;
		} // else
		this->length++;
	} // else
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T ArrayQueue<T>::front() const {
	return frontIndex;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

#endif
