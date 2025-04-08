#include <chrono>
#include <iostream>
#include <string>
#include "School.h"
#include "SchoolList.h"
#include "CSVReader.h"
#include "SchoolBST.h"
#include "SchoolHashTable.h"

using namespace std;

std::vector<School> loadSchoolsFromCSV(const std::string& filename) {
    std::vector<School> schools;
    std::ifstream file(filename);
    std::string line, name, address, city, state, county;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }

    std::getline(file, line);

    int lineCount = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, name, ',');
        std::getline(ss, address, ',');
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, county, ',');

        if (!name.empty()) {
            schools.emplace_back(name, address, city, state, county);
            lineCount++;
        }
    }

    std::cout << "Total parsed schools: " << lineCount << std::endl;
    return schools;
}

template<typename Func>
long long timeFunction(Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {
    std::string filename = "C:/Users/johnb/CLionProjects/MidtermProject/USA_Schools.csv";
    std::vector<School> schools = loadSchoolsFromCSV(filename);
    std::cout << "Loaded " << schools.size() << " schools.\n";




    SchoolList ll;
    SchoolBST bst;
    SchoolHashTable ht;

    auto llInsertTime = timeFunction([&]() {
        for (auto& s : schools) ll.insert(s);
    });

    auto bstInsertTime = timeFunction([&]() {
        for (auto& s : schools) bst.insert(s);
    });

    auto htInsertTime = timeFunction([&]() {
        for (auto& s : schools) ht.insert(s);
    });

    std::cout << "Insertion Times (µs):\n";
    std::cout << "Linked List: " << llInsertTime << "\n";
    std::cout << "BST: " << bstInsertTime << "\n";
    std::cout << "Hash Table: " << htInsertTime << "\n";

    int searchCount = std::min(100, (int)schools.size());
    auto llSearchTime = timeFunction([&]() {
        for (int i = 0; i < searchCount; i++) ll.findByName(schools[i].name);
    });

    auto bstSearchTime = timeFunction([&]() {
        for (int i = 0; i < searchCount; i++) bst.findByName(schools[i].name);
    });

    auto htSearchTime = timeFunction([&]() {
        for (int i = 0; i < searchCount; i++) ht.findByName(schools[i].name);
    });

    std::cout << "\nSearch Times (µs) for " << searchCount << " records:\n";
    std::cout << "Linked List: " << llSearchTime << "\n";
    std::cout << "BST: " << bstSearchTime << "\n";
    std::cout << "Hash Table: " << htSearchTime << "\n";


    auto llDeleteTime = timeFunction([&]() {
    for (int i = 0; i < searchCount; i++) {
        ll.deleteByName(schools[i].name);
    }
});

    auto bstDeleteTime = timeFunction([&]() {
        for (int i = 0; i < searchCount; i++) {
            bst.deleteByName(schools[i].name);
        }
    });

    auto htDeleteTime = timeFunction([&]() {
        for (int i = 0; i < searchCount; i++) {
            ht.deleteByName(schools[i].name);
        }
    });

    std::cout << "\nDeletion Times (µs) for " << searchCount << " records:\n";
    std::cout << "Linked List: " << llDeleteTime << "\n";
    std::cout << "BST: " << bstDeleteTime << "\n";
    std::cout << "Hash Table: " << htDeleteTime << "\n";

    return 0;
}

