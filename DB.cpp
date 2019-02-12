#include "DB.hpp"
#include <algorithm>

void DB::add_to_base(Human *new_human)
{
    people.emplace_back(new_human);
}

void DB::delete_student_from_base(std::string no_of_grade_book)
{
    auto it = std::find_if(people.begin(), people.end(), [](std::string no_of_grade_book)
    {
        return people.get_no_of_grade_book() == no_of_grade_book;
    });
}
