#include "pch.h"
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

    if (it == people.end())
        std::cout << "W bazie nie ma studenta o nr indeksu: " << no_of_grade_book << "!\n";
    else people.erase(it);
}

void DB::delete_human_by_PESEL(std::string PESEL)
{
    auto it = find_by_PESEL(PESEL);

    if (it == people.end())
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
    std::for_each(people.begin(), people.end(), [](Human* human) {std::cout << human->print() << '\n'; });
}

void DB::sort_by_grade_book()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b) {return a->get_no_of_grade_book() < b->get_no_of_grade_book(); });
}

void DB::sort_by_PESEL()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b) {return a->get_PESEL() < b->get_PESEL(); });
}

void DB::sort_by_surname()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b) {return a->get_surname() < b->get_surname(); });
}

void DB::sort_by_salary()
{
    std::sort(people.begin(), people.end(), [](Human *a, Human *b) {return a->get_salary() < b->get_salary(); });
}

void DB::change_address_by_PESEL(std::string PESEL, std::string new_address)
{
    auto it = find_by_PESEL(PESEL);

    if (it == people.end())
        std::cout << "W bazie nie ma czlowieka o podanym nr PESEL: " << PESEL << "!\n";
    else (*it)->set_address(new_address);
}

void DB::change_salary_by_PESEL(std::string PESEL, double new_salary)
{
    auto it = find_by_PESEL(PESEL);

    if (it == people.end())
        std::cout << "W bazie nie ma czlowieka o podanym nr PESEL: " << PESEL << "!\n";
    else if (((*it)->get_salary()) == 0)
            std::cout << "Osoba o nr PESEL " << PESEL << " jest studentem i nie mozna jej ustawic pensji!\n";
        else (*it)->set_salary(new_salary);
}

void DB::save(std::string file_name) const
{
    std::ofstream DB_save_file(file_name.c_str());

    for (auto element : people)
    {
        DB_save_file << element->get_name() << '\n';
        DB_save_file << element->get_surname() << '\n';
        DB_save_file << element->get_PESEL() << '\n';
        DB_save_file << element->get_sex() << '\n';
        DB_save_file << element->get_address() << '\n';
        DB_save_file << element->get_no_of_grade_book() << '\n';
        DB_save_file << element->get_salary() << '\n';
    }
}

void DB::load(std::string file_name)
{
    std::ifstream DB_load_file(file_name.c_str());

    if (DB_load_file.good() == false)
    {
        std::cout << "\nPlik zapisu o podanej nazwie nie istnieje.\n";
        return;
    }

    people.clear();

    std::string load_data;
    int line_no = 1, human_no = 0;

    while (getline(DB_load_file, load_data))
    {
        static std::string temp_name = "NULL";
        static std::string temp_surname = "NULL";
        static std::string temp_PESEL = "NULL";
        static std::string temp_sex = "NULL";
        static std::string temp_address = "NULL";
        static std::string temp_no_of_grade_book = "NULL";
        static double temp_salary = 0;

        if (line_no == 1)
            temp_name = load_data;
        if (line_no == 2)
            temp_surname = load_data;
        if (line_no == 3)
            temp_PESEL = load_data;
        if (line_no == 4)
            temp_sex = load_data;
        if (line_no == 5)
            temp_address = load_data;
        if (line_no == 6)
            temp_no_of_grade_book = load_data;
        if (line_no == 7)
        {
            std::stringstream convert;
            convert << load_data;
            convert >> temp_salary;

            if (temp_salary == 0)
            {
                std::unique_ptr<Student> ptr_temp_student(new Student(temp_name, temp_surname, temp_PESEL, temp_sex, temp_address, temp_no_of_grade_book));
                people.emplace_back(ptr_temp_student.get());
            }
            else {
                std::unique_ptr<Employee> ptr_temp_employee(new Employee(temp_name, temp_surname, temp_PESEL, temp_sex, temp_address, temp_salary));
                people.emplace_back(ptr_temp_employee.get());
            }
        }

        if (line_no == 7)
            line_no = 1;
        else line_no++;
    }
}