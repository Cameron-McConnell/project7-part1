#include <string>

#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

class Date{
  private:
    int month;
    int day;
    int year;
  public:
    Date();
    void init(std::string dateString);
    void printDate() const;
};

#endif
