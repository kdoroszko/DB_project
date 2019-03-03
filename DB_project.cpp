#include "pch.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "DB.hpp"

int main()
{
    try
    {
        DB database;

        std::shared_ptr<Human> ptr_A;
        std::shared_ptr<Human> ptr_V;
        std::shared_ptr<Human> ptr_B;
        std::shared_ptr<Human> ptr_W;
        std::shared_ptr<Human> ptr_C;
        std::shared_ptr<Human> ptr_X;
        std::shared_ptr<Human> ptr_D;
        std::shared_ptr<Human> ptr_Y;
        std::shared_ptr<Human> ptr_E;
        std::shared_ptr<Human> ptr_Z;

        ptr_A.reset(new Student("Adam", "Adamowski", "99011012344", "mezczyzna", "Wroclaw", "123"));
        ptr_V.reset(new Employee("Wiktoria", "Kowalska", "78060614585", "kobieta", "Brzeg", 1500));
        ptr_B.reset(new Student("Bartosz", "Byk", "94041712587", "mezczyzna", "Opole", "456"));
        ptr_W.reset(new Employee("Wanda", "Wol", "56082917785", "kobieta", "Dlugoleka", 2500));
        ptr_C.reset(new Student("Celina", "Czajka", "97100812455", "kobieta", "Sroda Slaska", "789"));
        ptr_X.reset(new Employee("Anna", "Nowak", "88021412842", "kobieta", "Jelenia Gora", 3500));
        ptr_D.reset(new Student("Dariusz", "Drewniak", "91051923349", "mezczyzna", "Olawa", "249"));
        ptr_Y.reset(new Employee("Zuzanna", "Zegar", "76022812310", "kobieta", "Czestochowa", 4500));
        ptr_E.reset(new Student("Emil", "Ekierka", "99032462379", "mezczyzna", "Wroclaw", "536"));
        ptr_Z.reset(new Employee("Zbigniew", "Zabek", "49120112440", "mezczyzna", "Wroclaw", 1000));

        database.add_to_base(ptr_A);
        database.add_to_base(ptr_V);
        database.add_to_base(ptr_B);
        database.add_to_base(ptr_W);
        database.add_to_base(ptr_C);
        database.add_to_base(ptr_X);
        database.add_to_base(ptr_D);
        database.add_to_base(ptr_Y);
        database.add_to_base(ptr_E);
        database.add_to_base(ptr_Z);

        database.delete_student_from_base("789");
        database.delete_student_from_base("789111");

        database.find_by_surname("Byk");
        std::cout << "Powyzej wyswietla po nazwisku.\n\n";
        auto it_find_by_PESEL = database.find_by_PESEL("99032412379");

        database.print();

        std::cout << '\n';
        database.sort_by_grade_book();
        database.print();

        std::cout << '\n';
        database.sort_by_PESEL();
        database.print();

        std::cout << '\n';
        database.sort_by_surname();
        database.print();

        std::cout << '\n';
        database.delete_human_by_PESEL("56082917485");
        database.delete_human_by_PESEL("AAA");
        database.print();

        std::cout << '\n';
        database.change_address_by_PESEL("76022812311", "NOWY ADRES");
        database.print();

        std::cout << '\n';
        database.sort_by_salary();
        database.print();

        std::cout << '\n';
        database.change_salary_by_PESEL("111", 1000);
        database.change_salary_by_PESEL("99011012344", 1000);
        std::cout << '\n';
        database.change_salary_by_PESEL("76022812310", 6000);
        database.print();

        std::cout << '\n';
        database.save("Zapis_bazy.txt");
        database.delete_student_from_base("123");
        std::cout << "Po zapisie usunieto studenta o nr indeksu 123\n\n";
        database.print();
        std::cout << "\nWczytanie bazy z zapisanego pliku: \n\n";
        database.load("Zapis_bazy.txt");
        database.print();

        std::cout << "\nLosowo dodana osoba do bazy: \n\n";
        database.generate_data();
        database.print();
    }

    catch (std::logic_error message)
    {
        std::cout << "\nWprowadzony nr PESEL jest nieprawidlowy\n";
        std::exit(1);
    }

    return 0;
}