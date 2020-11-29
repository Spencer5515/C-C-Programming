#include "Dice.h"
#include "AtkBlob.h"
#include "DefBlob.h"
#include "SpeedBlob.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <cctype>
#include <iostream>
using namespace std;

int main() {
	Dice* die;
	string name1 = "";
	string name2 = "";
	string name3 = "";
	string name4 = "";
	string name5 = "";
	string name6 = "";

	int teamType1;
	int teamType2;
	int dicenum = 0;
	bool team1First = false;
	int attack = 0;
	const int ARRAY_SIZE = 3;

	cout << "Welcome to Blob Attack!!" << endl << endl;

	while (name1.length() == 0 && name2.length() == 0 && dicenum <= 0) {
		cout << "Please pick two teams to battle!" << endl;
		cout << "Which two teams? Attack Blobs = 1, Defense Blobs = 2, or Speed Blobs = 3: ";
		cin >> teamType1 >> teamType2;
    cin.ignore();
		// getline(cin, teamType1);
		// getline(cin, teamType2);
		cout << "Please enter the name of Blob 1: ";
		getline(cin, name1);
		cout << "Please enter the name of Blob 2: ";
		getline(cin, name2);
		cout << "Please enter the name of Blob 3: ";
		getline(cin, name3);
		cout << "Please enter the name of Blob 4: ";
		getline(cin, name4);
		cout << "Please enter the name of Blob 5: ";
		getline(cin, name5);
		cout << "Please enter the name of Blob 6: ";
		getline(cin, name6);
		cout << "Please enter how many dice to use: ";
		cin >> dicenum;
	} // while loop

	cout << endl << "And were off!" << endl;

	die = new Dice(dicenum);

	int temp = rand() % 6 + 1;
	if (temp % 2 == 0) {
		team1First = true;
	} // if
	else if (temp % 2 == 1) {
		team1First = false;
	} // else if
	else {} // else

	int ctr = 0; // counter starting at 0 to determine going every other turn

	if (teamType1 == 1 && teamType2 == 1) {
		Atkblob* team1[ARRAY_SIZE] = { new Atkblob(name1), new Atkblob(name2), new Atkblob(name3) };
		Atkblob* team2[ARRAY_SIZE] = { new Atkblob(name4), new Atkblob(name5), new Atkblob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // if
	else if (teamType1 == 1 && teamType2 == 2) {
		Atkblob* team1[ARRAY_SIZE] = { new Atkblob(name1), new Atkblob(name2), new Atkblob(name3) };
		DefBlob* team2[ARRAY_SIZE] = { new DefBlob(name4), new DefBlob(name5), new DefBlob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 1 && teamType2 == 3) {
		Atkblob* team1[ARRAY_SIZE] = { new Atkblob(name1), new Atkblob(name2), new Atkblob(name3) };
		SpeedBlob* team2[ARRAY_SIZE] = { new SpeedBlob(name4), new SpeedBlob(name5), new SpeedBlob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 2 && teamType2 == 1) {
		DefBlob* team1[ARRAY_SIZE] = { new DefBlob(name1), new DefBlob(name2), new DefBlob(name3) };
		Atkblob* team2[ARRAY_SIZE] = { new Atkblob(name4), new Atkblob(name5), new Atkblob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 2 && teamType2 == 2) {
		DefBlob* team1[ARRAY_SIZE] = { new DefBlob(name1), new DefBlob(name2), new DefBlob(name3) };
		DefBlob* team2[ARRAY_SIZE] = { new DefBlob(name4), new DefBlob(name5), new DefBlob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 2 && teamType2 == 3) {
		DefBlob* team1[ARRAY_SIZE] = { new DefBlob(name1), new DefBlob(name2), new DefBlob(name3) };
		SpeedBlob* team2[ARRAY_SIZE] = { new SpeedBlob(name4), new SpeedBlob(name5), new SpeedBlob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 3 && teamType2 == 1) {
		SpeedBlob* team1[ARRAY_SIZE] = { new SpeedBlob(name1), new SpeedBlob(name2), new SpeedBlob(name3) };
		Atkblob* team2[ARRAY_SIZE] = { new Atkblob(name4), new Atkblob(name5), new Atkblob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 3 && teamType2 == 2) {
		SpeedBlob* team1[ARRAY_SIZE] = { new SpeedBlob(name1), new SpeedBlob(name2), new SpeedBlob(name3) };
		DefBlob* team2[ARRAY_SIZE] = { new DefBlob(name4), new DefBlob(name5), new DefBlob(name6) };

		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else if (teamType1 == 3 && teamType2 == 3) {
		SpeedBlob* team1[ARRAY_SIZE] = { new SpeedBlob(name1), new SpeedBlob(name2), new SpeedBlob(name3) };
		SpeedBlob* team2[ARRAY_SIZE] = { new SpeedBlob(name4), new SpeedBlob(name5), new SpeedBlob(name6) };
		while ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) != 0 &&
			(team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) != 0) {
			cout << endl;

			if (ctr % 2 == 0 && team1First == true) { // if blob1First = true && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // if
			else if (ctr % 2 == 0 && team1First == false) { // if blob1First = false && ctr % 2 is even
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == true) { // if blob1First = true && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team2[i]->getSpeed() > team1[i]->getSpeed()) {
							attack = team2[i]->getAtStat() - team1[i]->getDefStat();
							cout << team2[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team2[i]->getSpeed() < team1[i]->getSpeed()) {
							attack = 0;
							cout << team2[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team1[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team2[i]->getAtStat() - team1[i]->getDefStat();
						team1[i]->decHP(attack);

						cout << team2[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else if (ctr % 2 == 1 && team1First == false) { // if blob1First = false && ctr % 2 is odd
				for (int i = 0; i < ARRAY_SIZE; i++) {
					int diceRoll = die->roll(dicenum);
					double numPossibleValues = dicenum * 6.0 - (dicenum - 1.0);
					int perc60 = round(0.6 * numPossibleValues - 0.1);
					int perc40 = round(0.4 * numPossibleValues - 0.1);

					if (diceRoll >= dicenum && diceRoll <= perc60 + (dicenum - 1)) {
						// between value of dicenum && perc75 (needs to be dicenum + however many dice EX: 2 dice == 2 - 9)
						if (team1[i]->getSpeed() > team2[i]->getSpeed()) {
							attack = team1[i]->getAtStat() - team2[i]->getDefStat();
							cout << team1[i]->getName() << " uses a normal attack!" << endl;
						} // if
						else if (team1[i]->getSpeed() < team2[i]->getSpeed()) {
							attack = 0;
							cout << team1[i]->getName() << " uses a poor attack!" << endl;
						} // else if
						else {} // else
						team2[i]->decHP(attack);

						ctr++;
					} // if
					else if (diceRoll > perc60 + (dicenum - 1) && diceRoll <= perc60 + (dicenum - 1) + perc40) {
						// between value of perc75 && value of perc75 + perc15
						attack = team1[i]->getAtStat() - team2[i]->getDefStat();
						team2[i]->decHP(attack);

						cout << team1[i]->getName() << " uses a normal attack!" << endl;

						ctr++;
					} // else if
				} // for loop for determining every group order

				cout << "Team One has " << (team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) << " health points remaining." << endl;
				cout << "Team Two has " << (team2[0]->getHP() + team2[1]->getHP() + team2[2]->getHP()) << " health points remaining." << endl;
			} // else if
			else {} // else
		} // while loop

		cout << endl;
		if ((team1[0]->getHP() + team1[1]->getHP() + team1[2]->getHP()) == 0) {
			cout << "Team Two emerges victoriously!" << endl;
		} // if
		else {
			cout << "Team One emerges victoriously!" << endl;
		} // else

		for (int i = 0; i < ARRAY_SIZE; i++) {
			delete team1[i];
			delete team2[i];
		} // deletion for loop

		delete die;
	} // else if
	else {} // else

	// terminate
	cout << endl << "Program Ending..." << endl;
	return 0;
} // main function
