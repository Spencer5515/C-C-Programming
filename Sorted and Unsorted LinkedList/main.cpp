#include "UnsortedList.hpp"
#include "SortedList.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // seed the random number generator
    srand(time(0));

    /***************************************************************************
    *   TESTING UNSORTED LIST
    ***************************************************************************/

    // create an unsorted list
    UnsortedList<int> ulist;

    // populate the unsorted list
    const int MAX_VAL = 25;
    for (int i = 0; i < 10; i++) {
        ulist.append(rand() % MAX_VAL);
    }

    // display the unsorted list
    cout << ulist << endl;

    // search for random values in the unsorted list
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        if (ulist.search(t)) {
            cout << "Search successful for " << t << endl;
        }
        else {
            cout << "Search could not find " << t << endl;
        }
    }

    // remove random elements in the unsorted list
    cout << endl;
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        ulist.removeElem(t);
        cout << "Attempting to remove " << t << endl;
    }

    // display the unsorted list after removals
    cout << endl << ulist << endl;

    /***************************************************************************
    *   TESTING SORTED LIST, ASCENDING MODE
    ***************************************************************************/

    // create a sorted list in ascending order
    SortedList<int> alist;

    // call the methods that are no longer allowed by sorted lists
    alist.append(5);        // should display error
    alist.insert(0, 2);     // should display error
    alist.replace(3, 1);    // should display error

    // populate the sorted list
    for (int i = 0; i < 10; i++) {
        alist.insert(rand() % MAX_VAL);
    }

    // display the sorted list
    cout << endl << alist << endl;

    // search for random values in the sorted list
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        if (alist.search(t)) {
            cout << "Search successful for " << t << endl;
        }
        else {
            cout << "Search could not find " << t << endl;
        }
    }

    // remove random elements in the sorted list
    cout << endl;
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        alist.removeElem(t);
        cout << "Attempting to remove " << t << endl;
    }

    // display the sorted list after removals
    cout << endl << alist << endl;

    /***************************************************************************
    *   TESTING SORTED LIST, DESCENDING MODE
    ***************************************************************************/

    // create a sorted list in descending order
    SortedList<int> dlist(SortedList<int>::DESCENDING);

    // populate the sorted list
    for (int i = 0; i < 10; i++) {
        dlist.insert(rand() % MAX_VAL);
    }

    // display the sorted list
    cout << dlist << endl;

    // search for random values in the sorted list
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        if (dlist.search(t)) {
            cout << "Search successful for " << t << endl;
        }
        else {
            cout << "Search could not find " << t << endl;
        }
    }

    // remove random elements in the sorted list
    cout << endl;
    for (int i = 0, t = 0; i < 10; i++) {
        t = rand() % MAX_VAL;
        dlist.removeElem(t);
        cout << "Attempting to remove " << t << endl;
    }

    // display the sorted list after removals
    cout << endl << dlist;

    // terminate
    return 0;
}
