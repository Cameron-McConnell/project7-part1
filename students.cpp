#include <iostream>
#include <sstream>

#include "students.h"
#include "address.h"
#include "date.h"

// Default constructor
Student::Student() {
    firstName = "";
    lastName = "";
    address = new Address();
    birthDate = new Date();
    gradDate = new Date();
    creditHours = 0;
} // end constructor

// Default destructor
Student::~Student(){
	delete address;
	delete birthDate;
	delete gradDate;
} // end destructor

// Initialize using a single formatted string
// Example format:
// "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65"
void Student::init(std::string studentString) {
    std::stringstream converter;
    // create temp strings as needed
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string sBirthDate;
    std::string sGradDate;
    std::string sCreditHours;

    // Load up string stream with input
    converter.clear();
    converter.str(studentString);

    // Pull date from stringStream CSV
    //Names go straight into attributes

    getline(converter, firstName, ',');
    getline(converter, lastName, ',');

    // Now pull data needed for address
    getline(converter, street, ',');
    getline(converter, city, ',');
    getline(converter, state, ',');
    getline(converter, zip, ',');

    // Initialize address with this data
    address->init(street, city, state, zip);

    // Get dates
    getline(converter, sBirthDate, ',');
    getline(converter, sGradDate, ',');

    // Use dates to initiate date classes
    birthDate->init(sBirthDate);
    gradDate->init(sGradDate);

    // Get credit hours
    getline(converter, sCreditHours, ',');

    // Convert credit Hours to an int

    converter.clear();
    converter.str("");
    converter << sCreditHours;
    converter >> creditHours;

} // End init

void Student::printStudent(){
	std::cout << lastName << ", " << firstName << std::endl;
	address->printAddress();
	std::cout << "Birth date: ";
	birthDate->printDate();
	std::cout << "Grad date: ";
	gradDate->printDate();
	std::cout << "Credit Hours: " << creditHours << std::endl;
	std::cout << std::endl;
} // End printStudent
  
std::string Student::getLastFirst(){
	std::stringstream converter;
	converter.str("");
	converter << lastName << ", " << firstName;
	return converter.str();
} // End getLastFirst

std::string Student::getLastName(){
	return lastName;
} // End getLastName
 
std::string Student::getFirstName(){
	return firstName;
} // End getFirstName

int Student::getCreditHours(){
	return creditHours;
} // End getCreditHours





