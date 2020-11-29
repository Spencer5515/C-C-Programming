#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string i, string t, string a, string g) {
	isbn = nullptr;	
	title = nullptr;
	author = nullptr;
	genre = nullptr;

	initialize(i, t, a, g);
} // Book constructor

Book::Book(const Book& copyObj) {
	isbn = nullptr;	
	title = nullptr;
	author = nullptr;
	genre = nullptr;

	initialize(copyObj.getISBN(), copyObj.getTitle(), copyObj.getAuthor(), copyObj.getGenre());
} // Book copy constructor

Book::~Book() {
	cleanup();
} // Book destructor

void Book::initialize(string i, string t, string a, string g) {
	if (isbn == nullptr || title == nullptr || author == nullptr || genre == nullptr) { 
		isbn = new string(i);
		title = new string(t);
		author = new string(a);
		genre = new string(g);
	} // if
	else {
		*isbn = i;
		*title = t;
		*author = a;
		*genre = g;
	} // else
} // initialize method

void Book::cleanup() {
	if (isbn != nullptr && title != nullptr && author != nullptr && genre != nullptr) {
		delete isbn;
		isbn = nullptr;
		delete title;
		title = nullptr;
		delete author;
		author = nullptr;
		delete genre;
		genre = nullptr;	
	} // if
} // cleanup method

string Book::getISBN() const {
	if (isbn != nullptr) {
		return *isbn;
	} // if
	else {
		return " ";
	} // else
} // getISBN method

string Book::getTitle() const {
	if (title != nullptr) {
		return *title;
	} // if
	else {
		return " ";
	} // else
} // getTitle method

string Book::getAuthor() const {
	if (author != nullptr) {
		return *author;
	} // if
	else {
		return " ";
	} // else
} // getAuthor method

string Book::getGenre() const {
	if (genre != nullptr) {
		return *genre;
	} // if
	else {
		return " ";
	} // else
} // getGenre method

Book& Book::operator=(const Book& rightObj) {
	initialize(rightObj.getISBN(), rightObj.getTitle(), rightObj.getAuthor(), rightObj.getGenre());

	return *this; 
} // operator change method (relational)

bool Book::operator==(const Book& rightObj) const {  
	return (this->getISBN() == rightObj.getISBN() && this->getTitle() == rightObj.getTitle() && this->getAuthor() == rightObj.getAuthor() && this->getGenre() == rightObj.getGenre()); 
} // operator change method (relational)

bool Book::operator!=(const Book& rightObj) const {  
	return (this->getISBN() != rightObj.getISBN() && this->getTitle() != rightObj.getTitle() && this->getAuthor() != rightObj.getAuthor() && this->getGenre() != rightObj.getGenre());
} // operator change method (relational)

ostream& operator<<(ostream& outStream, const Book& myObj) {
	outStream << "ISBN: " << myObj.getISBN() << endl;
	outStream << "Title: " << myObj.getTitle() << endl;
	outStream << "Author: " << myObj.getAuthor() << endl;
	outStream << "Genre: " << myObj.getGenre() << endl;

	return outStream;
} // operator change method (I/O operators <<)
