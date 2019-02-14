#include "Human.hpp"

std::string Human::get_name() const
{
    return name;
}

std::string Human::get_surname() const
{
    return surname;
}

std::string Human::get_PESEL() const
{
    return PESEL;
}

std::string Human::get_sex() const
{
    return sex;
}

std::string Human::get_address() const
{
    return address;
}

std::ostream& operator << (std::ostream &os, const Human &h)
{
    os << h.get_name() << " " << h.get_surname() << ", PESEL: " << h.get_PESEL() << ", " << h.get_sex() << ", adres: " << h.get_address();

	return os;
}
