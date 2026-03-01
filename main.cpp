/*
#include <iostream>
#include "date.h"
#include "address.h"
#include "students.h"

void testAddress();
void testDate();
void testStudent();

int main(){
  std::cout << "Hello!" << std::endl;
  testAddress();
  testDate();
  testStudent();
  return 0;
} // end main


void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress


void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate


void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "date.h"
#include "address.h"
#include "students.h"

void testAddress();
void testDate();
void testStudent();

void loadStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void sortByLastName(std::vector<Student*>& students);
void sortByFirstName(std::vector<Student*>& students);
void sortByCredits(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

int main(){

  std::cout << "Hello!" << std::endl;

  // Keep your test functions
  testAddress();
  testDate();
  testStudent();


  std::vector<Student*> students;

  loadStudents(students);

  std::string choice;

  do {
      choice = menu();

      if (choice == "1")
          showStudentNames(students);
      else if (choice == "2")
          printStudents(students);
      else if (choice == "3")
          findStudent(students);
      else if (choice == "4")
          sortByLastName(students);
      else if (choice == "5")
          sortByFirstName(students);
      else if (choice == "6")
          sortByCredits(students);

  } while (choice != "0");

  delStudents(students);

  return 0;
} // end main


// Test funcitons

void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
}

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
}

void testStudent(){
  std::string studentString =
  "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";

  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst() << std::endl;
  delete student;
}


// Function assignment

void loadStudents(std::vector<Student*>& students){

    std::ifstream inFile;
    std::string currentLine;

    inFile.open("students.csv");
    while(getline(inFile, currentLine)){
	    std::cout <<currentLine << std::endl;
	    Student* s = new Student();
	    s->init(currentLine);
	    students.push_back(s);
    } // end while

    inFile.close();

} // end loadStudent

void showStudentNames(std::vector<Student*>& students){
    for (Student* student: students){
        std::cout << student->getLastFirst();
    	std::cout << ", " << student->getCreditHours() << std::endl;
    } // end for
} // end shsowStudentNames

void printStudents(std::vector<Student*>& students){
    for (Student* student: students){
        student->printStudent();
    } // end for
}  // end printStudents

void findStudent(std::vector<Student*>& students){
	std::string search;
       	std::cout << "Enter name of student: ";
       	std::getline(std::cin, search);

	bool found = false;
	
	for (Student* student: students){
		if (student->getLastName().find(search) != std::string::npos){
		       	student->printStudent();
			found = true;
                } 
        }
	
	if (!found){
		std::cout << "Student not found." << std::endl;
	}
} // end findStudent

void sortByLastName(std::vector<Student*>& students){

    std::sort(students.begin(), students.end(),
        [](Student* a, Student* b){
            return a->getLastName() < b->getLastName();
	    });
        
}

void sortByFirstName(std::vector<Student*>& students){

    std::sort(students.begin(), students.end(),
        [](Student* a, Student* b){
            return a->getFirstName() < b->getFirstName();
	    });
       
}

void sortByCredits(std::vector<Student*>& students){

    std::sort(students.begin(), students.end(),
        [](Student* a, Student* b){
            return a->getCreditHours() > b->getCreditHours();
	    });
      
}

void delStudents(std::vector<Student*>& students){
    for (Student* student: students){
        delete student;
    students.clear();
    }
} // end delStudents

std::string menu(){

    std::string choice;

    std::cout << "\n0) quit\n";
    std::cout << "1) print all student names\n";
    std::cout << "2) print all student data\n";
    std::cout << "3) find a student\n";
    std::cout << "4) sort by last name\n";
    std::cout << "5) sort by first name\n";
    std::cout << "6) sort by credit hours (descending)\n";
    std::cout << "\nplease choose 0-6: ";

    std::getline(std::cin, choice);

    return choice;
}
