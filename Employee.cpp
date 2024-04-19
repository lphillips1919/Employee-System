// ---------- INCLUDES ----------
#include <iostream>
#include <iomanip>
#include <exception>
#include <random>
#include <ctime>
#include "Employee.h"

const int MAX_ID_NUM = 9999;
const int MIN_ID_NUM = 1;


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

int GenerateId() {
    srand((unsigned int)time(NULL));
    int id = rand() % MAX_ID_NUM + MIN_ID_NUM;
    
    return id;
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
    int id = GenerateId();
    float salary = 0;
    std::cin.exceptions(std::ios_base::failbit);
    try {
        // need an ignore since we have dont have an endl; after prompting for name
        std::cout << "Employees Full Name: ";
        std::cin.ignore();
        while (name.empty()) {
            getline(std::cin, name);
            employee.SetName(name);
        }

        std::cout << "Employee ID: ";
        employee.SetId(id);
        std::cout << employee.GetId() << std::endl;

        std::cout << "Salary: $";
        std::cin >> salary; 
        employee.SetSalary(salary);

        employees.push_back(employee);
    } catch (const std::ios_base::failure &failure) {
        std::cout << std::endl;
        std::cin.clear();
        std::cout << "Invalid Arguement!"<< std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void ViewEmployees(std::vector<Employee> employees) {
    size_t size = employees.size();
    // iterate through vector of employees
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

    std::cin.exceptions(std::ios_base::failbit);
    try {
        std::cout << "Enter Employee ID: ";
        std::cin >> id;

        // searches for existing id in employees vector
        // returns true if found
        // sets the index to i
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
    } catch (const std::ios_base::failure &failure) {
        std::cout << std::endl;
        std::cin.clear();
        std::cout << "Invalid Arguement!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void RemoveEmployee(std::vector<Employee> &employees) {
    size_t index = 0;
    int id = 0; 
    bool found = false;

    try {
        if (employees.size() != 0) {
            std::cout << "Enter Employee ID: ";
            std::cin >> id;

            // iterates over every employee in the employees vector
            for (size_t i = 0; i < employees.size(); i++) {
                if (id == employees[i].GetId()) {
                    found = true;
                    index = i;
                }
            }
            // if found remove employees at position[index]
            if (found == true) {
                std::cout << "Employee:  " << employees[index].GetName() << " has been removed" << std::endl;
                employees.erase(employees.begin() + static_cast<long>(index));
            } else {
                std::cout << "ID: " << id << " does not exist. " << std::endl;
            }
        } else {
            std::cout << "There are no employees!" << std::endl;
        }
    } catch (const std::ios_base::failure &failure) {
        std::cout << std::endl;
        std::cin.clear();
        std::cout << "Invalid Arguement!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void EditEmployee(std::vector<Employee> &employees) {
    int id, choice = 0;
    bool found = false;
    size_t index = 0;
    std::cout << "-----Editor Mode-----" << std::endl;
    std::cout << "Enter employee ID to Edit: ";
    try {
        std::cin >> id;
        for (size_t i = 0; i < employees.size(); i++) {
            if (id == employees[i].GetId()) {
                found = true;
                index = i;
            }
        }
        
        if (found == true) { 
            while (choice != 4) {
                std::cout << "1.) Edit Name: " << std::endl;
                std::cout << "2.) Edit Id: " << std::endl;
                std::cout << "3.) Edit Salary: " << std::endl;
                std::cout << "4.) Quit: " << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1) {
                    std::string newName = "";
                    std::cout << "Enter new name: ";
                    std::cin.ignore();
                    getline(std::cin, newName);
                    employees[index].SetName(newName);
                } else if (choice == 2) {
                    int newId = GenerateId();
                    employees[index].SetId(newId);
                } else if (choice == 3) {
                    float newSalary = 0;
                    std::cout << "Enter new salary: ";
                    std::cin >> newSalary;
                    employees[index].SetSalary(newSalary);
                } else {
                    std::cout << "Not a valid choice (1-4)" << std::endl;
                }
            }
        } else {
            std::cout << "ID: " << id << " does not exist" << std::endl;
        }
    } catch (const std::ios_base::failure &failure) {
        std::cout << std::endl;
        std::cin.clear();
        std::cout <<  "Invalid Arguement!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}