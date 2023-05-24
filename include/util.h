#include <iostream>

namespace util {
    inline int getnum() {
        std::string n;
        std::getline(std::cin, n);
        return std::stoi(n);
    }
}