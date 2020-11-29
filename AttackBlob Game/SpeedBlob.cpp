#include "SpeedBlob.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

SpeedBlob::SpeedBlob() {
  cout << "Initializing attribute data." << endl;
  initialize(0, 0, 0, 0, "");
} // deafult constructor

SpeedBlob::SpeedBlob(string n) {
  srand(time(0));
  int h = rand() % (25 - 20 + 1) + 20;
  int a = rand() % (5 - 2 + 1) + 2;
  int d = rand() % (5 - 3 + 1) + 3;
  int s = rand() % (5 - 3 + 1) + 3;

  cout << "Created an SpeedBlob object using the 1-parameter constructor." << endl;
	initialize(h, a, d, s, n);
  *name = n;
} // AtkBlob constructor

SpeedBlob::~SpeedBlob() {
  cout << endl << "The SpeedBlob object is being destroyed." << endl;
	cleanup();
} // Atkblob deconstructor

int SpeedBlob::getHP() const {
	return *HP;
} // getHp

int SpeedBlob::getAtStat() const {
	return *atStat;
} // getAtStat

int SpeedBlob::getDefStat() const {
	return *defStat;
} // getDefStat

int SpeedBlob::getSpeed() const {
  return *speed;
} // speed 

string SpeedBlob::getName() const {
	return *name;
} // getName

void SpeedBlob::decHP(int n) {
	*HP -= n;

	if (*HP <= 0) {
		*HP = 0;
	} // if
} // decHP method

void SpeedBlob::initialize(int h, int a, int d, int s, string n) {
  cout << "Allocating dynamic memory for all attributes." << endl;
  HP = new int(h);
  atStat = new int(a);
  defStat = new int(d);
  speed = new int(s);
  name = new string(n);
} // initialize method

void SpeedBlob::cleanup() {
  cout << "Releasing dynamic memory for all attributes." << endl;
  delete HP;
  delete atStat;
  delete defStat;
  delete speed;
  delete name;
} // cleanup method
