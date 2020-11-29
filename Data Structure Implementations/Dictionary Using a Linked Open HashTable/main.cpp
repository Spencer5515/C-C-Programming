#include "HashTableOpen.hpp"
#include <string>

int main() {
    HashTableOpen<string, string> dict;
    string userWord = "", s = "";
    int userChoice = 0;
    bool flag = false;

    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("cactus", "a pointy plant");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("graph", "an awesome data structure!");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("igloo", "a cool house");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("quack", "said Mr. Duck");

    cout << "Welcome to my open hash table dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Size\n";
    cout << "\t5. Clear\n";
    cout << "\t6. Quit\n";

    do {
        cout << "Enter your option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                try {
                    cout << "Enter a key to search my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    s = dict.find(userWord);
                    cout << s << endl;
                }
                catch (int&) { }
                break;

            case 2:
                cout << "Enter the key of the new record: ";
                cin.ignore();
                getline(cin, userWord);
                cout << "Enter the value of the new record: ";
                getline(cin, s);
                dict.insert(userWord, s);
                break;

            case 3:
                cout << "Enter the key of the record to be "
                     << "removed from my dictionary: ";
                cin.ignore();
                getline(cin, userWord);
                dict.remove(userWord);
                break;

            case 4:
                cout << "Dictionary size is " << dict.size() << endl;
                break;

            case 5:
                cout << "Clearing out my dictionary . . . ";
                dict.clear();
                cout << "cleared!\n";
                break;

            case 6:
                flag = true;
                break;
        }
    } while (!flag);

    return 0;
}
