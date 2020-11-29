#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include "LinkedList.hpp"

template <typename T>
class SortedList : public LinkedList<T> {
    public:
        // enumerate the two possible modes
        enum Order {
            ASCENDING, DESCENDING
        };

        // default constructor
        SortedList(Order = ASCENDING);

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // insert the given element at the proper position to remain sorted
        void insert(const T&);

        // remove an element from the list that matches the argument
        void removeElem(const T&);

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // determine if the argument is in the list
        bool search(const T&) const;

    private:
        // represents what order mode is being used
        Order listOrder;

        // simplify the type definition for the inherited Node type
        typedef typename LinkedList<T>::Node Node;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
SortedList<T>::SortedList(Order o)
: listOrder(o) { }


/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void SortedList<T>::append(const T& elem) {
    cout << "This method is not available for a sorted list.\n";
}

/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void SortedList<T>::insert(int position, const T& elem) {
    cout << "This method is not available for a sorted list.\n";
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume the list has length > 1 and the element will be placed at the end.
*
*   T(n) = 3 + 2n + 3
*        = 2n + 6
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void SortedList<T>::insert(const T& elem) {
    Node* n = new Node(elem);
    Node* curr = this->head;
    Node* prev = nullptr;

    if (listOrder == ASCENDING) {
        while (curr != nullptr && curr->value < elem) {
            prev = curr;
            curr = curr->next;
        }
    }
    else if (listOrder == DESCENDING) {
        while (curr != nullptr && curr->value > elem) {
            prev = curr;
            curr = curr->next;
        }
    }

    if (prev != nullptr) {
        prev->next = n;
    }
    else {
        this->head = n;
    }

    n->next = curr;

    this->length++;
}

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume the list is non-empty and the last node contains the value.
*
*   T(n) = 1 + n - 1 + 2 + 2(n - 1) + 3n + 2
*        = 1 + n - 1 + 2 + 2n - 2 + 3n + 2
*        = 6n + 2
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void SortedList<T>::removeElem(const T& elem) {
    if (this->isEmpty() || !search(elem)) {
        return;
    }

    Node* curr = this->head;
    int i = 0;

    while (curr != nullptr) {
        if (curr->value == elem) {
            this->remove(i);
            break;
        }

        curr = curr->next;
        i++;
    }
}

/*******************************************************************************
*   Analyzing the number of output operations.
*   Input size n is the length of the list.
*
*   T(n) = 1
*
*   Asymptotic analysis:
*       T(n) = O(1)
*******************************************************************************/
template <typename T>
void SortedList<T>::replace(int position, const T& elem) {
    cout << "This method is not available for a sorted list.\n";
}

/*******************************************************************************
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   Assume the list is non-empty, descending mode, and the last node contains
*   the value.
*
*   T(n) = 5n + 1
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
bool SortedList<T>::search(const T& elem) const {
    if (this->isEmpty()) {
        return false;
    }

    Node* curr = this->head;

    while (curr != nullptr) {
        if (curr->value == elem) {
            return true;
        }
        else if (listOrder == ASCENDING && curr->value > elem) {
            return false;
        }
        else if (listOrder == DESCENDING && curr->value < elem) {
            return false;
        }

        curr = curr->next;
    }

    return false;
}

#endif
