//
// Created by johnb on 2/25/2025.
//


#define SCHOOLLIST_H
#include "School.h"
#include <iostream>
#include <string>


class SchoolList {
private:
    School* head;

public:
    SchoolList() : head(nullptr) {}

    void insert(School s) {
        School* newNode = new School(s);
        newNode->next = head;
        head = newNode;
    }

    void insertFirst(std::string name, std::string address, std::string city, std::string state, std::string county) {
        School* newSchool = new School(name, address, city, state, county);
        newSchool->next = head;
        head = newSchool;
    }

    void insertLast(std::string name, std::string address, std::string city, std::string state, std::string county) {
        School* newSchool = new School(name, address, city, state, county);
        if (!head) {
            head = newSchool;
            return;
        }
        School* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newSchool;
    }

    void deleteByName(std::string name) {
        if (!head) {
            std::cout << "List is empty.";
            return;
        }
        if (head->name == name) {
            School* temp = head;
            head = head->next;
            delete temp;
            std::cout << "School " << name << " deleted.\n";
            return;
        }
        School* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (!temp->next) {
            std::cout << "School not found.\n";
            return;
        }
        School* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        std::cout << "School " << name << " deleted.\n";
    }

    void findByName(std::string name) {
        School* temp = head;
        while (temp) {
            if (temp->name == name) {
                std::cout << "School Found:\n";
                std::cout << "Name: " << temp->name << "\nAddress: " << temp->address << "\nCity: " << temp->city
                          << "\nState: " << temp->state << "\nCounty: " << temp->county << "\n";
                return;
            }
            temp = temp->next;
        }
        std::cout << "School not found.\n";
    }

    void display() {
        if (!head) {
            std::cout << "The list is empty.\n";
            return;
        }
        School* temp = head;
        std::cout << "School List:\n";
        while (temp) {
            std::cout << "Name: " << temp->name << ", Address: " << temp->address << ", City: " << temp->city
                      << ", State: " << temp->state << ", County: " << temp->county << "\n";
            temp = temp->next;
        }
    }

    ~SchoolList() {
        School* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

};




