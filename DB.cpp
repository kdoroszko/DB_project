#include "DB.hpp"

void DB::add_to_base(Human *new_human)
{
    people.emplace_back(new_human);
}

void DB::delete_student_from_base(std::string no_of_grade_book)
{
    auto it = std::find_if(people.begin(), people.end(), [no_of_grade_book](Human* human)
    {
        return human->get_no_of_grade_book() == no_of_grade_book;
    });

    if(it == people.end())
        std::cout << "W bazie nie ma studenta o nr indeksu: " << no_of_grade_book << "!\n";
    else people.erase(it);
}

void DB::delete_human_by_PESEL(std::string PESEL)
{
    auto it = find_by_PESEL(PESEL);

    if(it == people.end())
        std::cout << "W bazie nie ma czlowieka o podanym nr PESEL: " << PESEL << "!\n";
    else people.erase(it);
}

std::vector<Human*>::iterator DB::find_by_surname(std::string surname)
{
    return std::find_if(people.begin(), people.end(), [surname](Human* human)
    {
        return human->get_surname() == surname;
    });
}

std::vector<Human*>::iterator DB::find_by_PESEL(std::string PESEL)
{
    return std::find_if(people.begin(), people.end(), [PESEL](Human* human)
    {
        return human->get_PESEL() == PESEL;
    });
}

void DB::print() const
{
    std::for_each(people.begin(), people.end(), [](Human* human){std::cout << human->print() << '\n';});
}

void DB::sort_by_grade_book()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b){return a->get_no_of_grade_book() < b->get_no_of_grade_book();});
}

void DB::sort_by_PESEL()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b){return a->get_PESEL() < b->get_PESEL();});
}

void DB::sort_by_surname()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b){return a->get_surname() < b->get_surname();});
}

void DB::change_address_by_PESEL(std::string PESEL, std::string new_address)
{
    auto it = find_by_PESEL(PESEL);

    if(it == people.end())
        std::cout << "W bazie nie ma czlowieka o podanym nr PESEL: " << PESEL << "!\n";
    else (*it)->set_address(new_address);
}
