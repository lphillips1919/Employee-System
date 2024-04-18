#include <iostream>
#include <iomanip>
#include "Employee.h"

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
    size_t size = employees.size();
    for (size_t i = 0; i < size; ++i) {
        std::cout << employees[i].GetName() << std::endl;
        std::cout << employees[i].GetId() << std::endl;
        std::cout << employees[i].GetYearsWorked() << std::endl;
    }
}

void AddEmployee(Employee &employee, std::vector<Employee> &employees) {
    std::string name = "";
    int yrsWrked, id = 0;

    std::cout << "Enter your name: ";
    std::cin >> name;
    employee.SetName(name);
    
    std::cout << "Enter your id: ";
    std::cin >> id;
    employee.SetId(id);

    std::cout << "Enter how many years you have worked: ";
    std::cin >> yrsWrked; 
    employee.SetYearsWorked(yrsWrked);

    employees.push_back(employee);
}
    