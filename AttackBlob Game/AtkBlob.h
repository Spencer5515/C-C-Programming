#ifndef ATKBLOB_H
#define ATKBLOB_H

#include <iostream>
using namespace std;

class Atkblob {
private:
	int* HP;
  int* atStat;
  int* defStat;
  int* speed;
	string* name;

  void initialize(int, int, int, int ,string);
  void cleanup();
public:
  // constructors
  Atkblob();
	Atkblob(string);
  // destructors
  ~Atkblob();

	int getHP() const;
	int getAtStat() const;
	int getDefStat() const;
  int getSpeed() const;
  string getName() const;

	void decHP(int);
}; // AtkBlob class

#endif
