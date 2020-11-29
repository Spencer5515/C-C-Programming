#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;

int main() {
	ArrayQueue<int> arr(10);
	cout << boolalpha; // tells C++ to print true/false

	cout << "Max Size: " << arr.getMaxSize() << endl;
	cout << "Length: " << arr.getLength() << endl;
	cout << arr.isEmpty() << endl;
	cout << arr.isFull() << endl;

	arr.enqueue(54);
	arr.enqueue(23);
	arr.enqueue(1);
	arr.enqueue(78);
	arr.enqueue(90);
	arr.enqueue(45);
	arr.enqueue(35);
	arr.enqueue(12);
	arr.enqueue(89);
	arr.enqueue(67);

	cout << endl;

	arr.enqueue(2); // should throw error
	arr.enqueue(4); // should throw error

	cout << endl;

	cout << "Max Size: " << arr.getMaxSize() << endl;
	cout << "Length: " << arr.getLength() << endl;
	cout << arr.isEmpty() << endl;
	cout << arr.isFull() << endl;

	arr.dequeue();
	arr.dequeue();
	arr.dequeue();

	cout << endl;

	cout << "Max Size: " << arr.getMaxSize() << endl;
	cout << "Length: " << arr.getLength() << endl;
	cout << arr.isEmpty() << endl;
	cout << arr.isFull() << endl;

	cout << "\nProgram Ending...\n";
	return 0;
}