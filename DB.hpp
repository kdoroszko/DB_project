#ifndef DB_HPP
#define DB_HPP

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>
#include <algorithm>


class DB
{

public:

    void add_to_base(Human *new_human);
    void delete_student_from_base(std::string no_of_grade_book);
    std::vector<Human*>::iterator find_by_surname(std::string surname);
    std::vector<Human*>::iterator find_by_PESEL(std::string PESEL);
    void print();

private:

    std::vector<Human*> people;
};

#endif // DB_HPP
