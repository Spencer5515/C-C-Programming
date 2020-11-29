#include "DoublyList.hpp"

int main() {
    // create a doubly linked list
    DoublyList<string> myList;

    myList.append("Heart");
    myList.insert(0, "Your");
    myList.insert(0, "May");
    myList.replace(-3, "?"); // should display error
    myList.append("Citrus");
    myList.insert(5, "kweh"); // should display error
    myList.remove(3);

    cout << myList;

    string word = myList.getElement(2);
    cout << "Element 2: " << word << endl;

    DoublyList<string> secondList = myList;
    secondList.append("Beat");
    secondList.replace(2, "Drums");

    cout << secondList;

    secondList.remove(4); // should display error

    DoublyList<string> thirdList;
    cout << thirdList;
    thirdList = myList;

    cout << "thirdList length: " << thirdList.getLength() << endl;

    thirdList.append("Be A");
    thirdList.append("Yellow");
    thirdList.append("Banana");

    cout << thirdList;

    myList.clear();

    if (myList.isEmpty()) {
        cout << "myList is empty!\n";
    }

    // terminate
    return 0;
}
