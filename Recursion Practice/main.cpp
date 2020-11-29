#include <iostream>
#include <string>
using namespace std;
/*******************************************************************************
***** FUNCTION PROTOTYPES
*******************************************************************************/
int product(int, int);

int productRec(int, int);

template <typename T>
bool member(T, T[], const int);

template <typename T>
bool memberRec(T, T[], const int, int = 0);
/*******************************************************************************
***** STARTING POINT
*******************************************************************************/
int main() {
    // calculate the product of numbers between 3 and 7 (inclusive)
    cout << product(3, 7) << endl;
    // calculate it again but using recursion
    cout << productRec(3, 7) << endl;
    // create an array of floating-point numbers
    const int SIZE = 10;
    float vals[SIZE] = {
        2.5f, -1.05f, 3.84f, 0.f, 12.547f,
        -8.06f, 24.99f, 6.4f, 100.f, -32.7001f
    };
    // check if 24.99 is in the array
    if (member(24.99f, vals, SIZE)) {
        cout << "Found the target!\n";
    }
    else {
        cout << "Target not found.\n";
    }
    // check again but using recursion
    if (memberRec(24.99f, vals, SIZE)) {
        cout << "Found the target!\n";
    }
    else {
        cout << "Target not found.\n";
    }
    // create a character array
    char msg[] = "This is a message.";
    // check if q is in the array
    if (member('q', msg, 18)) {
        cout << "Found the target!\n";
    }    
	else {
        cout << "Target not found.\n";
    }
    // check again but using recursion
    if (memberRec('q', msg, 18)) {
        cout << "Found the target!\n";
    }
    else {
        cout << "Target not found.\n";
    }
    // terminate
    return 0;
}
/*******************************************************************************
***** FUNCTION DEFINITIONS
*******************************************************************************/
int product(int x, int y) {
	int product = 1;
	while (y >= x) {
		product *= y;
		y--;
	} // while loop
	return product;
} // product function

int productRec(int x, int y) {
	if (y == x) {
		return x;
	} // if
	else {
		int product = productRec(x, y - 1);
		return product * y;
	} // else
} // product recursion fucntion

template <typename T>
bool member(T target, T array[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
		if (array[i] == target) {
			return true;
		} // if
	} // for loop
	return false;
} // member function

// found from old AP CS code :)
template <typename T>
bool memberRec(T target, T array[], const int SIZE, int i) {
	if (array[i] == target) {
		return true;
	} // if
	else {
		bool found = memberRec(target, array, SIZE, i + 1);
		return found;
	} // else
	return false;
} // member recursion function