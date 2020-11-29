#ifndef PATRON_H
#define PATRON_H

#include "Book.h"
#include <string>
using namespace std;

class Patron {
	private:
		int age, numBooks;
		string* name;
		Book* currentBooks;

		void initialize(string, int, int);
		void cleanup();
	public:
		Patron(string = "", int = 0);
		Patron(const Patron&);
		~Patron();

		int getAge() const;
		int getNumBooks() const;
		string getName() const;
		void addBook(Book&); 
		void removeBook(Book&);

		Patron& operator=(const Patron&);
		Book& operator[](int) const;
		Book& operator[](string) const;
		friend ostream& operator<<(ostream&, const Patron&);
};

#endif