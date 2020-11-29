#ifndef SPEEDBLOB_H
#define SPEEDBLOB_H

#include <iostream>
using namespace std;

class SpeedBlob {
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
  SpeedBlob();
	SpeedBlob(string);
  // destructors
  ~SpeedBlob();

	int getHP() const;
	int getAtStat() const;
	int getDefStat() const;
  int getSpeed() const;
  string getName() const;

	void decHP(int);
}; // AtkBlob class

#endif
