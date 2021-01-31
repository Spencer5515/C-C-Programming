/*
Class: CPSC-362-09
Homework: 1
Name: Spencer DeMera
Due Date: 3/3/2021
*/

#include "crypto.h"
#include <limits.h>
#include <iostream>
using namespace std;

void Encryption::inputData() {
	cout << "Enter a string of your choice: ";
	getline(cin, userString);

	while (userString.length() > 133) {
		cerr << "\nERROR: Too many characters used in string. Try again.\n\n";
		cout << "Enter a string of your choice: ";
		getline(cin, userString);
	} // while
	InputDataCount = userString.length();

	cout << "Enter your 8 character encryption key: ";
	getline(cin, userKey);

	while (userKey.length() != 8) {
		cerr << "\nERROR: Key was was not 8 characters. Try again.\n\n";
		cout << "Enter your 8 character encryption key: ";
		getline(cin, userKey);
	} // while

	for (int i = 0; i < InputDataCount; i++) {
		InputDataBuffer[i] = userString[i];
	} // for loop
	for (int i = 0; i < 9; i++) {
		CryptoKey[i] = userKey[i];
	} // for loop

	cout << endl;
} // inputData function

void Encryption::Encrypt() {
	cout << "Data is being encrypted...\n\n";
	int ctr = 0;

	for (int i = 0; i < InputDataCount + 1; i++) {
		if (ctr == 8) {
			ctr = 0;
		} // if
		CryptoMatrix[i] = InputDataBuffer[i] ^ CryptoKey[ctr];
		ctr++;
	} // for loop
} // encryption function

void Encryption::Decrypt() {
	cout << "Data is being decrypted...\n\n";
	int ctr = 0;

	for (int i = 0; i < InputDataCount + 1; i++) {
		if (ctr == 8) {
			ctr = 0;
		} // if
		ClearMatrix[i] = CryptoMatrix[i] ^ CryptoKey[ctr];
		ctr++;
	} // for loop
} // decryption function

void Encryption::DisplayCryptoMatrix() {
	if (CryptoMatrix[0] == '\0') {
		cerr << "ERROR: No encryption has occured yet (array is empty).\n\t Select another option below.\n";
	} // if
	else {
		for (int i = 0; i < InputDataCount; i++) {
			cout << CryptoMatrix[i];
		} // for loop
		cout << endl;
	} // else
	cout << endl;
} // DisplayCryptoMatrix function

void Encryption::DisplayClearMatrix() {
	if (ClearMatrix[0] == '\0') {
		cerr << "ERROR: No decryption has occured yet (array is empty).\n\t Select another option below.\n";
	} // if
	else {
		for (int i = 0; i < InputDataCount; i++) {
			cout << ClearMatrix[i];
		} // for loop
		cout << endl;
	} // else
	cout << endl;
} // DisplayClearMatrix function

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