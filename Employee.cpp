#include "Employee.hpp"

double Employee::get_salary() const
{
    return salary;
}

std::ostream& operator << (std::ostream &os, const Employee &e)
{
    os << e.get_name() << " " << e.get_surname() << ", PESEL: " << e.get_PESEL() << ", " << e.get_sex() << ", adres: " << e.get_address()
	<< ", wysokosc pensji: " << e.get_salary() << " PLN";

	return os;
}
