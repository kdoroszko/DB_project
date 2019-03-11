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
    void print();
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
    std::vector<std::string> rand_male_name;
    std::vector<std::string> rand_female_name;
    std::vector<std::string> rand_surname;
    std::vector<std::string> rand_PESEL;
    std::vector<std::string> rand_sex;
    std::vector<std::string> rand_address;
    std::vector<std::string> rand_no_of_grade_book;
    std::vector<double> rand_salary;
};

