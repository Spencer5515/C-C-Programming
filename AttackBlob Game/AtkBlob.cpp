#include "AtkBlob.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

Atkblob::Atkblob() {
  cout << "Initializing attribute data." << endl;
  initialize(0, 0, 0, 0, "");
} // default constructor

Atkblob::Atkblob(string n) {
  srand(time(0));
  int h = rand() % (17 - 13 + 1) + 13;
  int a = rand() % (8 - 5 + 1) + 5;
  int d = rand() % 2 + 1;
  int s = rand() % (4 - 2 + 1) + 2;

  cout << "Created an Atkblob object using the 1-parameter constructor." << endl;
	initialize(h, a, d, s, n);
  *name = n;
} // AtkBlob constructor

Atkblob::~Atkblob() {
  cout << endl << "The Atkblob object is being destroyed." << endl;
	cleanup();
} // Atkblob deconstructor

int Atkblob::getHP() const {
	return *HP;
} // getHp

int Atkblob::getAtStat() const {
	return *atStat;
} // getAtStat

int Atkblob::getDefStat() const {
	return *defStat;
} // getDefStat

int Atkblob::getSpeed() const {
  return *speed;
} // speed 

string Atkblob::getName() const {
	return *name;
} // getName

void Atkblob::decHP(int n) {
	*HP -= n;

	if (*HP <= 0) {
		*HP = 0;
	} // if
} // decHP method

void Atkblob::initialize(int h, int a, int d, int s, string n) {
  cout << "Allocating dynamic memory for all attributes." << endl;
  HP = new int(h);
  atStat = new int(a);
  defStat = new int(d);
  speed = new int(s);
  name = new string(n);
} // initialize method

void Atkblob::cleanup() {
  cout << "Releasing dynamic memory for all attributes." << endl;
  delete HP;
  delete atStat;
  delete defStat;
  delete speed;
  delete name;
} // cleanup method
