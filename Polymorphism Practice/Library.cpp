#include "Book.h"
#include "Patron.h"
#include "Library.h"
#include <cstddef>
#include <iostream>
using namespace std;

Library::Library() {
	numBooks = 0;
	numPatrons = 0;
	initialize(0, 0);
} // constructor

Library::~Library() {
	cleanup();
} // destructor

void Library::initialize(int b, int p) {
	currentPatrons = new Patron[p];
	availableBooks = new Book[b];
} // initializer method

void Library::cleanup() {
	delete[] currentPatrons;
	currentPatrons = nullptr;
	delete[] availableBooks;
	availableBooks = nullptr;
} // cleanup method

void Library::start() {
	int userInput = 0;

	cout << "Welcome to my Library" << endl;
	while (userInput != 6) {
		cout << "Here are your options:" << endl;
		cout << "\t1. ) Add a book" << endl;
		cout << "\t2. ) Add a patron" << endl;
		cout << "\t3. ) Check out a book" << endl;
		cout << "\t4. ) Check in a book" << endl;
		cout << "\t5. ) Print a report" << endl;
		cout << "\t6. ) Exit the program" << endl;
		cout << "Enter your choice: ";
		cin >> userInput;
		cin.ignore();

		if (userInput == 1) {
			addBook();
		} // if
		else if (userInput == 2) {
			addPatron();
		} // else if
		else if (userInput == 3) {
			int pIndex, bIndex;
			cout << "Please enter the patron index: ";
			cin >> pIndex;
			cout << "Please enter the book index: ";
			cin >> bIndex;
			cin.ignore();

			checkOut(pIndex, bIndex);
		} // else if
		else if (userInput == 4) {
			int pIndex, bIndex;
			cout << "Please enter the patron index: ";
			cin >> pIndex;
			cout << "Please enter the book index: ";
			cin >> bIndex;
			cin.ignore();

			checkIn(pIndex, bIndex);
		} // else if
		else if (userInput == 5) {
			cout << Library();
		} // else if
		else if (userInput == 6) {
			cout << "You have chosen to EXIT the program..." << endl;
			exit(0);
		} // else if
		else {
			cout << "*Error* You input an invalid number" << endl;
		} // else
	} // while loop
} // start method

void Library::addBook() { // adds book to library
	string i;
	string t;
	string a;
	string g;

	numBooks++;
	cout << "Enter ISBN: ";
	cin >> i;
	cout << "Enter Title: ";
	cin >> t;
	cout << "Enter Author: ";
	cin >> a;
	cout << "Enter Genre: ";
	cin >> g;
	cin.ignore();

	Book** newBookArr = new Book*[numBooks]; // creates temp book array
	for (int i = 0; i < numBooks; i++) {
		newBookArr[i] = &availableBooks[i]; // could this work? we may never know
	}
	newBookArr[numBooks - 1] = new Book(i, t, a, g);

	delete[] availableBooks;
	availableBooks = *newBookArr;
	delete[] newBookArr;
} // addBook method

void Library::addPatron() { // adds patron to library
	int a;
	string n;

	numPatrons++;
	cout << "Enter Age: ";
	cin >> a;
	cout << "Enter Name: ";
	cin >> n;
	cin.ignore();

	Patron** newPatronArr = new Patron*[numPatrons]; // creates temp patron array
	for (int i = 0; i < numPatrons; i++) {
		newPatronArr[i] = &currentPatrons[i]; // could this work? we may never know
	}
	newPatronArr[numPatrons] = new Patron(n, a);

	delete[] currentPatrons;
	currentPatrons = *newPatronArr;
} // addPatron method

void Library::checkOut(int pIndex, int bIndex) {
	if (pIndex < numPatrons && pIndex >= 0 && bIndex < numBooks && bIndex >= 0) {
		// I want the x person to have the y book in their patron object
		for (int i = 0; i < numBooks; i++) {
			if (i == pIndex) {
				currentPatrons[pIndex].addBook(availableBooks[bIndex]);
			} // if
		} // for loop
	} // if
} // checkOut method

void Library::checkIn(int pIndex, int bIndex) {
	if (pIndex < numPatrons && pIndex >= 0 && bIndex < numBooks && bIndex >= 0) {
		// I want the x person to not have the y book in their patron object
		for (int i = 0; i < numBooks; i++) {
			if (i == pIndex) {
				currentPatrons[pIndex].removeBook(availableBooks[bIndex]);
			} // if
		} // replacer for loop
	} // if
} // checkIn method

Book& Library::operator[](string index) {
	for (int i = 0; i < numBooks; i++) {
		if (availableBooks[i].getTitle() == index) {
			return availableBooks[i];
		} // if
	} // linear search
} // operator changer method 

Patron& Library::operator[](int index) {
	return currentPatrons[index];
} // operator changer method

ostream& operator<<(ostream& outStream, const Library& myObj) {
	cout << "******** START LIBRARY REPORT ********" << endl << endl;
	cout << "******** CURRENT BOOKS ********" << endl;
	for (int i = 0; i < myObj.numBooks; i++) {
		cout << myObj.availableBooks[i] << endl;
	}
	cout << "******** CURRENT BOOKS ********" << endl << endl;
	cout << "******** CURRENT PATRONS ********" << endl;
	for (int i = 0; i < myObj.numBooks; i++) {
		cout << myObj.currentPatrons[i] << endl;
	}	
	cout << "******** CURRENT PATRONS ********" << endl << endl;
	cout << "******** END LIBRARY REPORT ********" << endl;

	return outStream;
} // operator change method (I/O operators <<)
