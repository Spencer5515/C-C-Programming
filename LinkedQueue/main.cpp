#include "LinkedQueue.hpp"
#include <iostream>
using namespace std;

int main() {
	LinkedQueue<int> Queue;
	cout << boolalpha; // tells C++ to print true/false

	cout << Queue.isEmpty() << endl;
	cout << Queue.getLength() << endl;

	Queue.enqueue(5);
	Queue.enqueue(35);
	Queue.enqueue(9);
	Queue.enqueue(24);

	cout << Queue.isEmpty() << endl;
	cout << Queue.getLength() << endl;

	cout << Queue.front() << endl;
	cout << Queue.back() << endl;

	Queue.dequeue();

	cout << Queue.front() << endl;
	cout << Queue.back() << endl;
	cout << Queue.isEmpty() << endl;
	cout << Queue.getLength() << endl;

	Queue.dequeue();
	Queue.dequeue();

	cout << Queue.front() << endl;
	cout << Queue.back() << endl;

	Queue.dequeue();
	Queue.dequeue(); // should throw error

	cout << "\nProgram Ending...\n";
	return 0;
}