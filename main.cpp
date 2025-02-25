#include <iostream>
#include <string>
#include "school.h"
#include "schoolList.h"
#include "CSVReader.h"

using namespace std;

void loadCSV(SchoolList &schoolList, const string &filename) {
    vector<vector<string>> data = CSVReader::readCSV(filename);

    if (data.empty()) {
        cerr << "Error CSV file is empty or could not be read\n";
        return;
    }

    for (size_t i = 1; i < data.size(); i++) {
        if (data[i].size() < 5) continue;
        schoolList.insertLast(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]);
    }

    cout << "CSV file loaded\n";
}

int main() {
    SchoolList schoolList;
    string filename = "schools.csv";
    loadCSV(schoolList, filename);

    int choice;
    string name;

    do {
        cout << "1. Search for a school\n";
        cout << "2. Delete a school\n";
        cout << "3. Display all schools\n";
        cout << "4. Exit\n";
        cout << "Choose one: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the school name to search: ";
            getline(cin, name);
            schoolList.findByName(name);
            break;
            case 2:
                cout << "Enter the school name to delete: ";
            getline(cin, name);
            schoolList.deleteByName(name);
            break;
            case 3:
                schoolList.display();
            break;
            case 4:
                cout << "Bye Bye\n";
            break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}

