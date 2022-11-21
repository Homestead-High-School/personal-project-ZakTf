// GameTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
inline
void hasWeapon(Game g) {
    if (g.hasWeapon() == true) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
}
void outputCharacter(Game g) {
    std::cout << "Name: " << g.getName() << "\n";
    std::cout << "Has weapon: ";
    hasWeapon(g);
    std::cout << "\n" << "Health: " << g.getHp() << "\n";
}

int main()
{
    std::string name;
    std::string storeAns;
    bool w;
    std::cout << "Create a new profile!" << "\n\n";
    std::cout << "Enter a name: ";
    std::cin >> name;
    std::cout << "Does your character have a weapon? (y/n) ";
    std::cin >> storeAns;
    if (storeAns == "y") {
        w = true;
    }
    else if (storeAns == "n") {
        w = false;
    }
    else {
        throw std::invalid_argument("Invalid Answer");
    }
    Game g(name, w, 50);
    std::cout << "\n\n";
    outputCharacter(g);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
