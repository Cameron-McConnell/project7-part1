#include "students.h"
#include <iostream>
#include <sstream>

// Default constructor
Student::Student() {
    firstName = "";
    lastName = "";
    creditHours = 0;
}

// Initialize using a single formatted string
// Example format:
// "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65"
void Student::init(std::string studentString) {
    std::stringstream ss(studentString);

    std::string street, city, state, zip;
    std::string birth, grad;

    ss >> firstName >> lastName;
    ss >> street >> city >> state >> zip;
    ss >> birth >> grad;
    ss >> creditHours;

    address.init(street, city, state, zip);
    birthDate.init(birth);
    gradDate.init(grad);
}

void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address.printAddress();
    std::cout << "Birth Date: ";
    birthDate.printDate();
    std::cout << "Graduation Date: ";
    gradDate.printDate();
    std::cout << "Credit Hours: " << creditHours << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}

