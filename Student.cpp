#include "pch.h"
#include "Student.hpp"

std::string Student::print() const
{
    return Human::print() + ", nr indeksu: " + get_no_of_grade_book();
}

std::string Student::get_no_of_grade_book() const
{
    return no_of_grade_book;
}