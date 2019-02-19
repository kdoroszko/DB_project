#include "Human.hpp"

std::string Human::print() const
{
    return name + " " + surname + ", PESEL: " + PESEL + ", " + sex + ", adres: " + address;
}

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

void Human::set_address(std::string new_address)
{
    address = new_address;
}
