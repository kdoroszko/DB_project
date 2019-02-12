#ifndef DB_HPP
#define DB_HPP

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>


class DB
{

public:

    void add_to_base(Human *new_human);

    void delete_student_from_base(std::string no_of_grade_book);

private:

    std::vector<Human*> people;
};

#endif // DB_HPP
