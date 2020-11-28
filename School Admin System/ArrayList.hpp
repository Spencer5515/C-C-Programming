#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // an auxiliary array for merge sort
        T* aux;

        // the maximum number of elements in the list
        int maxSize;

        // copy the values from the argument list to `this`
        void copy(const ArrayList<T>&);

        // swap the elements at the given positions
        void swap(int, int);

		void bubbleSort();
        void selectionSort();
        void insertionSort();
        void mergeSort(int, int);
    public:
        // constructor with the maximum size as the argument
        ArrayList(int = 100);

        // copy constructor
        ArrayList(const ArrayList<T>&);

        // overloaded assignment operator
        ArrayList<T>& operator=(const ArrayList<T>&);

        // destructor
        virtual ~ArrayList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // return the maximum size of the list
        int getMaxSize() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // determine if the list currently full
        bool isFull() const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

		virtual void sort(int) override;
};


// T(n) = O(1)
template <typename T>
void ArrayList<T>::swap(int i, int j) {
    T temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
}

// T(n) = O(1)
template <typename T>
ArrayList<T>::ArrayList(int i) {
    this->length = 0;
    maxSize = i;
    buffer = new T[maxSize];
    aux = nullptr;
}

// T(n) = O(n)
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

// T(n) = O(n)
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

// T(n) = O(n)
template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

// T(n) = O(n)
template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        cout << "ERROR: list is full\n";
    } // if
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        } // if

        buffer[this->length] = elem;
        this->length++;
    } // else
}

// T(n) = O(1)
template <typename T>
void ArrayList<T>::clear() {
    if (buffer != nullptr) {
        delete[] buffer;
    } // if

    buffer = nullptr;
    this->length = 0;
    if (aux != nullptr) {
        delete[] aux;
    } // if
}

// T(n) = O(n)
template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    aux = nullptr;

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    } // for loop
}

// T(n) = O(1)
template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
        throw -1;
    } // if

    return buffer[position];
}

// T(n) = O(1)
template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

// T(n) = O(1)
template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

// T(n) = O(n)
template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else if (isFull()) {
        cout << "ERROR: list is full\n";
    } // else
    else {
        for (int i = this->length; i > position; i--) {
            buffer[i] = buffer[i - 1];
        } // for loop
        
        buffer[position] = elem;
        this->length++;
    } // else
}

// T(n) = O(1)
template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

// T(n) = O(1)
template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

// T(n) = O(n)
template <typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
        for (int i = position; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        } // for loop

        this->length--;
    } // else
}

// T(n) = O(1)
template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
        buffer[position] = elem;
    } // else
}

// T(n) = O(n)
template <typename T>
void ArrayList<T>::sort(int algo) {
    if (algo == 1) {
        bubbleSort();
    }
    else if (algo == 2) {
        selectionSort();
    }
    else if (algo == 3) {
        insertionSort();
    }
    else if (algo == 4) {
        if (aux == nullptr) {
            aux = new T[maxSize];
        }
        mergeSort(0, this->length - 1);
    }
}

/*
Key Comparisons:
	best case: O(n^2)
	avg case: O(n^2)
	worst case: O(n^2)
Swaps:
	best case: O(0)
	avg case: O(n^2)
	worst case: O(n^2)
*/
template <typename T>
void ArrayList<T>::bubbleSort() {
    for (int i = 0; i < this->length - 1; i++) {
        for (int j = this->length - 1; j > i; j--) {
            if (buffer[j - 1] > buffer[j]) {
                swap(j - 1, j);
            } // if
        } // for loop
    } // for loop
}

/*
Key Comparisons:
	best case: O(n^2)
	avg case: O(n^2)
	worst case: O(n^2)
Swaps:
	best case: O(0)
	avg case: O(n)
	worst case: O(n)
*/
template <typename T>
void ArrayList<T>::selectionSort() {
    int t = -1;
    for (int i = 0; i < this->length - 1; i++) {
        t = i;
        for (int j = this->length - 1; j > i; j--) {
            if (buffer[t] > buffer[j]) {
                t = j;
            } // if
        } // for loop
        if (i != t) {
            swap(i, t);
        } // if
    } // for loop
}

/*
Key Comparisons:
	best case: O(n)
	avg case: O(n^2)
	worst case: O(n^2)
Swaps:
	best case: O(0)
	avg case: O(n^2)
	worst case: O(n^2)
*/
template <typename T>
void ArrayList<T>::insertionSort() {
    for (int i = 1; i < this->length; i++) {
        for (int j = i; j > 0 && buffer[j - 1] > buffer[j]; j--) {
            swap(j - 1, j);
        } // for loop
    } // for loop
}

/*
Key Comparisons:
	best case: O(n(log(n)))
	avg case: O(n(log(n)))
	worst case: O(n(log(n)))
Swaps:
	best case: O(0)
	avg case: O(n(log(n)))
	worst case: O(n(log(n)))
*/
template <typename T>
void ArrayList<T>::mergeSort(int left, int right) {
	if (left < right) { 
        int m = left + (right - left) / 2; 

        mergeSort(left, m); 
        mergeSort(m + 1, right); 

		for (int i = left; i <= right; i++) {
			aux[i] = buffer[i];
		} // for loop

		int i = left;
		int j = m + 1; 
		int k = left;

		while(i <= m && j <= right) {
			if(aux[i] <= aux[j]) {
				buffer[k] = aux[i];
				i++;
			} // if
			else {
				buffer[k] = aux[j++];                                          
			} // else
			k++;
		} // while
		while(i <= m) {
			buffer[k++] = aux[i++];
		} // while
    } // if
}

#endif
