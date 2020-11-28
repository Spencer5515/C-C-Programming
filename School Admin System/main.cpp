#include "ArrayList.hpp"
#include "List.hpp"
#include "Dictionary.hpp"
#include "ALDict.hpp"
#include <iostream>
using namespace std;

// function prototypes
void run();
void FAQpage();

int main() {
	// declaration of ALDict of colleges"
	Dictionary<string, int>* CSstuDict;
	CSstuDict = new ALDict<string, int>();
	Dictionary<string, int>* PHYSstuDict;
	PHYSstuDict = new ALDict<string, int>();
	Dictionary<string, int>* ENGstuDict;
	ENGstuDict = new ALDict<string, int>();
	Dictionary<string, int>* LAWstuDict;
	LAWstuDict = new ALDict<string, int>();
	Dictionary<string, int>* PSstuDict;
	PSstuDict = new ALDict<string, int>();
	Dictionary<string, int>* HIstuDict;
	HIstuDict = new ALDict<string, int>();

	// insertions of all students into their respective colleges
	// these insert their name as the Key and performance as the Val
	CSstuDict->insert("Kyle", 98);
	CSstuDict->insert("Spencer", 15);
	CSstuDict->insert("Amanda", 89);
	CSstuDict->insert("Stephanie", 75);
	CSstuDict->insert("John", 90);

	PHYSstuDict->insert("Andrew", 100);
	PHYSstuDict->insert("Ethan", 95);
	PHYSstuDict->insert("Samantha", 92);
	PHYSstuDict->insert("Tracy", 78);
	PHYSstuDict->insert("Padme", 90);

	ENGstuDict->insert("Travis", 78);
	ENGstuDict->insert("Matt", 89);
	ENGstuDict->insert("Tony", 34);
	ENGstuDict->insert("Stacy", 92);
	ENGstuDict->insert("Madison", 67);

	LAWstuDict->insert("Jonny", 93);
	LAWstuDict->insert("Anakin", 100);
	LAWstuDict->insert("Alexander", 65);
	LAWstuDict->insert("Pierre", 45);
	LAWstuDict->insert("Barb", 94);

	PSstuDict->insert("Corey", 89);
	PSstuDict->insert("Bob", 56);
	PSstuDict->insert("Alexandria", 78);
	PSstuDict->insert("Harleigh", 23);
	PSstuDict->insert("Will", 90);

	HIstuDict->insert("Bonn", 96);
	HIstuDict->insert("Maddie", 99);
	HIstuDict->insert("Carlos", 56);
	HIstuDict->insert("Janelle", 87);
	HIstuDict->insert("Cole", 85);

// variables
	run(); // calls run function for menu info
	int totalPerf = 0;
	int numCol = 6;
	//individual performances of each school
	int CSperf = 0;
	int PHYSperf = 0;
	int ENGperf = 0;
	int LAWperf = 0;
	int PSperf = 0;
	int HIperf = 0;

	// varibales for the user choices in the menu system
	int userChoice = 6;
	int userChoice2 = 7;
	int userChoice3 = 5;
	int userChoice4 = 4;

	// creats ArrayList for total college performance
	ArrayList<int>* totalColPerfs = new ArrayList<int>();

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < CSstuDict->size(); i++) {
		CSperf += CSstuDict->getPerf(i);
	} // for loop
	totalColPerfs->append(CSperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < PHYSstuDict->size(); i++) {
		PHYSperf += PHYSstuDict->getPerf(i);
	} // for loop
	totalColPerfs->append(PHYSperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < ENGstuDict->size(); i++) {
		ENGperf += ENGstuDict->getPerf(i);
	} // for loop
	totalColPerfs->append(ENGperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < LAWstuDict->size(); i++) {
		LAWperf += LAWstuDict->getPerf(i);
	} // for loop
	totalColPerfs->append(LAWperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < PSstuDict->size(); i++) {
		PSperf += PSstuDict->getPerf(i);
		} // for loop
	totalColPerfs->append(PSperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < HIstuDict->size(); i++) {
		HIperf += HIstuDict->getPerf(i);
	} // for loop
	totalColPerfs->append(HIperf);

	// finds the total performance of each school && adds it to the Uni total
	for (int i = 0; i < totalColPerfs->getLength(); i++) {
		totalPerf += totalColPerfs->getElement(i);
	} // for loop

	totalPerf /= numCol; // finds total performance as an average of # of colleges

	cout << "Thank You for logging in, you may select options below:\n";

	do {
		// main menu
		cout << "\t1. Current University FAQ\n";
		cout << "\t2. Check overall University Academic Performance\n";
		cout << "\t3. Select Colleges\n";
		cout << "\t4. View Total Listing of Students\n";
		cout << "\t5. View All College Performances\n";
		cout << "\t6. Exit\n\n";

		cout << "Enter your choice: "; // initial user choice system
		cin >> userChoice;
		cout << endl;

		switch (userChoice) {
			case 1:
				FAQpage(); // prints the FAQ page from the FAQ function
				break;
			case 2:
				// prints overall performance of uni
				cout << "---------\n";
				cout << "Academic Performance of UC Livermore:\n";
				cout << "\t Overall Performance = " << totalPerf << " / 500." << endl;
				cout << "---------\n";
				// initial disclaimer of what "performance" means
				cout << "This value can be used to compare UC Livermore\n";
				cout << "to other UC's via their own calculations of this value.\n";
				cout << "NOTE: this value is obviously theoretical for the sake of this program\n";
				cout << "---------\n\n";
				break;
			case 3:
				do {
					// secondary meny for choosing colleges
					cout << "Listing of our Avaibale Colleges:\n";
					cout << "\t1. College of Computer Science\n";
					cout << "\t2. College of Physics\n";
					cout << "\t3. College of English\n";
					cout << "\t4. College of Law\n";
					cout << "\t5. College of Pharmecutical Sciences\n";
					cout << "\t6. College of History\n";
					cout << "\t7. Back to main menu\n\n";

					cout << "Enter your choice: "; // userchoice for a college
					cin >> userChoice2;
					cout << endl;

					switch (userChoice2) {
						case 1:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of Computer Science Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << CSperf / CSstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";

											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										CSstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << CSperf / CSstuDict->size() << endl;
										cout << "---------\n";
										CSstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							cout << endl;
							break;
						case 2:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of Physics Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << PHYSperf / PHYSstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";

											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										PHYSstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << PHYSperf / PHYSstuDict->size() << endl;
										cout << "---------\n";
										PHYSstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							cout << endl;
							break;
						case 3:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of English Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << CSperf / ENGstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";
																							
											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										ENGstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << ENGperf / ENGstuDict->size() << endl;
										cout << "---------\n";
										ENGstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							cout << endl;
							break;
						case 4:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of Law Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << CSperf / LAWstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";
																							
											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										LAWstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << LAWperf / LAWstuDict->size() << endl;
										cout << "---------\n";
										LAWstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							cout << endl;
							break;
						case 5:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of Pharmecutical Sciences Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << CSperf / PSstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";
																							
											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										PSstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << PSperf / PSstuDict->size() << endl;
										cout << "---------\n";
										PSstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							cout << endl;
							break;
						case 6:
							do {
								// secondary menu for choosing specific actions in each college
								cout << "College of History Listing:\n";
								cout << "\t1. College Academic Performance\n";
								cout << "\t2. Sort Listing of students\n";
								cout << "\t3. College Student Listing\n";
								cout << "\t4. Full College Printout\n";
								cout << "\t5. Back to College Menu\n\n";

								cout << "Enter your choice: "; // userChoice for college actions
								cin >> userChoice3;
								cout << endl;

								switch (userChoice3) {
									case 1: // prints performance of college
										cout << "---------\n";
										cout << "Academic Performance of College of CS:\n";
										cout << "\t Total Performance = " << CSperf / HIstuDict->size() << endl;
										cout << "---------\n\n";
										break;
									case 2:
										do {
											cout << "What kind of sort algorithm should be used?\n"
												<< "\t1. Bubble sort\n"
												<< "\t2. Selection sort\n"
												<< "\t3. Insertion sort\n"
												<< "\t4. Merge sort\n\n";
																							
											cout << "Enter your choice: "; // userchoice for a college
											cin >> userChoice4;
											cout << endl;
										} while (userChoice4 < 1 || userChoice4 > 4);
										CSstuDict->sort(userChoice4);
										break;
									case 3: // student printout
										cout << "---------\n";
										cout << "Full Student Listing in College of CS:\n";
										HIstuDict->print();
										cout << "---------\n\n";
										break;
									case 4: // full college printout
										cout << "---------\n";
										cout << "Full Printout of the College of CS:\n";
										cout << "\t Total Performance = " << HIperf / HIstuDict->size() << endl;
										cout << "---------\n";
										HIstuDict->print();
										cout << "---------\n\n";
										break;
									case 5: // exit command
										cout << "You have chosen to return to College Menu\n";
										break;
								} // switch
							} while (userChoice3 != 5);
							break;
						case 7:
							cout << "You have chosen to return to Main Menu\n";
							break;
					} // switch
				} while (userChoice2 != 7);
				cout << endl;
				break;
			case 4:
				// prrovides full print of all students in the college
				// prints out listing of students by college
				// (includes student names and performances)
				cout << "====================================================\n";
				cout << "Here is UC Livermore's Full Student List by College:\n\n";
				cout << "College of Computer Science\n";
				CSstuDict->print();
				cout << "College of Physics\n";
				PHYSstuDict->print();
				cout << "College of English\n";
				ENGstuDict->print();
				cout << "College of Law\n";
				LAWstuDict->print();
				cout << "College of Pharmecutical Sciences\n";
				PSstuDict->print();
				cout << "College of History\n";
				HIstuDict->print();
				cout << "====================================================\n\n";
				break;
			case 5:
				// provides full printout of uni performance
				// gives total performance again and individual performances of Colleges
				// the ladder is labeled as such
				cout << "====================================================\n";
				cout << "Here is UC Livermore's Full Performance Listing by College:\n";
				cout << "---------\n";
				cout << "Academic Performance of UC Livermore:\n";
				cout << "\t Overall Performance = " << totalPerf << " / 500." << endl;
				cout << "---------\n";
				cout << "Here is UC Livermore's Full Performance Listing by College:\n";
				cout << "---------\n";
				cout << "College of Computer Science: " << CSperf << " / 500." << endl;
				cout << "College of Physics: " << PHYSperf << " / 500." << endl;
				cout << "College of English: " << ENGperf << " / 500." << endl;
				cout << "College of Law: " << LAWperf << " / 500." << endl;
				cout << "College of Pharmecutical Sciences: " << PSperf << " / 500." << endl;
				cout << "College of History: " << HIperf << " / 500." << endl;
				cout << "---------\n";
				cout << "====================================================\n\n";
				break;
			case 6: // exit command
				cout << "You have chosen to Exit UC Livermore's Admin Portal.\n\n";
				break;
		} // switch
	} while (userChoice != 6);

	cout << "Program Terminating...\n";
	return 0;
} // main

