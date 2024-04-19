#pragma once
#include <string>

class Menu {
    public:
        Menu();
        ~Menu();
        void PrintMenu();
        int GetChoice();
    
    private:
        int choice;
        static const int menuOptionsLength{6};
        std::string menuOptions[menuOptionsLength] = {"Add Employee",
                                                      "Search Employee",
                                                      "View All Employees",
                                                      "Remove Employee",
                                                      "Edit Employee",
                                                      "Quit"  
                                                     };
};