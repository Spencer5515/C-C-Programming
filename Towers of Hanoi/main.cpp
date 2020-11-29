#include <iostream>
using namespace std;

// T(n) = o(2^n)
void towerHanoi(int n, string source, string buffer, string target, int& x) {
	x++;
	if (n == 1)  {  
        cout << "Move disk 1 from rod #" << source << " to rod #" << buffer << endl;  
	    return;  
    }  // if
    towerHanoi(n - 1, source, target, buffer, x);  

    cout << "Move disk " << n << " from rod #" << source << " to rod #" << buffer << endl;  

    towerHanoi(n - 1, target, buffer, source, x);  
}

int main() {
	int x = 0;
	int n = 1; 
	cout << "********************\n";
	cout << "Trying n = " << n << endl << endl;
    towerHanoi(n, "1", "3", "2", x); // A, B and C are names of rods 
	cout << endl << "Number of moves = " << x << endl;
	cout << "********************\n";

	x = 0;
	n = 2; 
	cout << "********************\n";
	cout << "Trying n = " << n << endl << endl;
    towerHanoi(n, "1", "3", "2", x); // A, B and C are names of rods 
	cout << endl << "Number of moves = " << x << endl;
	cout << "********************\n";

	x = 0;
	n = 3; 
	cout << "********************\n";
	cout << "Trying n = " << n << endl << endl;
    towerHanoi(n, "1", "3", "2", x); // A, B and C are names of rods 
	cout << endl << "Number of moves = " << x << endl;
	cout << "********************\n";

	x = 0;
	n = 4; 
	cout << "********************\n";
	cout << "Trying n = " << n << endl << endl;
    towerHanoi(n, "1", "3", "2", x); // A, B and C are names of rods 
	cout << endl << "Number of moves = " << x << endl;
	cout << "********************\n";

    return 0;  
}