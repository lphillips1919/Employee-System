#include <iostream>
#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

void Menu::PrintMenu() {
    for (int i = 1; i < menuOptionsLength; i++) {
        std::cout << i << ". " << menuOptions[i] << std::endl;
    }
}

int::Menu::GetChoice() {
    std::cout << "Enter your menu choice: ";
    std::cin >> choice;
    return choice;
}