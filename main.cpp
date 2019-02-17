#include <iostream>
#include <vector>
#include <cassert>

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "DB.hpp"

int main()
{
    DB database;

    Student A("Adam", "Adamowski", "99011012345", "mezczyzna", "Wroclaw", "123");
    Employee V("Wiktoria", "Kowalska", "78060614785", "kobieta", "Brzeg", 1500);
    Student B("Bartosz", "Byk", "94041712585", "mezczyzna", "Opole", "456");
    Employee W("Wanda", "Wol", "56082917485", "kobieta", "Dlugoleka", 2500);
    Student C("Celina", "Czajka", "97100812456", "kobieta", "Sroda Slaska", "789");
    Employee X("Anna", "Nowak", "88021412642", "kobieta", "Jelenia Gora", 3500);
    Student D("Dariusz", "Drewniak", "91051923345", "mezczyzna", "Olawa", "249");
    Employee Y("Zuzanna", "Zegar", "76022812311", "kobieta", "Czestochowa", 4500);
    Student E("Emil", "Ekierka", "99032412379", "mezczyzna", "Wroclaw", "536");
    Employee Z("Zbigniew", "Zabek", "49120112445", "mezczyzna", "Wroclaw", 1000);

    database.add_to_base(&A);
    database.add_to_base(&V);
    database.add_to_base(&B);
    database.add_to_base(&W);
    database.add_to_base(&C);
    database.add_to_base(&X);
    database.add_to_base(&D);
    database.add_to_base(&Y);
    database.add_to_base(&E);
    database.add_to_base(&Z);

    database.delete_student_from_base("789");
    database.delete_student_from_base("789111");

    auto it_find_by_surname = database.find_by_surname("Drewniak");
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

    return 0;
}
