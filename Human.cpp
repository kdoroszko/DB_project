#include "pch.h"
#include "Human.hpp"

Human::Human(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address)
: name(new_name), surname(new_surname), PESEL(new_PESEL), sex(new_sex), address(new_address)
{
    if (!correct_PESEL(new_PESEL))
            throw std::logic_error("Invalid PESEL");
}

std::string Human::print()
{
    name.resize(15, ' ');
    surname.resize(15, ' ');
    PESEL.resize(15, ' ');
    sex.resize(15, ' ');
    address.resize(15, ' ');

    return name + surname + PESEL + sex + address;
}

bool Human::correct_PESEL(std::string new_PESEL) const
{
    new_PESEL.resize(11);
    std::array<int, 11> compute;
    std::transform(new_PESEL.begin(), new_PESEL.end(), compute.begin(), [](const auto& s) {return s - '0';});

    std::array<int, 11> constants_for_compute = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int addition_control = std::inner_product(new_PESEL.begin(), new_PESEL.end(), constants_for_compute.begin(), 0);

    const int system = 10;
    if (addition_control % system == 0)
        return true;
    else return false;
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