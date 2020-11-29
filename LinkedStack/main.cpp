#include "LinkedStack.hpp"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
using namespace std;

// function prototype
int postfixParser(string);

/*******************************************************************************
* int main()
*   Starting point of the program. Runs different mathematical expressions to
*   test the postfix parser.
*
* Input(s):
*   N/A
*
* Output:
*   An integer to signal to the OS the exit code
*******************************************************************************/

int main() {
    // test #1
    cout << postfixParser("6 3 +") << endl;
    cout << "Answer should be 9" << endl;
    
    // test #2
    cout << postfixParser("4 7 -") << endl;
    cout << "Answer should be -3" << endl;
    
    // test #3
    cout << postfixParser("0 5 *") << endl;
    cout << "Answer should be 0" << endl;
    
    // test #4
    cout << postfixParser("9 2 /") << endl;
    cout << "Answer should be 4" << endl;
    
    // test #5
    cout << postfixParser("1 0 /") << endl;
    cout << "Should display an error message and return 0" << endl;
    
    // test #6
    cout << postfixParser("10 3 +") << endl;
    cout << "Answer should be 13" << endl;
    
    // test #7
    cout << postfixParser("6 3 +") << endl;
    cout << "Answer should be 9" << endl;
    
    // test #8
    cout << postfixParser("18 3 4 * -") << endl;
    cout << "Answer should be 6" << endl;
    
    // test #9
    cout << postfixParser("11 2 * 2 /") << endl;
    cout << "Answer should be 11" << endl;
    
    // test #10
    cout << postfixParser("2 7 - 3 *") << endl;
    cout << "Answer should be -15" << endl;
    
    // test #11
    cout << postfixParser("13 8 - 6 4 + *") << endl;
    cout << "Answer should be 50" << endl;
    
    // test #12
    cout << postfixParser("5 14 + 9 6 4 / - * 10 +") << endl;
    cout << "Answer should be 162" << endl;

	cout << "\nProgram Ending...\n";
    return 0;
} // main function

int postfixParser(string s) {
	LinkedStack<int> Tempstack;
	int mult;

	for(int i = 0; i < s.length(); i++) {
		string temp;
		if(isdigit(s[i])) {
			temp = temp+s[i];
			++i;

			while(isdigit(s[i])) {
				temp = temp+s[i];
				++i;
			} // while

			int str = stoi(temp);
			Tempstack.push(str);
		} // if
		else if(s[i]==' ') {
			continue;
		} // else if
		else {
			int c = Tempstack.top();
			Tempstack.pop();
			int b = Tempstack.top();
			Tempstack.pop();

			switch(s[i]) {
				case '+':
					Tempstack.push(b+c);
					break;
				case '-':
					Tempstack.push(b-c);
					break;
				case '*':
					Tempstack.push(b*c);
					break;
				case '/':
					if(c == 0) { Tempstack.push(0);}
					else {Tempstack.push(b / c);}
			} // switch
		} // else
  } // for loop

  return Tempstack.top();
}