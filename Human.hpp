#pragma once

#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

class Human
{

public:
    
    Human(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address);

    virtual std::string get_no_of_grade_book() const = 0;
    virtual double get_salary() const = 0;
    virtual std::string print() const;
    bool correct_PESEL(std::string new_PESEL) const;
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_PESEL() const;
    void set_address(std::string new_address);

private:

    std::string name, surname, PESEL, sex, address;
};

