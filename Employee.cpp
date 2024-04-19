#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Employee.h"

void Employee::SetId(int x) {
    id = x;
}

void Employee::SetName(std::string n) {
    name = n;
}

void Employee::SetSalary(float s) {
    salary = s;
}

int Employee::GetId() {
    return id;
}

std::string Employee::GetName() {
    return name;
}

float Employee::GetSalary() {
    return salary;
}

void AddEmployee(Employee &employee, std::vector<Employee> &employees) {
    std::string name;
    int id = 0;
    float salary = 0;

    // need a ignore since we have dont have an endl; after prompting for name
    std::cout << "Employees Full Name: ";
    std::cin.ignore();
    getline(std::cin, name);
    employee.SetName(name);

    std::cout << "Employee ID: ";
    std::cin >> id;
    employee.SetId(id);

    std::cout << "Salary: ";
    std::cin >> salary; 
    employee.SetSalary(salary);

    employees.push_back(employee);
}

void PrintEmployee(std::vector<Employee> employees) {
    size_t size = employees.size();
    for (size_t i = 0; i < size; ++i) {
        std::cout << std::setw(20)
                  << "Employee Name: " << employees[i].GetName() << std::endl;
        std::cout << std::setw(20) 
                  << "ID number: " << employees[i].GetId() << std::endl;
        std::cout << std::setw(20)
                  << "Salary: " << employees[i].GetSalary() << std::endl;
        std::cout << std::endl;
    }
}

void SearchEmployees(std::vector<Employee> employees) {
    std::string name;
    int id = 0; 
    bool found = false;
    std::cout << "Enter Employee ID: ";
    std::cin >> id;
    
    // iterates over every employee in the employees vector
    for (size_t i = 0; i < employees.size(); i++) {
        if (id == employees[i].GetId()) {
            found = true;
            name = employees[i].GetName();
        }
    }

    if (found == true) {
        std::cout << "ID: " << id << " belongs to " << name << std::endl;
    } else {
        std::cout << "ID: " << id << " does not exist. " << std::endl;
    }

}

    