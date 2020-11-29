#include "DefBlob.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

DefBlob::DefBlob() {
  cout << "Initializing attribute data." << endl;
  initialize(0, 0, 0, 0, "");
} // deafult constructor

DefBlob::DefBlob(string n) {
  srand(time(0));
  int h = rand() % (32 - 26 + 1) + 26;
  int a = rand() % 3 + 1;
  int d = rand() % (7 - 4 + 1) + 4;
  int s = rand() % 3 + 1;

  cout << "Created an DefBlob object using the 1-parameter constructor." << endl;
	initialize(h, a, d, s, n);
  *name = n;
} // AtkBlob constructor

DefBlob::~DefBlob() {
  cout << endl << "The DefBlob object is being destroyed." << endl;
	cleanup();
} // Atkblob deconstructor

int DefBlob::getHP() const {
	return *HP;
} // getHp

int DefBlob::getAtStat() const {
	return *atStat;
} // getAtStat

int DefBlob::getDefStat() const {
	return *defStat;
} // getDefStat

int DefBlob::getSpeed() const {
  return *speed;
} // speed 

string DefBlob::getName() const {
	return *name;
} // getName

void DefBlob::decHP(int n) {
	*HP -= n;

	if (*HP <= 0) {
		*HP = 0;
	} // if
} // decHP method

void DefBlob::initialize(int h, int a, int d, int s, string n) {
  cout << "Allocating dynamic memory for all attributes." << endl;
  HP = new int(h);
  atStat = new int(a);
  defStat = new int(d);
  speed = new int(s);
  name = new string(n);
} // initialize method

void DefBlob::cleanup() {
  cout << "Releasing dynamic memory for all attributes." << endl;
  delete HP;
  delete atStat;
  delete defStat;
  delete speed;
  delete name;
} // cleanup method