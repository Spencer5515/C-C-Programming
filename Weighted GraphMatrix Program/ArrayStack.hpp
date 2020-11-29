#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the stack
        int maxSize;

        // the current position of the top element in the stack
        int topPosition;

        // copy the values from the argument stack to `this`
        void copy(const ArrayStack<T>&);

    public:
        // default constructor
        ArrayStack(int = 100);

        // copy constructor
        ArrayStack(const ArrayStack<T>&);

        // overloaded assignment operator
        ArrayStack<T>& operator=(const ArrayStack<T>&);

        // destructor
        virtual ~ArrayStack();

        // remove all elements in the stack
        virtual void clear() override;

        // return the current length of the stack
        virtual int getLength() const override;

        // return the maximum size of the stack
        int getMaxSize() const;

        // determine if the stack currently empty
        virtual bool isEmpty() const override;

        // determine if the stack is currently full
        bool isFull() const;

        // remove the top element from the stack
        virtual void pop() override;

        // add the argument to the top of the stack
        virtual void push(const T&) override;

        // return the element at the top of the stack
        virtual T top() const override;
};

template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    this->length = 0;
    maxSize = i;
    topPosition = -1;
    buffer = new T[maxSize];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    this->length = 0;
    topPosition = -1;
    if (buffer != nullptr) {
        delete[] buffer;
    }
    buffer = nullptr;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    topPosition = this->length - 1;
    buffer = new T[maxSize];

    for (int i = 0; i < copyObj.length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        cout << "ERROR: stack is empty, avoiding underflow\n";
    }
    else {
        topPosition--;
        this->length--;
    }
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        cout << "ERROR: stack is full, avoiding overflow\n";
    }
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        }
        
        buffer[++topPosition] = elem;
        this->length++;
    }
}

template <typename T>
T ArrayStack<T>::top() const {
    if (isEmpty()) {
        cout << "ERROR: stack is empty, cannot access the top\n";
        throw -1;
    }

    return buffer[topPosition];
}

#endif
