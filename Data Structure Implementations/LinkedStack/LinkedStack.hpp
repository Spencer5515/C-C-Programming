#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedStack : public Stack<T> {
    protected:
        // represents an element in the stack
        struct Node {
            T value;
            Node* next;

            Node(T v, Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the stack
        Node* head;

    private:
        // copy the values from the argument stack to `this`
        void copy(const LinkedStack<T>&);

    public:
        // default constructor
        LinkedStack();

        // copy constructor
        LinkedStack(const LinkedStack<T>&);

        // overloaded assignment operator
        LinkedStack<T>& operator=(const LinkedStack<T>&);

        // destructor
        virtual ~LinkedStack();

        // remove all elements in the stack
        virtual void clear() override;

        // return the current length of the stack
        virtual int getLength() const override;

        // determine if the stack currently empty
        virtual bool isEmpty() const override;

        // remove the top element from the stack
        virtual void pop() override;

        // add the argument to the top of the stack
        virtual void push(const T&) override;

        // return the element at the top of the stack
        virtual T top() const override;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedStack<T>::LinkedStack() {
     this->length = 0;
    head = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rightObj) {
    clear();

    this->length = rightObj.length;
    head = nullptr;

    if (this->length > 0) {
        head = new Node(rightObj.head->value);
        Node* myCurr = head;
        Node* rightCurr = rightObj.head->next;

        while (rightCurr != nullptr) {
            Node* n = new Node(rightCurr->value);
            myCurr->next = n;
            myCurr = n;
            rightCurr = rightCurr->next;
        } // while
    } // if

    return *this;
}

/*******************************************************************************
*   Analyzing the number of basic operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedStack<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    } // hwile

    this->length = 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedStack<T>::copy(const LinkedStack<T>& copyObj) {
    this->length = copyObj.length;
    head = nullptr;

    if (this->length > 0) {
        head = new Node(copyObj.head->value);
        Node* myCurr = head;
        Node* copyCurr = copyObj.head->next;

        while (copyCurr != nullptr) {
            Node* n = new Node(copyCurr->value);
            myCurr->next = n;
            myCurr = n;
            copyCurr = copyCurr->next;
        } // while
    } // if
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int LinkedStack<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Assume the stack is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void LinkedStack<T>::pop() {
    if (isEmpty()) {
        cout << "ERROR: stack is empty, avoiding underflow\n";
    } // if
    else {
		Node* n=head;
		head=head->next;
		delete n;
		this->length--;
    } // else
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the stack.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void LinkedStack<T>::push(const T& elem) {
      Node *n= new Node(elem);
      n->value=elem;
      n->next=head;
      head=n;
      this->length++;
}

/*******************************************************************************
*   Analyzing the number of accesses to the buffer.
*   Input size n is the length of the stack.
*
*   Assume the stack is non-empty (n > 0).
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
T LinkedStack<T>::top() const {
      if (isEmpty()) {
        cout << "ERROR: stack is empty, cannot access the top\n";
        throw -1;
      } // if
      return head->value;
}	//working

#endif
