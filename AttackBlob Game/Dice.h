#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

class Dice {
private:
	int* diceNum;
  int* rollValue;

  void initialize(int n, int r);
  void cleanup();
public: 
  // constructors
	Dice(int);
  // destructor
  ~Dice();

	int roll(int);
}; // dice class

#endif