#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main() {
  LinkedList<string> myList;

	// cout << "test\n";
// appends
    myList.append("Heart");
	myList.append("Citrus");
	myList.append("Apple");

	// cout << "test\n";
// inserts
   myList.insert(0, "Your"); // gets overwritten
   myList.insert(0, "May");

	// cout << "test\n";
// replaces
    myList.replace(5, "Lemon"); // should display error
	myList.replace(2, "Lemon");
	cout << myList << endl;

	// cout << "test\n";
// removes
	cout << "Removes:\n";
    myList.remove(2); // should remove "Heart"
	myList.remove(3); // should remove "Apple": that is now at position 3
    cout << myList << endl;

	// cout << "test\n";
// getElements
	// this gets the item from the list
    string word = myList.getElement(2);
    cout << "Element 2: " << word << endl;

    LinkedList<string> secondList = myList;

	// cout << "test\n";
// appends
    secondList.append("Beat");
    cout << secondList << endl;

	// cout << "test\n";
// removes
    secondList.remove(4); // should display error

    LinkedList<string> thirdList;
    cout << thirdList << endl;
    thirdList = myList;

    cout << "thirdList length: " << thirdList.getLength() << endl;

	// cout << "test\n";
// appends
    thirdList.append("Be A");
    thirdList.append("Yellow");
    thirdList.append("Banana");

    cout << thirdList << endl;

	// cout << "test\n";
// clears
    myList.clear();
	cout << "myList data: " << myList << endl;

	// cout << "test\n";
// empty?
    if (myList.isEmpty()) {
        cout << "myList is empty!\n";
    }

	cout << endl << "Program Ending...\n";
    return 0;
}