#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#include "GeneralHashFunctions.h"
#include "GeneralHashFunctions.cpp"
#include "HashEntry.h"

class HashMap {
private:
      HashEntry **table;
      int tableSize;
      int collisions;
      int numElems;

public:
    // Overloaded constructor
    HashMap(int s) {
        tableSize = s, collisions = 0, numElems = 0;
        table = new HashEntry * [s];
        for (int i = 0; i < tableSize; i++) table[i] = NULL;
    }

    // Default constructor
    HashMap() {
        tableSize = 128, collisions = 0, numElems = 0;
        table = new HashEntry * [tableSize];
        for (int i = 0; i < tableSize; i++) table[i] = NULL;
    }

    // Put key into hash table
    void put(string key, int index, int func, int tableSize) {
        unsigned int hash = generateHash(key, func);

        // Hash out of bounds.
        if (hash > tableSize) {
            return;
        }

        // Provide updates (since this takes a long time!)
        if (tableSize / (7/8) == numElems) printUpdate(tableSize / (7/8));
        if (tableSize / (3/4) == numElems) printUpdate(tableSize / (3/4));
        if (tableSize / 2 == numElems) printUpdate(tableSize / 2);
        if (tableSize / 4 == numElems) printUpdate(tableSize / 4);
        if (tableSize / 8 == numElems) printUpdate(tableSize / 8);
        if (tableSize / 16 == numElems) printUpdate(tableSize / 16);
        if (tableSize / 32 == numElems) printUpdate(tableSize / 32);
        if (tableSize / 64 == numElems) printUpdate(tableSize / 64);
        if (tableSize / 128 == numElems) printUpdate(tableSize / 128);

        // Insert new.
        if (table[hash] == NULL) {
            table[hash] = new HashEntry(key);
            numElems++;

            return;
        }

        // Collision.
        if ((table[hash]->getKey()).length() > 0 && collisions == 0) {
            cout << "First collision detected on insertion attempt: " << index << endl;
            collisions++;
        }
    }

    void printUpdate(int size) {
        cout << "Insertion " << size << " has just been processed." << endl;
    }

    int getCollisions() {
        return collisions;
    }

    // Returns number of current entries
    int getNumEntries() {
        return numElems;
    }

    // Generates the new hash
    int generateHash(string key, int func) {
        switch (func) {
            case 0:
                return RSHash(key);
            case 1:
                return JSHash(key);
            case 2:
                return PJWHash(key);
            case 3:
                return ELFHash(key);
            case 4:
                return BKDRHash(key);
            case 5:
                return SDBMHash(key);
            case 6:
                return DJBHash(key);
            case 7:
                return DEKHash(key);
            case 8:
                return BPHash(key);
            case 9:
                return FNVHash(key);
            case 10:
                return APHash(key);
            default:
                return 0;
        }
    }

    // Destructor
    ~HashMap() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != 0)
                delete table[i];
        }

        delete[] table;
    }
};

#endif /* HASH_MAP_H */