#include <iostream>
#include "Employee.h"

Employee::Employee() {}
Employee::~Employee() {}

void Employee::SetId(int x) {
    id = x;
}

void Employee::SetName(std::string n) {
    name = n;
}

void Employee::SetYearsWorked(int y) {
    yearsWorked = y;
}

int Employee::GetId() {
    return id;
}

std::string Employee::GetName() {
    return name;
}

int Employee::GetYearsWorked() {
    return yearsWorked;
}

void PrintEmployee(std::vector<Employee> employees) {
    auto size = employees.size();
    for (auto i = 0; i < size; ++i) {
        std::cout << employees[i].GetName() << std::endl;
        std::cout << employees[i].GetId() << std::endl;
        std::cout << employees[i].GetYearsWorked() << std::endl;
    }
}

void AddEmployee(std::vector<Employee> employees) {
    
}
    