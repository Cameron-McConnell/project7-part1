# Heap of Students Part 1


## UML

'''mermaid
classDiagram

class Student{
    firstName: string
    lastName: string
    address: Address
    birthDate: Date
    gradDate: Date
    creditHours: int
    Student()
    init(string studentString)
    printStudent()
    getLastFirst(): string
}

class Address{
    street: string
    city: string
    state: string 
    zip: string
    Address()
    init(street, city, state, zip)
    printAddress
}

class Date{
    month: int
    day: int
    year: int
    Date()
    init(dateString)
    printDate()
}

Student--> Address
Student--> Date

'''



BEGIN PROGRAM

PRINT "Hello!"

CALL testAddress
CALL testDate
CALL testStudent


CREATE empty vector of Student pointers called students

CALL loadStudents(students)


DO

    DISPLAY menu options:
        0) quit
        1) print all student names
        2) print all student data
        3) find a student
        4) sort by last name
        5) sort by first name
        6) sort by credit hours (descending)

    GET user choice

    IF choice == "1"
        FOR each student in students
            PRINT student's last name, first name
        END FOR

    ELSE IF choice == "2"
        FOR each student in students
            PRINT full student record
        END FOR

    ELSE IF choice == "3"
        ASK user for last name substring
        FOR each student in students
            IF student's last name contains substring
                PRINT full student record
            END IF
        END FOR

    ELSE IF choice == "4"
        SORT students by last name in ascending order

    ELSE IF choice == "5"
        SORT students by first name in ascending order

    ELSE IF choice == "6"
        SORT students by credit hours in descending order

WHILE choice is not "0"


FOR each student in students
    DELETE student from heap
END FOR

CLEAR students vector

END PROGRAM



-------------------------
LOAD STUDENTS PROCEDURE
-------------------------

OPEN file "students.csv"

IF file cannot be opened
    PRINT error message
    RETURN
END IF

WHILE there is another line in file

    READ one line

    IF line is empty
        CONTINUE to next line
    END IF

    CREATE new Student on heap

    INITIALIZE student using CSV line

    ADD student pointer to students vector

END WHILE

CLOSE file



-------------------------
TEST FUNCTIONS
-------------------------

testAddress:
    CREATE Address object
    INITIALIZE with sample data
    PRINT address

testDate:
    CREATE Date object
    INITIALIZE with sample date string
    PRINT date

testStudent:
    CREATE Student pointer on heap
    INITIALIZE using sample CSV string
    PRINT full student record
    PRINT last name, first name
    DELETE student

END
