#pragma once
#include <string>
#include <vector>

class Employee {
    public:
        // ---------- SETTER ----------
            void SetId(int x);
            void SetName(std::string n);
            void SetYearsWorked(int y);
        // ---------- GETTER ----------
            int GetId();
            std::string GetName();
            int GetYearsWorked();
        // ---------- UTILITIES ----------
    private:
        std::string name;
        int yearsWorked;
        int id;
};

void AddEmployee(Employee &employee, std::vector<Employee> &employees);
void PrintEmployee(std::vector<Employee> employees);