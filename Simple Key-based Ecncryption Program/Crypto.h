#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <iostream>
using namespace std;

class Encryption {
	public:
		char InputDataBuffer[133]; // you process 16 characters at a time
		char CryptoKey[9]; // Using a user inputted 8-bit key
		char CryptoMatrix[133];
		char ClearMatrix[133];
		short InputDataCount;

		string userString;
		string userKey;

		void inputData();
		void Encrypt();
		void Decrypt();
		void DisplayCryptoMatrix();
		void DisplayClearMatrix();
		
}; // Encryption class


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
		for (int i  = 0; i < InputDataCount; i++) {
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
		for (int i  = 0; i < InputDataCount; i++) {
			cout << ClearMatrix[i];
		} // for loop
		cout << endl;
	} // else
	cout << endl;
} // DisplayClearMatrix function

#endif
