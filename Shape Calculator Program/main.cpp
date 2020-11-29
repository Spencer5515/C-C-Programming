#include "TwoDimens.h"
#include "ThreeDimens.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cube.h"
#include "Pyramid.h"
#include <iostream>
using namespace std;

int main() {
	int userInput;
	int userInput2;
	double userData, radius, length, width, height;
	int arrSize = 0;
	Shape** userArray = new Shape*[arrSize];
	
	cout << "--- Welcome to my Library ---\n";
	while (userInput != 4) {
		cout << "1. Add a new shape\n";
		cout << "2. Remove a shape\n";
		cout << "3. Print current shapes\n";
		cout << "4. Exit\n";

		cout << "Enter your choice: ";
		cin >> userInput;
		cin.ignore();

		if (userInput == 1) {
			arrSize++; // increments array size
			cout << "Pick what kind of shape you want to add:\n";
			cout << "1. Circle\n";
			cout << "2. Square\n";
			cout << "3. Triangle\n";
			cout << "4. Sphere\n";
			cout << "5. Cube\n";
			cout << "6. Pyramid\n";
			cout << "7. Go Back!\n";

			cout << "Enter your choice: ";
			cin >> userInput2;
			cin.ignore();

			Shape** tempUserArray = new Shape*[arrSize];
			for (int i = 0; i < arrSize; i++) {
				tempUserArray[i] = userArray[i];
			}

			delete[] userArray;
			userArray = tempUserArray;
			delete[] tempUserArray;

			if (userInput2 == 1) {
				cout << "Enter the radius: ";
				cin >> userData;
				cin.ignore();

				Shape* userCircle = new Circle(userData);
				userArray[arrSize - 1] = userCircle;
			} // if
			else if (userInput2 == 2) {
				cout << "Enter the side length: ";
				cin >> userData;
				cin.ignore();

				Shape* userSquare = new Square(userData);
				userArray[arrSize - 1] = userSquare;
			} // else if
			else if (userInput2 == 3) {
				cout << "Enter the length: ";
				cin >> length;
				cout << "Enter the width: ";
				cin >> width;
				cout << "Enter the height: ";
				cin >> height;
				cin.ignore();

				Shape* userTriangle = new Triangle(length, width, height);
				userArray[arrSize - 1] = userTriangle;
			} // else if
			else if (userInput2 == 4) {
				cout << "Enter the radius: ";
				cin >> userData;
				cin.ignore();

				Shape* userSphere = new Sphere(userData);
				userArray[arrSize - 1] = userSphere;
			} // else if
			else if (userInput2 == 5) {
				cout << "Enter the side length: ";
				cin >> userData;
				cin.ignore();

				Shape* userCube = new Cube(userData);
			} // else if
			else if (userInput2 == 6) {
				cout << "Enter the side length: ";
				cin >> userData;
				cin.ignore();

				Shape* userSphere = new Pyramid(userData);
				userArray[arrSize - 1] = userSphere;
			} // else if
			else if (userInput2 == 7) {
				break;
			} // else if
			else { break; } // else
		} // if
		else if (userInput == 2) {
			cout << "Enter the index number (or -1 to go back): ";
			cin >> userInput2;
			cin.ignore();
			if (userInput == -1) {
				break;
			} // if
			else if (userInput2 >= 0 && userInput2 < arrSize) {
				int tempSize = arrSize--;

				Shape** tempUserArrayDeletion = new Shape*[arrSize];
				for (int i = 0; i < tempSize; i++) {
					if (i >= userInput2) {
						tempUserArrayDeletion[i] = userArray[i + 1];
					} // else if
					else if (i < userInput2) {
						tempUserArrayDeletion[i] = userArray[i];
					} // else if
					else {} // else
				} // for loop

				delete[] userArray;
				userArray = tempUserArrayDeletion;
				delete[] tempUserArrayDeletion;

				arrSize--; // decrements array size
			} // else if
			else { break; } // else
		} // else if
		else if (userInput == 3) {
			cout << "*** BEGIN REPORT ***\n";

			TwoDimens* p;
			Circle* c;
			Square* s;
			Triangle* t;
			Sphere* sp;
			Cube* cu;
			Pyramid* py;
			for (int i = 0; i < arrSize; i++) {
				p = dynamic_cast<TwoDimens*>(userArray[i]);
				if (p != nullptr) { // if p != nullptr its a TwoDimens
					c = dynamic_cast<Circle*>(userArray[i]);
					s = dynamic_cast<Square*>(userArray[i]);
					t = dynamic_cast<Triangle*>(userArray[i]);
					if (c != nullptr) {
						cout << "Object # " << i + 1 << " (Circle)\n";
						cout << "\tNumber of faces: " << c->getNumSides() << endl;
						cout << "\tPerimeter: " << c->getPerimeter() << endl;
						cout << "\tArea: " << c->getArea() << endl;
					} // if
					else if (s != nullptr) {
						cout << "Object # " << i + 1 << " (Squre)\n";	
						cout << "\tNumber of faces: " << s->getNumSides() << endl;
						cout << "\tPerimeter: " << s->getPerimeter() << endl;
						cout << "\tArea: " << s->getArea() << endl;
					} // else if
					else if (t != nullptr) {
						cout << "Object # " << i + 1 << " (Triangle)\n";
						cout << "\tNumber of faces: " << t->getNumSides() << endl;
						cout << "\tPerimeter: " << t->getPerimeter() << endl;
						cout << "\tArea: " << t->getArea() << endl;
					} // else if
					else{} // else
				} // if
				else { // if p == nullptr its a ThreeDimens
					sp = dynamic_cast<Sphere*>(userArray[i]);
					cu = dynamic_cast<Cube*>(userArray[i]);
					py = dynamic_cast<Pyramid*>(userArray[i]);
					if (sp != nullptr) {
						cout << "Object # " << i + 1 << " (Sphere)\n";
						cout << "\tNumber of faces: " << sp->getNumSides() << endl;
						cout << "\tSurfaceArea: " << sp->getSurfaceArea() << endl;
						cout << "\tVolume: " << sp->getVolume() << endl;
					} // if
					else if (cu != nullptr) {
						cout << "Object # " << i + 1 << " (Cube)\n";	
						cout << "\tNumber of faces: " << cu->getNumSides() << endl;
						cout << "\tSurfaceArea: " << cu->getSurfaceArea() << endl;
						cout << "\tVolume: " << cu->getVolume() << endl;
					} // else if
					else if (py != nullptr) {
						cout << "Object # " << i + 1 << " (Pyramid)\n";
						cout << "\tNumber of faces: " << py->getNumSides() << endl;
						cout << "\tSurfaceArea: " << py->getSurfaceArea() << endl;
						cout << "\tVolume: " << py->getVolume() << endl;
					} // else if
					else{} // else
				} // else
			} // for loop for finding shapes
			cout << "*** END REPORT ***\n";
		} // else if
		else if (userInput == 4) {
			delete[] userArray;
			break;
		} // else if
		else {
			cout << "*Error* You input an invalid number" << endl;
		} // else
	} // while loop

	cout << "\nGood Bye User :)\n";
	return 0;
}