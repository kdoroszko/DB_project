#include "Employee.hpp"

double Employee::get_salary() const
{
    return salary;
}

void Employee::set_salary(double new_salary)
{
    salary = new_salary;
}

std::string Employee::print()
{
    std::stringstream temp_salary;
    temp_salary << salary;

    return Human::print() + temp_salary.str() + " PLN";
}

std::string Employee::get_no_of_grade_book() const
{
    return "Nie jestem studentem";
}