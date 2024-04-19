#pragma once
#include <string>
#include <vector>

class Employee {
    public:
        // ---------- SETTER ----------
            void SetId(int x);
            void SetName(std::string n);
            void SetSalary(float s);
        // ---------- GETTER ----------
            int GetId();
            std::string GetName();
            float GetSalary();
        // ---------- UTILITIES ----------
            void PrintEmployee();
    private:
        std::string name;
        float salary;
        int id;
};

int GenerateId();

void AddEmployee(Employee &employee, std::vector<Employee> &employees);
void SearchEmployeesById(std::vector<Employee> employees);
void ViewEmployees(std::vector<Employee> employees);
void RemoveEmployee(std::vector<Employee> &employees);
void EditEmployee(std::vector<Employee> &employees);
