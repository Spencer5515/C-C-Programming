#ifndef HT_OPEN_H
#define HT_OPEN_H

#include "Dictionary.hpp"
#include "LinkedList.hpp"

template <typename Key, typename Val>
class HashTableOpen : public Dictionary<Key, Val> {
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

        // the underlying (dynamic) array of (dynamic) linked lists
        LinkedList<Record>** ht;

        // the size of the hash table (total number of slots)
        int M;

        // hash function
        // folding method (assumes that Key = string)
        int hash(const Key&) const;

    public:
        // default constructor
        HashTableOpen(int = 100);

        // destructor
        virtual ~HashTableOpen();

        // remove all records in the dictionary
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

template <typename Key, typename Val>
HashTableOpen<Key, Val>::HashTableOpen(int i) {
	M = i;
	ht = new LinkedList<Record>*[M];
	for (int i = 0; i < M; i++) {
		ht[i] = new LinkedList<Record>;
	} // for loop
}

template <typename Key, typename Val>
HashTableOpen<Key, Val>::~HashTableOpen() {
    clear();
}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::clear() {
	for (int i = 0; i < M; i++) {
		delete ht[i];
		ht[i] = nullptr;
	} // for loop
	delete[] ht;
}

template <typename Key, typename Val>
Val HashTableOpen<Key, Val>::find(const Key& k) const {
	int hashed = hash(k);

	if (ht[hashed] == nullptr) { // if the slot is empty
		cerr << "ERROR: key not found, slot is empty.\n\n";
	} // if
	else {
		for (int i = 0; i < ht[hashed]->getLength(); i++) {
			if (ht[hashed]->getElement(i).k == k) {
				return ht[hashed]->getElement(i).v; // returns val at that position
			} // if
		} // for loop
		cerr << "ERROR: key not found.\n\n"; // if the key wasn't found in the LL
	} // else
	return nullptr;
}

template <typename Key, typename Val>
int HashTableOpen<Key, Val>::hash(const Key& k) const {
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
    cout << k << "\thashes to slot " << slot << endl;

    // return the valid slot position
    return slot;
}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::insert(const Key& k, const Val& v) {
	int hashed = hash(k);
	Record* rec = new Record();
	rec->k = k;
	rec->v = v;
	ht[hashed]->append(*rec);
}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::remove(const Key& k) {
    int hashed = hash(k);

	if (ht[hashed] == nullptr) { // if the slot is empty
		cerr << "ERROR: key not found, slot is empty.\n";
	} // if
	else {
		for (int i = 0; i < ht[hashed]->getLength(); i++) {
			if (ht[hashed]->getElement(i).k == k) {
				ht[hashed]->remove(i);
				return;
			} //if
		} // for loop
		cerr << "ERROR: key not found.\n"; // if the key wasn't found in the LL
	} // else
}

template <typename Key, typename Val>
int HashTableOpen<Key, Val>::size() const {
    int ctr = 0;
	for (int i = 0; i < M; i++) {
		if (ht[i] != nullptr) {
			ctr++;
		} // if
	} // for loop

	return ctr;
}

#endif
