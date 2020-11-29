#ifndef DEFBLOB_H
#define DEFBLOB_H

#include <iostream>
using namespace std;

class DefBlob {
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
  DefBlob();
	DefBlob(string);
  // destructors
  ~DefBlob();

	int getHP() const;
	int getAtStat() const;
	int getDefStat() const;
  int getSpeed() const;
  string getName() const;

	void decHP(int);
}; // DefBlob class

#endif