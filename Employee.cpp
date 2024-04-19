#include <iostream>
#include <iomanip>
#include <random>
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

void Employee::PrintEmployee() {
        std::cout << std::setw(20)
                  << "Employee Name: " << name << std::endl;
        std::cout << std::setw(20) 
                  << "ID number: " << id << std::endl;
        std::cout << std::setw(20)
                  << "Salary: $" << salary << std::endl;
        std::cout << std::endl;
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

    std::cout << "Salary: $";
    std::cin >> salary; 
    employee.SetSalary(salary);

    employees.push_back(employee);
}

void ViewEmployees(std::vector<Employee> employees) {
    size_t size = employees.size();
    for (size_t i = 0; i < size; ++i) {
        std::cout << std::setw(20)
                  << "Employee Name: " << employees[i].GetName() << std::endl;
        std::cout << std::setw(20) 
                  << "ID number: " << employees[i].GetId() << std::endl;
        std::cout << std::setw(20)
                  << "Salary: $" << employees[i].GetSalary() << std::endl;
    }
}

void SearchEmployeesById(std::vector<Employee> employees) {
    size_t index = 0;
    int id = 0; 
    bool found = false;

    std::cout << "Enter Employee ID: ";
    std::cin >> id;

    // iterates over every employee in the employees vector
    for (size_t i = 0; i < employees.size(); i++) {
        if (id == employees[i].GetId()) {
            found = true;
            index = i;
        }
    }

    if (found == true) {
        employees[index].PrintEmployee();
    } else {
        std::cout << "ID: " << id << " does not exist. " << std::endl;
    }
}

// void RemoveEmployee(std::vector<Employee> employees) {
//     size_t index = 0;
//     int id = 0; 
//     bool found = false;

//     std::cout << "Enter Employee ID: ";
//     std::cin >> id;

//     // iterates over every employee in the employees vector
//     for (size_t i = 0; i < employees.size(); i++) {
//         if (id == employees[i].GetId()) {
//             found = true;
//             index = i;
//         }
//     }

//     if (found == true) {
//         employees.erase(employees.begin() + index);
//         std::cout << "Employee " << employees[index].GetName() << " has been removed" << std::endl;
//     } else {
//         std::cout << "ID: " << id << " does not exist. " << std::endl;
//     }
// }

