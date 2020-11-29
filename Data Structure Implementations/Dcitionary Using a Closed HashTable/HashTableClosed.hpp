#ifndef HT_CLOSED_H
#define HT_CLOSED_H

#include "Dictionary.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

template <typename Key, typename Val>
class HashTableClosed : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() {
                k = Key{};
                v = Val{};
            }

            Record(Key x, Val y) {
                k = x;
                v = y;
            }
        };

        // the underlying (dynamic) array of records
        Record* ht;

        // the size of the hash table (total number of slots)
        int M;

        // a special marker
        Key TOMBSTONE;

        // hash function
        // folding method (assumes that Key = string)
        int hash(const Key&) const;

        // probe function
        // linear probing method
        int linearProbe(const Key&, int) const;

    public:
        // default constructor
        HashTableClosed(int = 100, const Key& = Key{});

        // destructor
        virtual ~HashTableClosed();

        // remove all records in the dictionary
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // print a visual representation of the hash table
        void print(bool = false) const;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

template <typename Key, typename Val>
HashTableClosed<Key, Val>::HashTableClosed(int i, const Key& k) {
    M = i;
	ht = new Record[M];
	TOMBSTONE = k;
	Record temp(TOMBSTONE, TOMBSTONE);

	for (int i = 0; i < M; i++) {
		ht[i] = temp;
	} // for loop
}

template <typename Key, typename Val>
HashTableClosed<Key, Val>::~HashTableClosed() {
    clear();
	delete[] ht;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::clear() {
    for (int i = 0; i < M; i++) {
		ht[i].k = TOMBSTONE;
		ht[i].v = TOMBSTONE;
	} // for loop
}

template <typename Key, typename Val>
Val HashTableClosed<Key, Val>::find(const Key& target) const {
    int hashed = hash(target);
	int ctr = 0;

	while (ctr < M && ht[hashed].k != TOMBSTONE && ht[hashed].k != target) {
		ctr++;
		hashed++; // increments hash index
		hashed %= M; // rehashed the hash index
	} // while
	if (ht[hashed].k == target) {
		return ht[hashed].v;
	} // if
	else {
		cerr << "ERROR: key not found.\n\n"; // if the key wasn't found
		throw -1;
	} // else
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::hash(const Key& k) const {
    // how long should each fold be
    // changing this means you should also change the reinterpeted data type
    const int FOLD_LEN = 4;

    // if the fold length is 4, then must treat the string as unsigned numbers
    unsigned* ikey = (unsigned*) k.c_str();

    // calculate how many folds there are
    int ilen = k.length() / FOLD_LEN;

    // accumulator
    unsigned sum = 0;

    // for each fold, now treated as a number, add it to the running total
    for (int i = 0; i < ilen; i++) {
        sum += ikey[i];
    }

    // calculate how many leftover characters there are
    int extra = k.length() - ilen * FOLD_LEN;

    // create a temporary array that will hold those extra characters
    char temp[FOLD_LEN];

    // clear out that array with a 0 value
    ikey = (unsigned*) temp;
    ikey[0] = 0;

    // copy the extra characters over
    for (int i = 0; i < extra; i++) {
        temp[i] = k[ilen * FOLD_LEN + i];
    }

    // add these final characters as a number to the running total
    sum += ikey[0];

    // calculate the slot position
    int slot = sum % M;

    // display the hashing information
    cout << k << " hashes to slot " << slot << endl;

    // return the valid slot position
    return slot;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::insert(const Key& k, const Val& v) {
    int hashed = hash(k);
	Record temp(k, v);

	while (ht[hashed].k != TOMBSTONE) {
		hashed++; // increments hash index
		hashed %= M; // rehashed the hash index
	} // while
	// once I hit a TOMBSTONE exit the loop
	ht[hashed] = temp;
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::linearProbe(const Key& k, int i) const {
    return i;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::print(bool tombFlag) const {
    const char FILL = '-';
    const int WIDTH = 80;
    const int SLOT_WIDTH = 4;
    const int KEY_WIDTH = 25;

    cout << setfill(FILL) << setw(WIDTH) << "" << endl << setfill(' ');

    for (int i = 0; i < M; i++) {
        cout << right << setw(SLOT_WIDTH) << i << " | "
             << left << setw(KEY_WIDTH)
             << (ht[i].k != TOMBSTONE || tombFlag ? ht[i].k : "")
             << " | "
             << (ht[i].k != TOMBSTONE || tombFlag ? ht[i].v : "")
             << endl;
    }

    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::remove(const Key& target) {
    int hashed = hash(target);

	while (ht[hashed].k != TOMBSTONE) {
		if (ht[hashed].k == target) {
			ht[hashed].k = TOMBSTONE;
			ht[hashed].v = TOMBSTONE;
		} // if
		hashed++; // increments hash index
		hashed %= M; // rehashed the hash index
	} // while
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::size() const {
	int ctr = 0;

	for (int i = 0; i < M; i++) {
		if (ht[i].k != TOMBSTONE) {
			ctr++;
		} // if
	} // for loop
	return ctr;
}

#endif
