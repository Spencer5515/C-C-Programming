#include "MyVector.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
/*******************************************************************************
*****   FUNCTION PROTOTYPE
*******************************************************************************/
template <typename T>
void printVector(MyVector<T>&);
/*******************************************************************************
*****   STARTING POINT
*******************************************************************************/
int main() {
    try {
        // create an empty vector
        MyVector<int> vec1;
        // confirm the size is 0
        cout << "vec1 size: " << vec1.size() << endl;
        // try an illegal operation
        try {
            cout << vec1.front() << endl;
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try another illegal operation
        try {
            cout << vec1.back() << endl;
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try another illegal operation
        try {
            cout << vec1[0] << endl;
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try another illegal operation
        try {
            cout << vec1.find(9) << endl;
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try another illegal operation
        try {
            vec1.remove(-4);
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try to add an item
        try {
            vec1.add(15);
        }
        catch (bad_alloc e) {
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        // confirm the size is now 1
        cout << "vec1 size: " << vec1.size() << endl;
        // try legal operations
        try {
            cout << "vec1 front: " << vec1.front() << endl;
            cout << "vec1 back: " << vec1.back() << endl;
            printVector(vec1);
        }
        catch (MyVector<int>::VectorError e) {
            cerr << e.what() << endl;
        }
        // create a second vector with starting size 5
        MyVector<char> vec2(5);
        // confirm the size is 5
        cout << "vec2 size: " << vec2.size() << endl;
        // try to initialize the vector and print it
        try {
            for (int i = 0; i < vec2.size(); i++) {
                vec2[i] = static_cast<char>(i + 97);
            }
            printVector(vec2);
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try an illegal operation
        try {
            cout << vec2[13] << endl;
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // create a third vector by copying from the second vector
		MyVector<char> vec3(vec2);
        // try to print it to confirm the elements were copied over
        try {
            printVector(vec3);
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try to add elements and print again
        try {
            for (int i = 5; i < 10; i++) {
                vec3.add(static_cast<char>(i + 97));
            }
            printVector(vec3);
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // confirm the new size is 10
        cout << "vec3 size: " << vec3.size() << endl;
        // try an illegal operation
        try {
            cout << vec3.find('q') << endl;
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try to find a legal item
        try {
            cout << "Index of item d is " << vec3.find('d') << endl;
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try to remove the front and back of the vector, then print
        try {
            vec3.remove(vec3.front());
            vec3.remove(vec3.back());
            printVector(vec3);
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // try to reset the vector
        try {
            vec3.reset();
        }
        catch (MyVector<char>::VectorError e) {
            cerr << e.what() << endl;
        }
        // confirm the size is now 0
        cout << "vec3 size: " << vec3.size() << endl;
        // terminate
        return 0;
    }
    catch (bad_alloc e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}
/*******************************************************************************
*****   FUNCTION DEFINITION
*******************************************************************************/
template <typename T>
void printVector(MyVector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}