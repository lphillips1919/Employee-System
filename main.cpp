// ---------- INCLUDES ----------
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Menu.h"

using namespace std;

int main() {
    // ----- MAIN VARIABLES -----
    Employee employee;
    Menu menu;
    vector<Employee> employees;
    bool loopControl = true;
    int selection = 0;

    // ----- MENU -----
    while (loopControl) {
        menu.PrintMenu();
        selection = menu.GetChoice();
        if (selection == 1) {
            AddEmployee(employee, employees);
        } else if (selection == 2) {
            SearchEmployeesById(employees);
        } else if (selection == 3) {
            ViewEmployees(employees);
        } else if (selection == 4) {
            // RemoveEmployee(employees);
            cout << "Employees: " << employees.size() << endl;
        } else if (selection == 5) {
            cout << "\t Goodbye" << endl;
            loopControl = false;
        } else {
            cout << "Invalid choice!" << endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}