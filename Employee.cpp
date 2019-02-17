#include "Employee.hpp"

double Employee::get_salary() const
{
    return salary;
}

std::string Employee::print() const
{
    std::stringstream temp_salary;
    temp_salary << salary;

    return get_name() + " " + get_surname() + ", PESEL: " + get_PESEL() + ", " + get_sex() + ", adres: " + get_address()
	+ ", wysokosc pensji: " + temp_salary.str() + " PLN";
}

std::string Employee::get_no_of_grade_book() const
{
        return "Nie jestem studentem";
}

std::ostream& operator << (std::ostream &os, const Employee &e)
{
    os << e.get_name() << " " << e.get_surname() << ", PESEL: " << e.get_PESEL() << ", " << e.get_sex() << ", adres: " << e.get_address()
	<< ", wysokosc pensji: " << e.get_salary() << " PLN";

	return os;
}
