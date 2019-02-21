#include "pch.h"
#include "Employee.hpp"

double Employee::get_salary() const
{
    return salary;
}

std::string Employee::print() const
{
    std::stringstream temp_salary;
    temp_salary << salary;

    return Human::print() + ", wysokosc pensji: " + temp_salary.str() + " PLN";
}

std::string Employee::get_no_of_grade_book() const
{
    return "Nie jestem studentem";
}