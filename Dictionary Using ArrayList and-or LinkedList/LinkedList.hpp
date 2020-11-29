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

        // merge sort algorithm
        void mergeSort(Node*&);

		Node* mergeLists(Node*&, Node*&);

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

        // print the elements in the list starting at the given Node (argument)
        void print(Node*) const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // sort the elements in the list using the algorithm (argument)
        //      4 --> merge sort
        virtual void sort(int) override;
};

// I formally secede defeat C++ has won
template <typename T>
void LinkedList<T>::mergeSort(Node*& curr) {
	Node* n = curr;
	Node* a = nullptr;
	Node* b = nullptr;

	if (n == nullptr || n->next == nullptr) {
		return;
	} // if

// splits linked list
	Node* an = n->next;
	Node* bn = n;

    while (an != nullptr) {
        an = an->next;
        if (an != nullptr) {
            bn = bn->next;
            an = an->next;
        } // if
    } // while

    a = n;
    b = bn->next;
    bn->next = nullptr;

// recursive calls for sorting
	mergeSort(an);
	mergeSort(bn);

// merging lists
	curr = mergeLists(a, b);

// Method 4 (different version of method 3 [still doesn't work])
	// if (a == nullptr) {
	// 	curr = b;
    // } // if
	// if (b == nullptr) {
	// 	curr = a;
    // } // if

	// Node* result;
	// if (an->value < bn->value) {
	// 	result = an;
	// } // if
	// else {
	// 	result = bn;
	// 	bn = an;
	// 	an = result;
	// } // else

	// while (an->next != nullptr) {
	// 	if (an->next->value > bn->value) {
	// 		Node* temp = an->next;
	// 		an->next = bn;
	// 		bn = temp;
	// 	} // if
	// 	an = an->next;
	// }
	// an->next = bn;

	// curr = result;

// Method 3 (further upgrade of method 1 [still doesn't work])
	// Node* ab = nullptr;
	// Node* result = ab;

	// while (an != nullptr && bn != nullptr) {
	// 	if (an->value <= bn->value) {
	// 		result->next = an;
	// 		an = an->next;
	// 	} // if
	// 	else {
	// 		result->next = bn;
	// 		bn = bn->next;
	// 	} // else
	// 	result = result->next;
	// } // while

	// if (an == nullptr) {
	// 	result->next = bn;
	// } // if
	// if (bn == nullptr) {
	// 	result->next = an;
	// } // if

	// curr = ab;

// Method 2 (upgrade of method 1)
	// Node* result = nullptr;

    // while (a != nullptr && b != nullptr) {
    //     if (a->value <= b->value) {
    //         result = an;
    //         an = an->next;
    //     } // if
    //     else {
    //         result = b;
    //         bn = bn->next;
    //     } // else
    // } // while

	// if (a == nullptr) {
	// 	curr = b;
    // } // if
	// else if (b == nullptr) {
	// 	curr = a;
    // } // else if

    // curr = result;

// Method 1 (only one that attempts to print)
	// Node* result = nullptr;

    // while (a != nullptr && b != nullptr) {
    //     if (a->value <= b->value) {
    //         result = a;
    //         a = a->next;
    //     } // if
    //     else {
    //         result = b;
    //         b = b->next;
    //     } // else
    // } // while

	// if (a == nullptr) {
	// 	curr = b;
    // } // if
	// else if (b == nullptr) {
	// 	curr = a;
    // } // else if

    // curr = result;
} 

// attempted recursive method
// IT PRINTS EVERYTHING... but it just restitches them back together 
// as they were and doesnt really sort much so im just not gonna bother it
// (behaves very weirdly when you insert or remove too its all kinds of wack)
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::mergeLists(Node*& A, Node*& B) {
	if (A == nullptr) {
		return B;
	} // if
	if (B == nullptr) {
		return A;
	} // if

	if (A->value < B->value) {
		A->next = mergeLists(A->next, B);
		return A;
	} // if
	else {
		B->next = mergeLists(B->next, A);
		return B;
	} // else
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->length = 0;
    head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

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

template <typename T>
T LinkedList<T>::getElement(int position) const {
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

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

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::print(Node* curr) const {
    if (curr == nullptr) {
        cout << "List is empty, no elements to display.\n";
    }
    else {
        while (curr != nullptr) {
            cout << curr->value;

            if (curr->next != nullptr) {
                cout << " --> ";
            }

            curr = curr->next;
        }

        cout << endl;
    }
}

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

template <typename T>
void LinkedList<T>::sort(int algo) {
    if (algo == 4) {
        mergeSort(head);
    }
    else {
        cout << "That algorithm hasn't been implemented :(\n";
    }
}

#endif
