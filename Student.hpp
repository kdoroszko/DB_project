#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Human.hpp"

#include <string>


class Student : public Human
{

public:

    Student(std::string new_name, std::string new_surname, std::string new_PESEL, std::string new_sex, std::string new_address, std::string new_no_of_grade_book)
    : Human(new_name, new_surname, new_PESEL, new_sex, new_address), no_of_grade_book(new_no_of_grade_book) {}

    std::string get_no_of_grade_book() const;

private:

    std::string no_of_grade_book;

};

#endif // STUDENT_HPP
