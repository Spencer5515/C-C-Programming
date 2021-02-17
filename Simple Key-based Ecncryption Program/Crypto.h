/*
Class: CPSC-362-09
Homework: 1
Name: Spencer DeMera
Due Date: 3/3/2021
*/

#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <iostream>
using namespace std;

class Crypto {
	public:
		// initialized / required variables
		char InputDataBuffer[129]; // you process 16 characters at a time
		char CryptoKey[9]; // Using a user inputted 8-bit key
		char CryptoMatrix[129];
		char ClearMatrix[129];
		short InputDataCount;

		// string variables
		string userString;
		string userKey;

		// methods
		void inputData();
		void Encrypt();
		void Decrypt();
		void DisplayCryptoMatrix();
		void DisplayClearMatrix();

}; // Encryption class

void Crypto::inputData() {
	cout << "Enter a string of your choice: ";
	getline(cin, userString);

	while (userString.length() > 129) { // check to see if userString is too long
		cerr << "\nERROR: Too many characters used in string. Try again.\n\n";
		cout << "Enter a string of your choice: ";
		getline(cin, userString);
	} // while
	InputDataCount = (short)userString.length();

	cout << "Enter your 8 character encryption key: ";
	getline(cin, userKey);

	while (userKey.length() != 8) { // check for proper key length
		cerr << "\nERROR: Key was was not 8 characters. Try again.\n\n";
		cout << "Enter your 8 character encryption key: ";
		getline(cin, userKey);
	} // while

	for (int i = 0; i < InputDataCount; i++) { // copies userString into InputDataBuffer
		InputDataBuffer[i] = userString[i];
	} // for loop
	for (int i = 0; i < 9; i++) { // copies userKey into CryptoKey
		CryptoKey[i] = userKey[i];
	} // for loop

	cout << endl;
} // inputData function

void Crypto::Encrypt() {
	cout << "Data is being encrypted...\n\n";
	int ctr = 0;

	for (int i = 0; i < InputDataCount + 1; i++) { 
		if (ctr == 8) { // check for 8 char prase chunk
			ctr = 0;
		} // if
		CryptoMatrix[i] = InputDataBuffer[i] ^ CryptoKey[ctr]; // XOR
		ctr++;
	} // for loop
} // encryption function

void Crypto::Decrypt() {
	cout << "Data is being decrypted...\n\n";
	int ctr = 0;

	for (int i = 0; i < InputDataCount + 1; i++) {
		if (ctr == 8) { // check for 8 char parse chunk
			ctr = 0;
		} // if
		ClearMatrix[i] = CryptoMatrix[i] ^ CryptoKey[ctr]; // XOR
		ctr++;
	} // for loop
} // decryption function

void Crypto::DisplayCryptoMatrix() {
	for (int i = 0; i < InputDataCount; i++) {
		cout << CryptoMatrix[i];
	} // for loop
	cout << endl << endl;
} // DisplayCryptoMatrix function

void Crypto::DisplayClearMatrix() {
	for (int i = 0; i < InputDataCount; i++) {
		cout << ClearMatrix[i];
	} // for loop
	cout << endl << endl;
} // DisplayClearMatrix function

#endif