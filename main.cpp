#include <iostream>
#include <vector>
#include <algorithm>

#include "Human.hpp"
#include "Student.hpp"
#include "Employee.hpp"

int main()
{
    std::vector<Human> people;

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

    people.emplace_back(A);
    people.emplace_back(V);
    people.emplace_back(B);
    people.emplace_back(W);
    people.emplace_back(C);
    people.emplace_back(X);
    people.emplace_back(D);
    people.emplace_back(Y);
    people.emplace_back(E);
    people.emplace_back(Z);

    auto it_del = std::find(people.begin(), people.end(), people.get_no_of_grade_book());
    people.erase(it_del);

    people.erase(std::find(people.begin(), people.end(), people.get_no_of_grade_book()));

    return 0;
}