void run() {
	// function to print a welcome or intro dialogue for the program
	cout << "|															 |\n";
	cout << "Welcome to University of California, Livermore's Admin Portal!\n";
	cout << "==============================================================\n\n";
	cout << "--------------------------------------------------------------\n";
	cout << "This portal allows admins to observe a listing of our different\n";
	cout << "colleges, their academic performance, the students in each college,\n";
	cout << "said students inidivual academic performance, and the overall\n";
	cout << "academic performance of our lovely university.\n";
	cout << "---------------------------------------------------------------\n\n";

	cout << "**NOTE: Student Performance is an integer value of 0 - 100**\n\n";
} // run function

void FAQpage() {
	// function to print my lame FAQ information
	cout << "Welcome to the Admin FAQ page!\n";
	cout << "==============================\n\n";
	cout << "NEWS LISTINGS:\n";
	cout << "\t- Somehow Student Spencer DeMera got into CSU Fullerton to\n";
	cout << "\t  complete his B.S. in Computer Science. \n";
	cout << "\t- C has risen to become the most popular programming\n";
	cout << "\t  language duirng the COVID-19 Pandemic.\n";
	cout << "\t- The original Jango Fett actor from Star Wars: Attack\n";
	cout << "\t  of The Clones has been cast to play Boba Fett in The\n";
	cout << "\t  Mandalorian: Season.2\n";
	cout << "\t- I'm running out of time I need to stop procrastinating!!\n\n";

	cout << "FAQ Listing:\n";
	cout << "\t- University of California, Livermore is now moving to full online instruction!\n";
	cout << "\t\t- All professors are required to draw up education plans for the Fall 2020 Semester.\n";
	cout << "\t\t- Full academic expectations will be posted on this Admin page later this week.\n\n";
	cout << "==============================\n\n";
} // FAQ function
