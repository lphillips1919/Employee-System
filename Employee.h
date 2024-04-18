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
    private:
        std::string name;
        float salary;
        int id;
};

void AddEmployee(Employee &employee, std::vector<Employee> &employees);
void PrintEmployee(std::vector<Employee> employees);