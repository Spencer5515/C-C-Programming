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

    private:
        // copy the values from the argument linked list to `this`
        void copy(const LinkedList<T>&);

        // recursive auxiliary functions
        void appendRec(Node*, Node*);
        void printRec(ostream&, Node*) const;
        void printReverseRec(Node* curr) const;

		void insertRec(Node*, Node*, Node*, int, int);
		void removeRec(int, Node*, Node*, int);
		T getElementRec(int, int, Node*) const;
		void replaceRec(int, int, Node*, const T&);

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

        // print the list in reverse using a recursive technique
        void printReverse() const;

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
        *   Asymptotic analysis:
        *       T(n) = O(n)
        ***********************************************************************/
        friend
        ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
            if (myObj.isEmpty()) {
                outStream << "List is empty, no elements to display.\n";
            }
            else {
                myObj.printRec(outStream, myObj.head);
				myObj.printReverse();
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
LinkedList<T>::LinkedList() {
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
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

/*******************************************************************************
*   Analyzing the number of delete operations.
*   Input size n is the length of the list.
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
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::append(const T& elem) {
    appendRec(new Node(elem), head);
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
void LinkedList<T>::appendRec(Node* n, Node* curr) {
    if (curr == nullptr) {
        head = n;
    }
    else if (curr->next == nullptr) {
        curr->next = n;
    }
    else {
        appendRec(n, curr->next);
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
void LinkedList<T>::clear() {
    if (head == nullptr) {
		return;
	} // if
	else {
		Node* prev = head;
		head = head->next;
		delete prev;

		clear();
	} // else 
	this->length = 0;
} // for sure works

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
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
*   Analyzing the number of links accessed.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/


// I honestly dont know why this assignment has been so difficult 
// for me but I cannot seem to get any of these to work properly


template <typename T>
T LinkedList<T>::getElement(int position) const {
	return getElementRec(position, 0, head);
	// Node* curr = head;

    // for (int i = 0; i < position; i++) {
    //     curr = curr->next;
    // }

    // return curr->value;
} // for sure works

//       T(n) = O(n)
template <typename T>
T LinkedList<T>::getElementRec(int position, int i, Node* curr) const {
	if (i == position) {
		return curr->value;
	} // if
	else {
		return getElementRec(position, i + 1, curr->next);
	} // else
} // for sure works

/*******************************************************************************
*   Analyzing the number of accesses to class attributes.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
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
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
		return;
    } // if
	else {
		insertRec(new Node(elem), head, nullptr, position, 0);
		this->length++;
	} // else
} // for sure works

//       T(n) = O(n)
template <typename T>
void LinkedList<T>::insertRec(Node* n, Node* curr, Node* prev, int position, int i) {
    if (position == 0) {
		n->next = head;
		head = n;
    } // if
	else if (i == position) {
		n->next = curr;
		prev->next = n;
	} // else if 
    else {
		insertRec(n, curr->next, prev, position, i + 1);
    } // else
} // for sure works

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::printRec(ostream& outStream, Node* curr) const {
    if (curr == nullptr) {
        outStream << endl;
    }
    else {
        outStream << curr->value;

        if (curr->next != nullptr) {
            outStream << " --> ";
        }

        printRec(outStream, curr->next);
    }
}

/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::printReverse() const {
    printReverseRec(head);
}

/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::printReverseRec(Node* curr) const {
    if (curr == nullptr) {
        return;
    }

    printReverseRec(curr->next);

    cout << curr->value;

    if (curr != head) {
        cout << " --> ";
    }
    else {
        cout << endl;
    }
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list and length > 1.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
		return;
    } // if
    else {
		removeRec(position, head, nullptr, 0);
		this->length--;
    } // else 
} // for sure works

//       T(n) = O(n)
template <typename T>
void LinkedList<T>::removeRec(int position, Node* curr, Node* prev, int i) {
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
	} // if
	else {
		if (i == position) {
			prev->next = curr->next;
			delete curr;
		} // if
		else if (i < position) {
			removeRec(position, curr->next, curr, i + 1);
		} // else if

		// if (curr == head) {
		// 	head = head->next;
		// } // if
		// else if (curr->next != nullptr) {
		// 	prev->next = curr->next;
		// } // else if
	} // else
} // for sure works

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume position is the last available one in the list.
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    } // if
    else {
		replaceRec(position + 1, 0, head, elem);
		// position + 1 cause it kept replacing the element at
		// what the user input for position - 1
    } // else
} // for sure works

//		T(n) = O(n)
template <typename T>
void LinkedList<T>::replaceRec(int position, int i, Node* curr, const T& elem) {
	if (i == position) {
		curr->value = elem;
	} // if
	else if (i < position) {
		replaceRec(position, i + 1, curr->next, elem);
	} // else
} // for sure works

#endif