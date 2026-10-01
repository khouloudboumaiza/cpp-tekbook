#include <iostream>
#include "tekbook.hpp"

int main() {
    std::cout << "Bienvenue sur " << tekbook::app_name() << "!\n";
    std::cout << "2 + 3 = " << tekbook::add(2, 3) << "\n";
    return 0;
}
