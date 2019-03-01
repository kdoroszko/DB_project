#include "pch.h"
#include "Human.hpp"

Human::Human(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address)
: name(new_name), surname(new_surname), PESEL(new_PESEL), sex(new_sex), address(new_address)
{
    //if (!correct_PESEL(new_PESEL))
            //throw std::logic_error("Invalid PESEL");
}

std::string Human::print() const
{
    return name + " " + surname + ", PESEL: " + PESEL + ", " + sex + ", adres: " + address;
}

bool Human::correct_PESEL(std::string new_PESEL) const
{
    int check_PESEL = std::stoi(new_PESEL);
    std::array<int, 11> compute;
    const int system = 10;
    /*auto it = compute.rbegin();

    std::generate(compute.rbegin(), compute.rend(), [&compute, &check_PESEL, &it]()
    {
        compute.at(*it) = check_PESEL % system;
        check_PESEL /= system;
        it++;
    });*/

    for (int i = 10; i >= 0; i--)
    {
        compute.at(i) = check_PESEL % system;
        check_PESEL /= system;
    }

    int addition_control = compute.at(0) + 3 * compute.at(1) + 7 * compute.at(2) + 9 * compute.at(3) + compute.at(4) + 3 * compute.at(5) + 7 * compute.at(6)
        + 9 * compute.at(7) + compute.at(8) + 3 * compute.at(9) + compute.at(10);

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