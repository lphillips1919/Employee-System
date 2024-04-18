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
    menu.PrintMenu();

    while (loopControl) {
        selection = menu.GetChoice();
        if (selection == 1) {
            AddEmployee(employee, employees);
        } else if (selection == 2) {
            PrintEmployee(employees);
        } else if (selection == 3) {
            cout << "Goodbye" << endl;
            loopControl = false;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}