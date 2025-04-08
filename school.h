//
// Created by johnb on 2/25/2025.
//

#ifndef SCHOOL_H
#define SCHOOL_H



struct School {
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string county;
    School* next;

    School(std::string n, std::string address, std::string c, std::string s, std::string co)
        : name(n), address(address), city(c), state(s), county(co), next(nullptr) {}

    void print() const {
        std::cout << name << ", " << address << ", " << city << ", " << state << ", "  << std::endl;
    }
};





#endif //SCHOOL_H
