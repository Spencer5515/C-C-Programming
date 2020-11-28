#include "Store.h"
#include "Garden.hpp"
#include "Lumber.hpp"
#include "Tools.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

void printTitle();
void printInfo();

template <typename T> bool storeSearch(T*, T);
template <typename T> void storeSort(T);

int main() {
	printTitle();
	printInfo();
	try {
		// variables
		Store* testObj;
		int userInput;
		int userInput2;
		string userInput3;
		int userIDinput;
		int productQuan;
		int quan;
		bool IDfound = false;
		int tempIndex = 0;
		int tempNum = 0;
		int tempNumber = 0;
		vector<Store*> userShoppingCart;

		// individually specified products
		Garden<float, string, int> Tulip(3.99, "D-5", "Tulip", 53101);
		Garden<float, string, int> Rose(4.59, "E-3", "Rose", 53102);
		Garden<float, string, int> Lily(17.49, "B-2", "Potted Lily Set", 53103);
		Lumber<float, string, int> twoxfour(12.98, "A-1", "2x4", 53111);
		Lumber<float, string, int> twoxsix(15.98, "C-6", "2x6", 53112);
		Lumber<float, string, int> plywood(23.99, "A-3", "Plywood Sheet", 53113);
		Tools<float, string, int> drill(98.99, "B-3", "Craftsman Drill", 53121);
		Tools<float, string, int> toolKit(179.99, "B-7", "Deqault Electric Drill Kit", 53122);
		Tools<float, string, int> skillSaw(129.99, "D-8", "Skill Saw (Deluxe) Package", 53123);

		// data arrays
		Garden<float, string, int> gardenArr[3] = {Tulip, Rose, Lily};
		Lumber<float, string, int> lumberArr[3] = {twoxfour, twoxsix, plywood};
		Tools<float, string, int> toolArr[3] = {drill, toolKit, skillSaw};
		Store::setTotalPrice(0.0f);

		// array of product IDs
		int productIDs[9] = {53101, 53102, 53103, 53111, 53112, 53113, 53121, 53122, 53123};

		// Body
		do {
			cout << endl;
//			printInfo();
			cout << "1. Add Product to Your Cart\n";
			cout << "2. Remove Product from your Cart\n";
			cout << "3. View Shopping Cart\n";
			cout << "4. Go-to Checkout\n";
			cout << "5. Exit\n\n";

			cout << "Enter your choice: ";
			cin >> userInput;
			cin.ignore();
			cout << endl;

			if (userInput == 1) {
				cout << "Which Product Category?: \n";
				cout << "1. Garden Center\n";
				cout << "2. Lumber Center\n";
				cout << "3. Tool Center\n\n";

				cout << "Enter your choice: ";
				cin >> userInput2;
				cin.ignore();
				cout << endl;
				
				if (userInput2 == 1) {
					cout << "Enter the product ID: ";
					cin >> userIDinput;
					cin.ignore();

					// checks if ID exists
					IDfound = storeSearch<int>(productIDs, userIDinput);
					try {
						if (IDfound == false) {
							string e = "*Error* Product ID not Found\n";
							throw e;
						} // if
					}
					catch (string e) {
						cerr << e;
						break;
					}

					cout << "Enter the desired Quantity: ";
					cin >> productQuan;
					cin.ignore();

					// adds new elements to the array 
					// how many are added depends on productQuan varibale
					for (int i = 0; i < 3; i++) {
						if (gardenArr[i].getProductID() == userIDinput) {
							for (int j = 0; j < productQuan; j++) {
								userShoppingCart.push_back(new Garden<float, string, int>(gardenArr[i]));
							} // nested for loop (adding item to array x times)
						} // if 
					} // for loop
				} // if
				else if (userInput2 == 2) {
					cout << "Enter the product ID: ";
					cin >> userIDinput;
					cin.ignore();

					// checks if ID exists
					IDfound = storeSearch<int>(productIDs, userIDinput);
					try {
						if (IDfound == false) {
							string e = "*Error* Product ID not Found\n";
							throw e;
						} // if
					}
					catch (const char* e) {
						cerr << e;
						break;
					}

					cout << "Enter the desired Quantity: ";
					cin >> productQuan;
					cin.ignore();

					// adds new elements to the array 
					// how many are added depends on productQuan varibale
					for (int i = 0; i < 3; i++) {
						if (lumberArr[i].getProductID() == userIDinput) {
							for (int j = 0; j < productQuan; j++) {
								userShoppingCart.push_back(new Lumber<float, string, int>(lumberArr[i]));
							} // nested for loop (adding item to array x times)
						} // if 
					} // for loop
				} // else if
				else if (userInput2 == 3) {
					cout << "Enter the product ID: ";
					cin >> userIDinput;
					cin.ignore();

					// checks if ID exists
					IDfound = storeSearch<int>(productIDs, userIDinput);
					try {
						if (IDfound == false) {
							string e = "*Error* Product ID not Found\n";
							throw e;
						} // if
					}
					catch (string e) {
						cerr << e;
						break;
					}

					cout << "Enter the desired Quantity: ";
					cin >> productQuan;
					cin.ignore();

					// adds new elements to the array 
					// how many are added depends on productQuan varibale
					for (int i = 0; i < 3; i++) {
						if (toolArr[i].getProductID() == userIDinput) {
							for (int j = 0; j < productQuan; j++) {
								userShoppingCart.push_back(new Tools<float, string, int>(toolArr[i]));
							} // nested for loop (adding item to array x times)
						} // if 
					} // for loop
				} // else if
			} // if
			// this else/if finds the first instance of the ID of the item the user wishes to delete
			// then it goes through a loop to delete the quantity of that item the user specified from the shopping cart
			else if (userInput == 2) { 
				cout << "Enter the product ID: ";
				cin >> userIDinput;
				cin.ignore();

				// checks if ID exists
				IDfound = storeSearch<int>(productIDs, userIDinput);
				try {
					if (IDfound == false) {
						string e = "*Error* Product ID not Found\n";
						throw e;
					} // if
				}
				catch (string e) {
					cerr << e;
					break;
				}

				cout << "Enter the desired Quantity: ";
				cin >> quan;
				cin.ignore();

				// finds out how many of the desired product actually exist
				for (int i = 0; i < userShoppingCart.size(); i++) {
					if (userShoppingCart[i]->getProdID() == userIDinput) {
						tempNumber++;
					} // if
				} // for loop

				// throws error message is the user tries to delete more instances items than exist in array
				try {
					if (quan > tempNumber) {
						string e = "*Error* Desired Deletion Qauntity is Greater Than Number of Said Item in Your Cart!\n";
						throw e;
					} // if
				}
				catch (string e) {
					cerr << e;
				}

				// erases the desired item(s) from the array 				
				for (int i = 0; i < userShoppingCart.size(); i++) {
					if (userShoppingCart[i]->getProdID() == userIDinput) {
						tempIndex = i; // sets the starting index for deletion
						tempNum = tempIndex + quan; // sets the last index for deletion
						userShoppingCart.erase(userShoppingCart.begin() + tempIndex, userShoppingCart.begin() + tempNum);
						// this deletes the data in the vetcor from the specified index to
						// that index + the (quantity - 1) that the user wishes to delete

						float tempMon = userShoppingCart[i]->getPrice() * quan;
						// finds the total price of all the items being deleted
						Store::setTotalPrice(Store::getTotalPrice() - tempMon);
						// sets the total price to be current total price - calculated deletion price
					} // if

					break;
				} // for loop
			} // else if
			else if (userInput == 3) {
				cout << "======================================\n";
				cout << "\t   Your Shopping Cart\t\n";
				cout << "======================================\n\n";

				cout << "--------------------------------------\n";
				// prints all of the data about the shopping cart

				// sorts shopping cart into ascedning order (based off of price)
				// before printing the reciept
				storeSort(userShoppingCart);

				// declaration of dynamic objects to use for searching in array
				Garden<float, string, int>* ga; 
				Lumber<float, string, int>* lu;
				Tools<float, string, int>* to;
				for (int i = 0; i < userShoppingCart.size(); i++) {
					// dynamic casts for assigning nullptr to object not located at [i]
					ga = dynamic_cast<Garden<float, string, int>*>(userShoppingCart[i]);
					lu = dynamic_cast<Lumber<float, string, int>*>(userShoppingCart[i]);
					to = dynamic_cast<Tools<float, string, int>*>(userShoppingCart[i]);

					if (ga != nullptr) {
						cout << endl;
						cout << *ga; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // if
					else if (lu != nullptr) {
						cout << endl;
						cout << *lu; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // else if
					else if (to != nullptr) {
						cout << endl;
						cout << *to; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // else if
				} // for loop
				cout << "--------------------------------------\n";
			} // else if	
			else if (userInput == 4) {
				cout << "======================================\n";
				cout << "\tYour Official Store Reciept\t\n";
				cout << "======================================\n\n";

				cout << "--------------------------------------\n";
				// prints all of the data about the shopping cart

				// sorts shopping cart into ascedning order (based off of price)
				// before printing the reciept
				storeSort(userShoppingCart);

				// declaration of dynamic objects to use for searching in array
				Garden<float, string, int>* ga; 
				Lumber<float, string, int>* lu;
				Tools<float, string, int>* to;
				for (int i = 0; i < userShoppingCart.size(); i++) {
					// dynamic casts for assigning nullptr to object not located at [i]
					ga = dynamic_cast<Garden<float, string, int>*>(userShoppingCart[i]);
					lu = dynamic_cast<Lumber<float, string, int>*>(userShoppingCart[i]);
					to = dynamic_cast<Tools<float, string, int>*>(userShoppingCart[i]);
					if (ga != nullptr) {
						cout << endl;
						cout << *ga; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // if
					else if (lu != nullptr) {
						cout << endl;
						cout << *lu; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // else if
					else if (to != nullptr) {
						cout << endl;
						cout << *to; // calls operator(<<) in parent of derived class
						cout << "-----\n";
					} // else if
				} // for loop

				if (Store::getTotalPrice() <= 0.0f) {
					Store::setTotalPrice(0.0f);
				} // if

				cout << "\n--------------------------------------\n";
				cout << "Your Total Price (Before Taxation): \n";
				cout << "\t $" << setprecision(3) << Store::getTotalPrice() << endl; // prints total price of the order
				cout << "-----\n";
				cout << "Your Total Price (After Taxation): \n";
				cout << "\t $" << setprecision(3) << Store::getTotalPrice() + Store::getTax() << endl; // adds tax amount to total price
				cout << "-----\n";
				cout << "--------------------------------------\n\n";

				cout << "You may now enter the wearhouse and collect your products!\n";
				cout << "Thank You For Shopping With Us! Have A Great Day!\n\n";
				cout << "*Exiting Program...*\n";
				cout << endl;
				break;
			} // else if
			else if (userInput == 5) { // simple exit message if you wish to exit
				cout << "You have chosen to exit the store...\n";
				cout << "*ALL USER DATA WILL BE LOST*\n";
				cout << "Are You Sure You Want to Exit? (input \"yes\" or \"no\"): ";

				cin >> userInput3;
				cin.ignore();
				cout << endl;

				if (userInput3 == "yes") {
					cout << "Goodbye!\n";
					cout << endl;
					break;
				} // if
				else if (userInput3 == "no") {
					cout << "*Going Back to Program*\n";
				} // else if
			} // else if
		} // body whille loop
		while (userInput <= 5);

		// deletes all objects in the users shopping cart
		for (int i = 0; i < userShoppingCart.size(); i++) {
			delete userShoppingCart[i];
		} // for loop

	} // try
	catch (bad_alloc e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    } // catch

	// terminate
  	return 0;
} // main function

void printTitle() {
	cout << "=============================================\n";
	cout << "\tWelcome to Spencer's Shopping\t\n";
	cout << "=============================================\n\n";
	cout << "------------------------------------------------------------------------------\n";
	cout << "You will first look at our list of product data presented below\n";
	cout << "to determine which products from what center you would like to purchase.\n";
	cout << "Once you have selected all your desired items, you may procede to checkout\n";
	cout << "where you will have your Product Info, Total Price, and Net Price printed onto\n";
	cout << "your reciept. Finally you may enter the wearhouse to retrieve your items.\n";
	cout << "------------------------------------------------------------------------------\n";
} // printTitle function

// function prints all essential user information
void printInfo() {
	cout << "------------------------------------------------------------------------------\n";
	cout << "Our Product List (Name (ID#), Price):\n";
	cout << "\tGarden Center: \n";
	cout << "\t\t" << "Tulip (53101)" << setw(35) << "$3.99" << endl;
	cout << "\t\t" << "Rose (53102)" << setw(36) << "$4.59" << endl;
	cout << "\t\t" << "Potted Lily Set (053103)" << setw(25) << "$17.49" << endl << endl;
	cout << "\tLumber Center: \n";
	cout << "\t\t" << "2x4 (53111)" << setw(38) << "$12.98" << endl;
	cout << "\t\t" << "4x6 (53112)" << setw(38) << "$15.98" << endl;
	cout << "\t\t" << "Plywood Sheet (53113)" << setw(28) << "$23.99" << endl << endl;
	cout << "\tTool Center: \n";
	cout << "\t\t" << "Craftsman Drill (53121)" << setw(26) << "$98.99" << endl;
	cout << "\t\t" << "Dewault Electric Tool Kit (53122)" << setw(17) << "$179.99" << endl;
	cout << "\t\t" << "Skill Saw (Deluxe) Package (53123)" << setw(16) << "$129.99" << endl;
	cout << "------------------------------------------------------------------------------\n";
} // printInfo function

// function template
// allows searching on float or string arrays
template <typename T> bool 
storeSearch(T* arr, T target) {
	T* ptr = arr;

	for (int i = 0; i < 9; i++) {
		if (*(ptr + i) == target) {
			return true;
		} // if
	} // for 

	return false;
} // store search algorithm

// function template
// allows sorting on float and string arrays
// **Ascending order**
template <typename T> void 
storeSort(T testVec) {
	int size = testVec.size();

	// algorithm I found from my Java code
	for (int i = 0; i < size - 1; i++) {
		// finds index of smallest remaining value
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (testVec[j]->getPrice() < testVec[min]->getPrice()) {
				min = j;
			} // if
		} // for loop
		// switches index of testVec[i] & testVec[min]
		Store* temp = testVec[min];
		testVec[min] = testVec[i];
		testVec[i] = temp;
	} // for loop
} // store sort algorithm
