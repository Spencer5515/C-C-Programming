#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue : public Queue<T> {
    protected:
        // represents an element in the queue
        struct Node {
            T value;
            Node* next;

            Node(T v, Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the queue
        Node* head;

        // a pointer to the back of the queue
        Node* last;

    private:
        // copy the values from the argument queue to `this`
        void copy(const LinkedQueue<T>&);

    public:
        // default constructor
        LinkedQueue();

        // copy constructor
        LinkedQueue(const LinkedQueue<T>&);

        // overloaded assignment operator
        LinkedQueue<T>& operator=(const LinkedQueue<T>&);

        // destructor
        virtual ~LinkedQueue();

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

        // determine if the queue currently empty
        virtual bool isEmpty() const override;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->length = 0;
    head = nullptr;
	last = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
	clear();

	if (rightObj.head == nullptr) {
	   	head = last = nullptr;
   	} // if
   	else {
	   	head = new Node(rightObj.head);
	   	Node* tempRight = rightObj.head->next;
	   	Node* temp = head;

	   	while (tempRight != nullptr) {
		   	temp->next = new Node(tempRight, nullptr, temp);
		   	temp = temp->next;
		   	tempRight = tempRight->next;
	   	} // while
	   	last = temp;
   	} // else

	return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of accesses to `last`.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T LinkedQueue<T>::back() const {
    return last->value;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    } // while
    last = head; // sets head and tail to same position

    this->length = 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
   if (copyObj.head == nullptr) {
	   head = last = nullptr;
   } // if
   else {
	   head = new Node(copyObj.head);
	   Node* tempCopy = copyObj.head->next;
	   Node* temp = head;

	   while (tempCopy != nullptr) {
		   temp->next = new Node(tempCopy, nullptr, temp);
		   temp = temp->next;
		   tempCopy = tempCopy->next;
	   } // while
	   last = temp;
   } // else
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::dequeue() {
	if (head == nullptr) {
		cerr << "ERROR: Queue is empty\n";
	} // if
	else {
		Node* temp = head;
		head = head->next;

		if (head == nullptr) {
			last = nullptr;
		} // if

		delete temp;
	} // else

	this->length--;

	// Node* temp = head;
    // if (head == nullptr) {
	// 	cerr << "ERROR: Queue is empty\n";
	// } // if
	// else {
	// 	if (n->next != nullptr) {
	// 		head = head->next;
	// 		head =n;
	// 	} // if
	// 	else {
	// 		head = nullptr;
	// 		last = nullptr;
	// 	} // else

	// 	delete temp;
	// } // else
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
	Node* n = new Node(elem);
	if (last == nullptr) {
		head = last = n;
	} // if	
	else {
		last->next = n;
		last = n;
	} // else

	this->length++;

	// Node* n = new Node(elem);
	// if (last == nullptr) {
	// 	last->next = nullptr;
	// 	last = n;
	// 	head = last;
	// } // if
	// else {
	// 	last->next = n;
	// 	n->next = nullptr;
	// 	last = n;
	// } // else
}

/*******************************************************************************
*   Analyzing the number of accesses to `head`.
*   Input size n is the length of the queue.
*
*   Assume the queue is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
T LinkedQueue<T>::front() const {
    return head->value;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;    
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the queue.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

#endif

