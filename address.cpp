#include "address.h"
#include <iostream>

// Default constructor
Address::Address() {
    street = "";
    city = "";
    state = "";
    zip = "";
}

// Parameterized constructor
Address::Address(std::string street, std::string city, std::string state, std::string zip) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

// Init function
void Address::init(std::string street, std::string city, std::string state, std::string zip) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

// Print function
void Address::printAddress() const {
    std::cout << street << std::endl;
    std::cout << city << ", " << state << " " << zip << std::endl;
}

