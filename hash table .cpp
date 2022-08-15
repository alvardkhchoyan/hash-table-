#include <iostream>
#include <list>

class HashTable {
public:
    HashTable(int);
    void insert_(int, int);
    void delete_(int);
    int hashfunction(int);
    void printHash();

private:
    int m_size;
    std::list<int>* m_table;
};


HashTable::HashTable(int size) {
    this->m_size = size;
    m_table = new std::list<int>[m_size];
}

int HashTable::hashfunction(int key) {
    return key % m_size;
}

void HashTable::insert_(int key, int val) {
    int ind = hashfunction(key);
    m_table[ind].push_back(val);
}

void HashTable::delete_(int key) {
    int ind = hashfunction(key);
    std::list<int>::iterator i;
    for (i = m_table[ind].begin(); i != m_table[ind].end(); ++i) {
        if (*i == key) {
            break;
        }
    }
    if (i != m_table[ind].end()) {
        m_table[ind].erase(i);
    }
}

void HashTable::printHash() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << i;
        for (auto j : m_table[i]) {
            std::cout << " " << j;
        }
        std::cout << std::endl;
    }
}


int main() {
    int size = 5;
    int key[size] = {12, 2, 8, 7, 21};
    int data[size] = {45, 77, 2, 10, 7};
    HashTable hash(8);
    for (int i = 0; i < size; ++i) {
        hash.insert_(key[i], data[i]);
    }
    hash.delete_(2);
    hash.printHash();
}
