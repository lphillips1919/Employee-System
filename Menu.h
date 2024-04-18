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
        static const int menuOptionsLength{4};
        std::string menuOptions[menuOptionsLength] = {"Add Employee",
                                                      "Remove Employee",
                                                      "View Employees",
                                                      "Quit"  
                                                     };
};