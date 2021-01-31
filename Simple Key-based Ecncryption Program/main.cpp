#include "crypto.h"
#include <limits.h>
#include <iostream>
using namespace std;

int main() {
	Encryption e; // encryption object
	int userChoice = 0;
	int dataInputFlag = 0;
	bool canEncrypt = false;
	bool canDecrypt = false;
	
	cout << "\nThank You for logging in, you may select options below:\n\n";

	do {
		// main menu
		cout << "======= Main Menu =======\n";
		cout << "\t1. Input Data\n";
		cout << "\t2. Encrypt Data\n";
		cout << "\t3. Decrypt Data\n";
		cout << "\t4. Display Crypto Matrix\n";
		cout << "\t5. Display Clear Matrix\n";
		cout << "\t6. Quit Program\n\n";

		cout << "Enter your choice: "; // initial user choice system
		cin >> userChoice;
		cout << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores return char

		switch (userChoice) {
			case 1: // data input
				if (dataInputFlag > 0) {
					cerr << "ERROR: You have already input your data. Select another option below.\n\n";
				} // if
				else {
					e.inputData();
					canEncrypt = true;
					dataInputFlag++;
				} // else
				break;
			case 2: // data encryption
				if (!canEncrypt) {
					cerr << "ERROR: There is no data to encrypt. Select another option below.\n\n";
				} // if
				else {
					e.Encrypt();
					canDecrypt = true;
					canEncrypt = false;
				} // else 
				break;
			case 3:	// data decryption
				if (!canDecrypt) {
					cerr << "ERROR: There is no data to decrypt. Select another option below.\n\n";
				} // if
				else {
					e.Decrypt();
					canDecrypt = false;
					canEncrypt = true;
				} // else
				break;
			case 4: // display crypto matrix
				e.DisplayCryptoMatrix();
				break;
			case 5: // display clear matrix
				e.DisplayClearMatrix();
				break;
			case 6: // quit program
				cout << "You have chosen exit the program.\n\n";
				break;
		} // switch

		if (!(userChoice > 0 && userChoice < 7)) {
			cerr << "ERROR: Invalid Input. Please enter a number between 1 and 6.\n\n";
		} // if 

	} while (userChoice != 6);

	cout << "Program Terminating...\n\n";
	return 0;
} // main function
