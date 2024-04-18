#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Menu.h"

using namespace std;

int main() {
    vector<Employee> employees;
    bool loopControl = true;
    int selection = 0;
    Menu menu;
    menu.PrintMenu();

    while (loopControl) {
        selection = menu.GetChoice();
        if (selection == 1) {
            cout << "Not Yet implemented" << endl;
        } else if (selection == 2) {
            cout << "Not Yet implemented" << endl;
        } else if (selection == 3) {
            cout << "Goodbye" << endl;
            loopControl = false;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}