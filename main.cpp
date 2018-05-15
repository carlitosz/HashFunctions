#include <iostream>
using namespace std;

#include "HashMap.h"

enum GeneralHashFunction {
    RS, JS, PJW, ELF, BKDR, SDBM, DJB, DEK, BP, FNV, AP
};

const int MIN = 1024;
const int MAX = 33554432;
const int STRING_SIZE = 26;
const string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}|";

void printOutput(int, string);
int execute(HashMap, int, GeneralHashFunction);
void printResult(HashMap, int);
string generateString();

int main(void){
    // Size of table
    srand(static_cast<unsigned int>(time(0)));
    int attempts = 0;
    int size;

    // Create new hash tables, print info, execute processes, print results.
    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table(size);
    printOutput(size, "RSHash()");
    attempts = execute(table, size, RS);
    printResult(table, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table2(size);
    printOutput(size, "JSHash()");
    attempts = execute(table2, size, JS);
    printResult(table2, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table3(size);
    printOutput(size, "PJWHash()");
    attempts = execute(table3, size, PJW);
    printResult(table3, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table4(size);
    printOutput(size, "ELFHash()");
    attempts = execute(table4, size, ELF);
    printResult(table4, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table5(size);
    printOutput(size, "BKDRHash()");
    attempts = execute(table5, size, BKDR);
    printResult(table5, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table6(size);
    printOutput(size, "SDBMHash()");
    attempts = execute(table6, size, SDBM);
    printResult(table6, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table7(size);
    printOutput(size, "DJBHash()");
    attempts = execute(table7, size, DJB);
    printResult(table7, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table8(size);
    printOutput(size, "DEKHash()");
    attempts = execute(table8, size, DEK);
    printResult(table8, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table9(size);
    printOutput(size, "BPHash()");
    attempts = execute(table9, size, BP);
    printResult(table9, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table10(size);
    printOutput(size, "FNVHash()");
    attempts = execute(table10, size, FNV);
    printResult(table10, attempts);

    size = rand() % (MAX - MIN + 1) + MIN;
    HashMap table11(size);
    printOutput(size, "APHash()");
    attempts = execute(table11, size, AP);
    printResult(table11, attempts);

    return 0;
}

// ==================================================================
// printResult.
//
// input -> nothing.
// output -> information to stdout.
// ==================================================================
void printResult(HashMap table, int key) {
    cout << endl << endl;
    cout << "========= Execution has finished =========" << endl;
    cout << "There were: "
         << table.getCollisions()
         << " collisions." 
         << endl;
    
    cout << "There were: "
         << key
         << " attempted insertions."
         << endl;
}

// ==================================================================
// execute.
//
// input -> table - the hash table instance, size - size of the table
// output -> nothing.
// ==================================================================
int execute(HashMap table, int size, GeneralHashFunction func) {
    int i = 0;
    string key = "";
    
    while (table.getNumEntries() < size) {
        key = generateString();
        table.put(key, i, func, size);
        i++;
    }

    return i;
}

// ==================================================================
// printOutput.
//
// input -> the name of the function.
// output -> information to stdout.
// ==================================================================
void printOutput(int size, string func) {
    cout << "New hash table of size "
         << size
         << " has been created." << endl << endl;

    cout << "Updates provided at: " << endl;
    cout << "Insertion: " << size / (7/8) << endl;
    cout << "Insertion: " << size / (3/4) << endl;
    cout << "Insertion: " << size / 2 << endl;
    cout << "Insertion: " << size / 4 << endl;
    cout << "Insertion: " << size / 8 << endl;
    cout << "Insertion: " << size / 16 << endl;
    cout << "Insertion: " << size / 32 << endl;
    cout << "Insertion: " << size / 64 << endl;
    cout << "Insertion: " << size / 128 << endl;

    cout << "Populating table using " << func << endl << endl;
}

// ==================================================================
// generateString.
//
// input -> nothing.
// output -> a random alphanumeric string.
// ==================================================================
string generateString() {
    string randomStr = "";

    for(int i = 0; i < STRING_SIZE; i++) {
        randomStr += CHARS [rand() % CHARS.size()];
    }

    return randomStr;
}
