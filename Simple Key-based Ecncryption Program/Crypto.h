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

#endif