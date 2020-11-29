#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
    protected:
        // represents an element in the linked list
        struct Node {
            T value;
            Node* next;

            Node(T v, Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the list
        Node* head;

    public:
        // default constructor
        LinkedList();

        // copy constructor
        LinkedList(const LinkedList<T>&);

        // overloaded assignment operator
        LinkedList<T>& operator=(const LinkedList<T>&);

        // destructor
        virtual ~LinkedList();

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
        ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                Node* curr = myObj.head;

                while (curr != nullptr) {
                    outStream << curr->value;

                    if (curr->next != nullptr) {
                        outStream << " --> ";
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
*   T(n) = 2
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
LinkedList<T>::LinkedList() {
    this->length = 0;
    head = nullptr;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block does not execute:
*       T(n) = 2
*
*   Scenario #2, the if block executes:
*       T(n) = 2 + 3 + 4n
*            = 4n + 5
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
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
        }
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block does not execute:
*       T(n) = 2n + 2 + 2
*            = 2n + 4
*
*   Scenario #2, the if block executes:
*       T(n) = 2n + 2 + 2 + 3 + 4n
*            = 6n + 7
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
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
        }
    }

    return *this;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
*
*   T(n) = n
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Scenario #1, the if block executes:
*       T(n) = 1 + 1 + 1
*            = 3
*
*   Scenario #2, the else block executes:
*       T(n) = 1 + 1 + (n - 1) + 1 + 1
*            = n + 3
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 1 + 2n + 1
*        = 2n + 2
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

/*******************************************************************************
*   Analyzing the number of links accessed.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list.
*
*   T(n) = n - 1
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
T LinkedList<T>::getElement(int position) const {
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list and length > 1.
*
*   T(n) = 3 + 1 + 3(n - 1) + 3
*        = 3n + 4
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        Node* n = new Node(elem);
        Node* curr = head;
        Node* prev = nullptr;

        for (int i = 0; i < position; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (prev != nullptr) {
            prev->next = n;
        }
        else if (position == 0) {
            head = n;
        }

        n->next = curr;
        this->length++;
    }
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list and length > 1.
*
*   T(n) = 2 + 1 + 3(n - 1) + 1 + 1
*        = 3n + 2
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* curr = head;
            Node* prev = nullptr;

            for (int i = 0; i < position; i++) {
                prev = curr;
                curr = curr->next;
            }

            if (curr == head) {
                head = head->next;
            }
            else {
                prev->next = curr->next;
            }

            delete curr;
        }

        this->length--;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list.
*
*   T(n) = 1 + 1 + 2(n - 1) + 1
*        = 2n + 1
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        Node* curr = head;

        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }

        curr->value = elem;
    }
}

#endif
