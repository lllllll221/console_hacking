#include <iostream>
#include <string>

std::string ReadLine() {
    std::string user;
    getline(std::cin, user);
    return user;
}

int main() {
    for (int i = 0; i < 34; i ++) {
        std::string input = ReadLine();
        for (char c : input) {
            if (c == '\'') {
                std::cout << "\"";
                continue;   
            }
            std::cout << c;
        }
        std::cout << std::endl;
    }
    // std::cout << std::endl;
}

