#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"

class Library {
	private:
		int numBooks;
		int numPatrons;
		Book* availableBooks;
		Patron* currentPatrons;

		void initialize(int, int);
		void cleanup();
	public:
		Library();
		~Library();

		void start();
		void addBook();
		void addPatron();
		void removeBook();
		void checkOut(int, int);
		void checkIn(int, int);

		Book& operator[](string);
		Patron& operator[](int);
		friend ostream& operator<<(ostream&, const Library&);
};

#endif