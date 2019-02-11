#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>


class Human
{

public:

    Human(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address)
    : name(new_name), surname(new_surname), PESEL(new_PESEL), sex(new_sex), address(new_address) {}

private:

    std::string name, surname, PESEL, sex, address;
};

#endif // HUMAN_HPP
