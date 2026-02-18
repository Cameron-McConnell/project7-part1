#include <string>

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS



class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

public:
    // Constructors
    Address();
    Address(std::string street, std::string city, std::string state, std::string zip);

    // Mutator
    void init(std::string street, std::string city, std::string state, std::string zip);

    // Accessor
    void printAddress() const;
};

#endif


