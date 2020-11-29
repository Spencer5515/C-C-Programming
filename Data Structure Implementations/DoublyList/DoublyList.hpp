#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class DoublyList : public List<T> {
    protected:
        // represents an element in the doubly linked list
        struct Node {
            T value;
            Node* next;
            Node* prev;

            Node(T v, Node* n = nullptr, Node* p = nullptr)
            : value(v), next(n), prev(p) { }
        };

        // a pointer to the front of the list
        Node* head;

    public:
        // default constructor
        DoublyList();

        // copy constructor
        DoublyList(const DoublyList<T>&);

        // overloaded assignment operator
        DoublyList<T>& operator=(const DoublyList<T>&);

        // destructor
        virtual ~DoublyList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // overloaded stream insertion operator
        /***********************************************************************
        *   Analyzing the number of output operations.
        *   Input size n is the length of the list.
        *
        *   Scenario #1, the if block executes:
        *       T(n) = 1
        *
        *   Scenario #2, the else block executes:
        *       T(n) = n + (n - 1) + 1
        *            = 2n
        *
        *   Asymptotic analysis:
        *       T(n) = O(n)
        ***********************************************************************/
        friend
        ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                Node* curr = myObj.head;

                while (curr != nullptr) {
                    outStream << curr->value;

                    if (curr->next != nullptr) {
                        outStream << " <--> ";
                    }

                    curr = curr->next;
                }

                outStream << endl;
            }

            return outStream;
        }
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
DoublyList<T>::DoublyList() {
    this->length = 0;
    head = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj) {
    this->length = copyObj.length;
    head = nullptr;

    if (this->length > 0) {
        head = new Node(copyObj.head->value);
        Node* myCurr = head;
        Node* copyCurr = copyObj.head->next;

        while (copyCurr->prev != nullptr) {
            Node* n = new Node(copyCurr->value);
            myCurr->prev->next = n;

			n-prev = copyCurr->next;
            myCurr->prev = n;
            n->next = copyCurr;
        } // while
    } // if
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    clear();

    this->length = rightObj.length;
    head = nullptr;

    if (this->length > 0) {
        head = new Node(rightObj.head->value);
        Node* myCurr = head;
        Node* copyCurr = rightObj.head->next;

        while (copyCurr->prev != nullptr) {
            Node* n = new Node(copyCurr->value);
            myCurr->prev->next = n;

			n-prev = copyCurr->next;
            myCurr->prev = n;
            n->next = copyCurr;
        } // while
    } // if
    return *this;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    } // if
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        } // while
        curr->next = n; 
		n->prev = curr; // links the prev back to curr from n
    } // if
    this->length++;    
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::clear() {
    while (head != nullptr) {
        head->prev = head;
        head = head->next;
		delete head->prev;
    } // while

    this->length = 0;
}

/*******************************************************************************
*   Analyzing the number of links accessed.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
T DoublyList<T>::getElement(int position) const {
     Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    } // for loop

    return curr->value;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O()
*******************************************************************************/
template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
        Node* n = new Node(elem);
        Node* curr = head;

        for (int i = 0; i < position; i++) {
            curr = curr->next;
        } // for loop

        if (curr->prev != nullptr) {
            curr->prev->next = n;
        } // if
        else if (position == 0) {
            head = n;
        } // else if

		n->prev = curr->next;
		curr->prev = n;
        n->next = curr;
        this->length++;
    } // else
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } //if
        else {
            Node* curr = head;

            for (int i = 0; i < position; i++) {
                curr = curr->next;
            } // for loop

            if (curr == head) {
				head->prev = head;
                head = head->next;
            } // if
            else {
                curr->prev->next = curr->next;
            } // else
            delete curr;
        } // else
        this->length--;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
        Node* curr = head;

        for (int i = 0; i < position; i++) {
            curr = curr->next;
        } // for loop
    	curr->value = elem;
    } // else
}

#endif
