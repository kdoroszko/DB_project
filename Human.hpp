#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include <iostream>


class Human
{

public:

    Human(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address)
    : name(new_name), surname(new_surname), PESEL(new_PESEL), sex(new_sex), address(new_address) {}

    virtual std::string print() const = 0;
    virtual std::string get_no_of_grade_book() const = 0;
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_PESEL() const;
    std::string get_sex() const;
    std::string get_address() const;
    void set_address(std::string new_address);

private:

    std::string name, surname, PESEL, sex, address;
};

std::ostream& operator << (std::ostream &os, const Human &h);

#endif // HUMAN_HPP
