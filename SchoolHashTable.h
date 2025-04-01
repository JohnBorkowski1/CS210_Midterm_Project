//
// Created by johnb on 3/30/2025.
//

#ifndef SCHOOLHASHTABLE_H
#define SCHOOLHASHTABLE_H

#include <iostream>
#include <vector>
#include <list>


using namespace std;

struct School {
    string name;
    string address;
    string city;
    string state;
    string zip;

    School(string n, string a, string c, string s, string z)
        : name(n), address(a), city(c), state(s), zip(z) {}

    void print() const {
        cout << name << ", " << address << ", " << city << ", " << state << ", " << zip << endl;
    };
};

class SchoolHashTable {
private:
    static const int TABLE_SIZE = 101;  // Use a prime number
    vector<list<School>> table;
    const int p = 31;
    const int mod = 1e9 + 9;

    int hash(const string& name) {
        long long hashValue = 0;
        long long pPow = 1;
        for (char c : name) {
            hashValue = (hashValue + (tolower(c) - 'a' + 1) * pPow) % mod;
            pPow = (pPow * p) % mod;
        }
        return static_cast<int>(hashValue % TABLE_SIZE);
    }

public:
    SchoolHashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(const School& school) {
        int index = hash(school.name);
        table[index].push_back(school);
    }

    void deleteByName(const string& name) {
        int index = hash(name);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->name == name) {
                chain.erase(it);
                cout << "Deleted: " << name << endl;
                return;
            }
        }
        cout << "School not found.\n";
    }

    void findByName(const string& name) {
        int index = hash(name);
        for (const auto& school : table[index]) {
            if (school.name == name) {
                cout << "Found: ";
                school.print();
                return;
            }
        }
        cout << "School not found.\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                cout << "Index " << i << ":\n";
                for (const auto& school : table[i]) {
                    cout << "  - ";
                    school.print();
                }
            }
        }
    }
};



#endif //SCHOOLHASHTABLE_H
