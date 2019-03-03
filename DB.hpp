#pragma once

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <ctime>
#include <random>

class DB
{

public:
    
    void add_to_base(std::shared_ptr<Human> new_human);
    void delete_student_from_base(std::string no_of_grade_book);
    void delete_human_by_PESEL(std::string PESEL);
    void find_by_surname(std::string find_surname);
    std::vector<std::shared_ptr<Human>>::iterator find_by_PESEL(std::string PESEL);
    void print() const;
    void sort_by_grade_book();
    void sort_by_PESEL();
    void sort_by_surname();
    void sort_by_salary();
    void change_address_by_PESEL(std::string PESEL, std::string new_address);
    void change_salary_by_PESEL(std::string PESEL, double new_salary);
    void save(std::string file_name) const;
    void load(std::string file_name);
    void generate_data();

private:

    std::vector<std::shared_ptr<Human>> people;
    //tutaj czy w klasie Human?
    std::vector<std::string> rand_name{ "Julia", "Zofia", "Antoni", "Jakub" };
    std::vector<std::string> rand_surname{ "Kowalczyk", "Wozniak", "Mazur", "Krawczyk" };
    std::vector<std::string> rand_PESEL{ "99011012443", "99011012542", "99011012641", "99011012740" };
    std::vector<std::string> rand_sex{ "mezczyzna", "kobieta" };
    std::vector<std::string> rand_address{ "Szczecin", "Bialystok", "Warszawa", "Poznan" };
    std::vector<std::string> rand_no_of_grade_book{ "111", "222", "333", "444" }; //w klasie Student?
    std::vector<double> rand_salary{ 10, 15, 20, 25 }; //w klasie Employee?
};

