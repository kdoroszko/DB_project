#include "pch.h"
#include "Student.hpp"

std::string Student::print()
{
    return Human::print() + get_no_of_grade_book();
}

std::string Student::get_no_of_grade_book() const
{
    return no_of_grade_book;
}

double Student::get_salary() const
{
    return 0;
}