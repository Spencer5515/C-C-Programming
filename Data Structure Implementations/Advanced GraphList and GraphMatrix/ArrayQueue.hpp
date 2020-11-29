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

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    maxSize = i;
    frontIndex = 0;
    backIndex = maxSize - 1;
    this->length = 0;
    buffer = new T[maxSize];
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, cannot access the back\n";
        throw -1;
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
    if (buffer != nullptr) {
        delete[] buffer;
    }
    buffer = nullptr;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    frontIndex = 0;
    backIndex = maxSize - 1;
    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % maxSize];
    }

    if (this->length > 0) {
        backIndex = this->length - 1;
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, avoiding underflow\n";
    }
    else {
        frontIndex = (frontIndex + 1) % maxSize;
        this->length--;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        cout << "ERROR: queue is full, avoiding overflow\n";
    }
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        }

        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = elem;
        this->length++;
    }
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        cout << "ERROR: queue is empty, cannot access the front\n";
        throw -1;
    }

    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

#endif
