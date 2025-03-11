//
// Created by johnb on 3/11/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SchoolBST.h"
void loadCSV(SchoolBST& bst, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "error opening file\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        School school;
        getline(ss, school.name, ',');
        getline(ss, school.address, ',');
        getline(ss, school.city, ',');
        getline(ss, school.state, ',');
        getline(ss, school.county, ',');
        bst.insert(school);
    }
    file.close();
}

int main() {
    SchoolBST bst;
    loadCSV(bst, "schools.csv");

    int choice;
    string name;
    do {
        cout << "\n1. Search School\n2. Delete School\n3. Display In-Order\n4. Display Pre-Order\n5. Display Post-Order\n6. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter school name: ";
            getline(cin, name);
            if (School* school = bst.findByName(name))
                cout << "Found: " << school->name << ", " << school->city << "\n";
            else
                cout << "School not found\n";
            break;
            case 2:
                cout << "Enter school name to delete: ";
            getline(cin, name);
            bst.deleteByName(name);
            cout << "Deleted\n";
            break;
            case 3:
                bst.displayInOrder();
            break;
            case 4:
                bst.displayPreOrder();
            break;
            case 5:
                bst.displayPostOrder();
            break;
            case 6:
                cout << "Exiting\n";
            break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);
    return 0;
}
