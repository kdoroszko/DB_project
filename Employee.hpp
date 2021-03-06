#pragma once

#include "Human.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Employee : public Human
{

public:
    
    Employee(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address, double new_salary)
    : Human(new_name, new_surname, new_PESEL, new_sex, new_address), salary(new_salary) {}

    double get_salary() const;
    void set_salary(double new_salary);
    std::string print();
    virtual std::string get_no_of_grade_book() const;

private:

    double salary;
};

