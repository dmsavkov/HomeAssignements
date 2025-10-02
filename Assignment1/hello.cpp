#include <iostream>
#include "hello.h"

void print_hello() {
    std::cout << "Hello world!" << std::endl;

    bool infinite_loop = true;
    std::string prefix = "Hello, ";
    char suffix = '!';

    while (infinite_loop) {
        std::string input;
        std::getline(std::cin, input);

        std::string message = prefix + input + suffix;
        std::cout << message << std::endl;
    }
}