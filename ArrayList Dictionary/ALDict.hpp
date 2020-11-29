#ifndef AL_DICT_H
#define AL_DICT_H

#include "Dictionary.hpp"
#include "ArrayList.hpp"

template <typename Key, typename Val>
class ALDict : public Dictionary<Key, Val> {
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

        // the underlying array-based list
        ArrayList<Record>* list;

        // sequential search algorithm (iterative)
        Val seqSearch(const Key&) const;

		// recurisve seq search
		Val recSeqSearch(const Key&, int, int) const;

        // binary search algorithm (iterative)
        Val binSearch(const Key&, int, int) const;

		// recursive binary search
		Val recBinarySearch(const Key&, int, int) const;

    public:
        // default constructor
        ALDict(int = 100);

        // destructor
        virtual ~ALDict();

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
ALDict<Key, Val>::ALDict(int i) {
    list = new ArrayList<Record>(i);
}

template <typename Key, typename Val>
ALDict<Key, Val>::~ALDict() {
    delete list;
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::binSearch(const Key& target, int left, int right) const {
// iterative
	Record* buffer = list->getBuffer();
	while (left <= right) { 
        int mid = left + (right - left) / 2; 
  
        if (buffer[mid].k == target) {
			return buffer[mid].v; 
		} // if
        else if (buffer[mid].k < target) {
			left = mid + 1;
		}  // else if
        else {
			right = mid - 1; 
		} // else
    }  // while
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::recBinarySearch(const Key& target, int left, int right) const {
// recursive
	Record* buffer = list->getBuffer();
	if (right >= left) { 
        int mid = left + (right - left) / 2; 

        if (buffer[mid].k == target) {
			return buffer[mid].v; 
		} // if
       	else if (buffer[mid].k > target) {
			 return recBinarySearch(target, left, mid - 1); 
		} // else if
        return recBinarySearch(target, mid + 1, right); 
    }  // if
}

template <typename Key, typename Val>
void ALDict<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::find(const Key& k) const {
    try {
		int i = list->getLength() - 1;
        // return seqSearch(k);
		// return recSeqSearch(k, 0, i);

        // return binSearch(k, 0, i);
		return recBinarySearch(k, 0, i);
    }
    catch (int& i) {
        cout << "ERROR: unable to find record\n";
        throw i;
    }
}

template <typename Key, typename Val>
void ALDict<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ALDict<Key, Val>::remove(const Key& k) {
    Record* buffer = list->getBuffer();
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (buffer[i].k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "Unable to find record with matching key to remove\n";
    }
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::seqSearch(const Key& target) const {
// iterative
    Record* buffer = list->getBuffer();

    for (int i = 0; i < list->getLength(); i++) {
        if (buffer[i].k == target) {
            return buffer[i].v;
        }
    }

    throw -1;
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::recSeqSearch(const Key& target, int left, int right) const {
// recurisve
	Record* buffer = list->getBuffer();
    if (right < left) {
		return 0; 
	} // if
    if (buffer[left].k == target) {
		return buffer[left].v; 
	} // if
    if (buffer[right].k == target) {
		return buffer[right].v; 
	} // if
    return recSeqSearch(target, left + 1, right - 1); 
}

template <typename Key, typename Val>
int ALDict<Key, Val>::size() const {
    return list->getLength();
}

#endif
