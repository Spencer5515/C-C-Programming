#include "ALDict.hpp"
#include <string>

int main() {
    ALDict<string, string> dict(8);
    string userWord = "", s = "";

    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("cactus", "a pointy plant");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("graph", "an awesome data structure!");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("igloo", "a cool house");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("quack", "said Mr. Duck");

    while (true) {
        try {
            cout << "Enter a key to search my dictionary (or -1 to stop): ";
            getline(cin, userWord);
            if (userWord == "-1") {
                break;
            }
            s = dict.find(userWord);
            cout << s << endl;
        }
        catch (int&) { }
    }

    return 0;
}
