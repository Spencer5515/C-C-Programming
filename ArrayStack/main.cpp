#include "ArrayStack.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	cout << boolalpha; // tells C++ to print true/false

	ArrayStack<int> stack;

	cout << stack.isEmpty() << endl; // empty check
	cout << stack.getMaxSize() << endl; // gets max size
	stack.pop(); // error

	try {
		cout << stack.top() << endl; // error
	} // try
	catch (int i) {
		// empty body
	} // catch

	for (int i = 0; i < stack.getMaxSize(); i++) {
		stack.push(rand() % (50 - 1 + 1) + 1);
	} // for loop
	stack.push(43); // error

	cout << stack.isEmpty() << endl; // empty check
	cout << stack.isFull() << endl; // checks to see if its full

	stack.pop(); // pops top off stack
	stack.pop(); // pops top off stack
	stack.pop(); // pops top off stack
	stack.pop(); // pops top off stack
	int elem1 = stack.top(); // gets top of stack
	stack.pop(); // pops top off stack
	cout << elem1 << endl;

	cout << stack.getLength() << endl; // gets current getLength
	cout << stack.isFull() << endl; // checks to see if its full

	cout << "\nProgram Ending...\n";
	return 0;
}