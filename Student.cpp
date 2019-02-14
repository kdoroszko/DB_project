#include "Student.hpp"

std::string Student::get_no_of_grade_book() const
{
    return no_of_grade_book;
}

std::ostream& operator << (std::ostream &os, const Student &s)
{
	os << s.get_name() << " " << s.get_surname() << ", PESEL: " << s.get_PESEL() << ", " << s.get_sex() << ", adres: " << s.get_address()
	<< ", nr indeksu: " << s.get_no_of_grade_book();

	return os;
}
