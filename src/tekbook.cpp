#include "tekbook.hpp"

namespace tekbook {
std::string app_name() {
    return "cpp-tekbook";
}

int add(int a, int b) {
    return a + b;
}
}

int defaut() {
    int* p = nullptr;
    return *p;
}
