#include "Patron.h"
#include <string>
#include <iostream>
using namespace std;

Patron::Patron(string n, int a) : name(new string (n)), age(a) {
	name = nullptr;
	currentBooks = nullptr;

	initialize(n, a, 0);
} // constructor

Patron::Patron(const Patron& copyObj) {
	name = nullptr;	
	currentBooks = nullptr;

	initialize(copyObj.getName(), copyObj.getAge(), copyObj.getNumBooks());
} // Book copy constructor

Patron::~Patron() {
	cleanup();
} // Book destructor

void Patron::initialize(string n, int a, int num) {
	currentBooks = new Book[num];

	numBooks = num;
	age = a;
	name = new string(n);
} // initialize method

void Patron::cleanup() {
	if (name != nullptr && age != 0 && numBooks != 0) {
		delete name;
		name = nullptr;
		age = 0;
		numBooks = 0;
		delete[] currentBooks;	
	} // if
} // cleanup method

int Patron::getAge() const {
	if (age != 0) {
		return age;
	} // if
	else {
		return 0;
	} // else
} // getAge method

int Patron::getNumBooks() const {
	if (numBooks != 0) {
		return numBooks;
	} // if
	else {
		return 0;
	} // else
} // getNumBooks method

string Patron::getName() const {
	if (name != nullptr) {
		return *name;
	} // if
	else {
		return "";
	} // else
} // getName method

void Patron::addBook(Book& bk) {
	numBooks++;

	int newSize = numBooks;
	Book* temparr = new Book[newSize];
	for (int i = 0; i < newSize; i++) {
		temparr[i] = currentBooks[i];
	}

	temparr[newSize - 1] = bk;

	delete[] currentBooks;
	currentBooks = temparr;
	delete[] temparr;
} // addBook method

void Patron::removeBook(Book& bk) {
	numBooks--;

	int newSize = numBooks;
	Book* temparr = new Book[newSize];
	for (int i = 0; i < newSize; i++) {
		temparr[i] = currentBooks[i];
	}

	delete[] currentBooks;
	currentBooks = temparr;
	delete[] temparr;
} // removeBook method

Patron& Patron::operator=(const Patron& rightObj) {
	initialize(rightObj.getName(), rightObj.getAge(), rightObj.getNumBooks());

	return *this; 
} // operator change method (relational)

Book& Patron::operator[](int index) const {  
	return currentBooks[index];
} // operator change method (relational)

Book& Patron::operator[](string index) const {
	for (int i = 0; i < this->getNumBooks(); i++) {
		if(currentBooks[i].getTitle() == index) {
			return currentBooks[i]; 
		} // if
	} // linear search
} // operator change method (relational)

ostream& operator<<(ostream& outStream, const Patron& myObj) {
	outStream << "Name: " << myObj.getName() << endl;
	outStream << "Age: " << myObj.getAge() << endl;
	outStream << "Number of Books Checked Out: " << myObj.getNumBooks() << endl;

	return outStream;
} // operator change method (I/O operators <<)
