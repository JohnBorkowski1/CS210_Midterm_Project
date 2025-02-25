#include <iostream>
#include <string>

struct School {
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string county;
    School* next;

    School(std::string n, std::string address, std::string c, std::string s, std::string co)
        : name(n), address(address), city(c), state(s), county(co), next(nullptr) {}
};





int main() {
    return 0;
}