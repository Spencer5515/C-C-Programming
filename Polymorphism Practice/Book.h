#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
	private:
		string *isbn, *title, *author, *genre;

		void initialize(string, string, string, string);
		void cleanup();
	public:
		Book(string = "", string = "", string = "", string = "");
		Book(const Book&);
		~Book();

		string getISBN() const;
		string getTitle() const;
		string getAuthor() const;
		string getGenre() const;

		Book& operator=(const Book&);
		bool operator==(const Book&) const;
		bool operator!=(const Book&) const;
		friend ostream& operator<<(ostream&, const Book&);
};

#endif
