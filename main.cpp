#include <iostream>
#include <vector>

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"
#include "DB.hpp"

int main()
{
    DB database;

    Student A("Adam", "Adamowski", "99011012345", "male", "Wroclaw", "123");
    Employee V("Wiktotia", "Kowalska", "78060614785", "female", "Brzeg", 1500);
    Student B("Bartosz", "Byk", "94041712585", "male", "Opole", "456");
    Employee W("Wanda", "Wół", "56082917485", "female", "Długołęka", 2500);
    Student C("Celina", "Czajka", "97100812456", "female", "Środa Śląska", "789");
    Employee X("Anna", "Nowak", "88021412642", "female", "Jelenia Góra", 3500);
    Student D("Dariusz", "Drewniak", "91051923345", "male", "Oława", "249");
    Employee Y("Zuzanna", "Zegar", "76022812311", "female", "Częstochowa", 4500);
    Student E("Emil", "Ekierka", "99032412379", "male", "Wroclaw", "536");
    Employee Z("Zbigniew", "Ząbek", "49120112445", "male", "Wrocław", 1000);

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

    auto it_find_by_surname = database.find_by_surname("Drewniak");
    auto it_find_by_PESEL = database.find_by_PESEL("99032412379");

    return 0;
}
