#include <iostream>
#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

void Menu::PrintMenu() {
    for (int i = 0; i < menuOptionsLength; i++) {
        std::cout << "\t" << i + 1 << ". " << menuOptions[i] << std::endl;
    }
}

int::Menu::GetChoice() {
    std::cout << "Enter your menu choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}
