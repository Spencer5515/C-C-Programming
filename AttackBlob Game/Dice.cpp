#include "Dice.h"
#include <iostream>
using namespace std;

Dice::Dice(int n) {
  srand(time(0));
  cout << "Created an Dice object using the 1-parameter constructor." << endl;
	initialize(1, 0);
  *diceNum = n;
} // dice constructor

Dice::~Dice() {
  cout << endl << "The Dice object has been destroyed." << endl;
  cleanup();
} // dice destructor

int Dice::roll(int n) {
	*rollValue = 0;

	for (int i = 0; i < *diceNum; i++) {
		*rollValue += rand() % 6 + 1;
	} // for loop

  return *rollValue;
} // roll method

void Dice::initialize(int n, int r) {
  cout << "Allocating dynamic memory for all attributes." << endl;
  diceNum = new int(n);
  rollValue = new int(r);
} // initialize method

void Dice::cleanup() {
  cout << "Releasing dynamic memory for all attributes." << endl;
  delete diceNum;
  delete rollValue;
} // cleanup method

// srand(time(0));