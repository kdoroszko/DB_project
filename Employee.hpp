#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Human.hpp"


class Employee : public Human
{

public:

    Employee(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address, double new_salary)
    : Human(new_name, new_surname, new_PESEL, new_sex, new_address), salary(new_salary) {}

    virtual std::string get_no_of_grade_book() const;

private:

    double salary;
};

#endif // EMPLOYEE_HPP
