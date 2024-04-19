#include <iostream>
#include <exception>
#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

void Menu::PrintMenu() {
    for (int i = 0; i < menuOptionsLength; i++) {
        std::cout << "\t" << i + 1 << ". " << menuOptions[i] << std::endl;
    }
}

int::Menu::GetChoice() {
    std::cin.exceptions(std::ios_base::failbit);
    try {
        std::cout << "Enter your menu choice: ";
        std::cin >> choice;
        std::cout << std::endl;
    } catch (const std::ios_base::failure &failure) {
        std::cin.clear();
        std::cout << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}
