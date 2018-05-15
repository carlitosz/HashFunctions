#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

class HashEntry {
private:
      string key;
public:
    HashEntry() {
        key = "";
    }

    HashEntry(string key) {
        this->key = key;
    }

    string getKey() {
        return key;
    }
};

#endif /* HASH_ENTRY_H */
