//
// Created by johnb on 4/1/2025.
//

#include "SchoolHashTable.h"

#include <fstream>
#include <sstream>
#include <string>


vector<School> loadSchoolsFromCSV(const string& filename) {
    vector<School> schools;
    ifstream file(filename);
    string line;

    getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        string name, address, city, state, zip;
        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');

        schools.emplace_back(name, address, city, state, zip);
    }

    return schools;
}

int main() {
    SchoolHashTable hashTable;
    string filename = "schools.csv";

    cout << "Loading data from " << filename << "...\n";
    vector<School> schools = loadSchoolsFromCSV(filename);
    for (const auto& school : schools) {
        hashTable.insert(school);
    }

    cout << schools.size() << " schools loaded into the hash table.\n";

    int choice;
    string name;
    do {
        cout << "\nOptions:\n1. Search\n2. Delete\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter school name to search: ";
            getline(cin, name);
            hashTable.findByName(name);
            break;
            case 2:
                cout << "Enter school name to delete: ";
            getline(cin, name);
            hashTable.deleteByName(name);
            break;
            case 3:
                hashTable.display();
            break;
            case 4:
                cout << "Exiting...\n";
            break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
