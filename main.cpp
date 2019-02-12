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

    Student *ptr_A = &A;
    Employee *ptr_V = &V;
    Student *ptr_B = &B;
    Employee *ptr_W = &W;
    Student *ptr_C = &C;
    Employee *ptr_X = &X;
    Student *ptr_D = &D;
    Employee *ptr_Y = &Y;
    Student *ptr_E = &E;
    Employee *ptr_Z = &Z;

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

    /*auto it_del = std::find(people.begin(), people.end(), people.get_no_of_grade_book());
    people.erase(it_del);

    people.erase(std::find(people.begin(), people.end(), people.get_no_of_grade_book()));*/

    return 0;
}
