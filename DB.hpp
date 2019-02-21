#pragma once

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
    void delete_human_by_PESEL(std::string PESEL);
    std::vector<Human*>::iterator find_by_surname(std::string surname); //wyswietlic wszystkie mozliwosci, np. cala kolekcje z tym samym nazwiskiem
    std::vector<Human*>::iterator find_by_PESEL(std::string PESEL);
    void print() const;
    void sort_by_grade_book();
    void sort_by_PESEL();
    void sort_by_surname();
    void change_address_by_PESEL(std::string PESEL, std::string new_address);
    //generowanie losowych danych: zbior imion, nazwisk itp. potem losowac i tworzyc osoby

private:

    std::vector<Human*> people;
};

