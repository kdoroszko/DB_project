#pragma once

#include "Human.hpp"
#include <string>
#include <iostream>

class Student : public Human
{

public:
    
    Student(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address, std::string new_no_of_grade_book)
        : Human(new_name, new_surname, new_PESEL, new_sex, new_address), no_of_grade_book(new_no_of_grade_book) {}

    std::string print() const;
    std::string get_no_of_grade_book() const;
    virtual double get_salary() const;
    virtual void set_salary(double new_salary) {/*Student nie ma pensji*/}

private:

    std::string no_of_grade_book;
};

