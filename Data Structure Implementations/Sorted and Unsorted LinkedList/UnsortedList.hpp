#ifndef UNSORTED_LIST_HPP
#define UNSORTED_LIST_HPP

#include "LinkedList.hpp"

template <typename T>
class UnsortedList : public LinkedList<T> {
    private:
        // simplify the type definition for the inherited Node type
        typedef typename LinkedList<T>::Node Node;

    public:
        // remove an element from the list that matches the argument
        void removeElem(const T&);

        // determine if the argument is in the list
        bool search(const T&) const;
};

/*******************************************************************************
*   Analyzing the number of assignment operations.
*   Input size n is the length of the list.
*
*   Assume the list is non-empty and that the last node contains the value.
*
*   T(n) = 1 + n - 1 + 2 + 2(n - 1) + 3n + 2
*        = 1 + n - 1 + 2 + 2n - 2 + 3n + 2
*        = 6n + 2
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
void UnsortedList<T>::removeElem(const T& elem) {
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
*   Analyzing the number of comparison operations.
*   Input size n is the length of the list.
*
*   Assume the list is non-empty and that the last node contains the value.
*
*   T(n) = 2n + 1
*
*   Asymptotic analysis:
*       T(n) = O(n)
*******************************************************************************/
template <typename T>
bool UnsortedList<T>::search(const T& elem) const {
    if (this->isEmpty()) {
        return false;
    }

    Node* curr = this->head;

    while (curr != nullptr) {
        if (curr->value == elem) {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

#endif
