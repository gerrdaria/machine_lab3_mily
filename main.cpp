#include <iostream>
#include <string>
#include "automat/mili.cpp"
#include "automat/mura.cpp"
#include "automat/minimizirovan.cpp"

int main() {
    std::cout << "Choose:\n";
    std::cout << "1. Mili\n2. Mura\n3. Minimizirovan\n> ";

    int choice;
    std::cin >> choice;

    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    try {
        if (choice == 1) {
            MiliAutomat automat;
            automat.setLine(input);
            automat.Auto();
        } else if (choice == 2) {
            MuraAutomat autom;
            autom.setLine(input);
            autom.Auto();
        } else if (choice == 3) {
            Automat autom;
            autom.setLine(input);
            autom.Auto();
        } else {
            std::cerr << "Wrong choice:" << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
