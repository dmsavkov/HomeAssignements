#include <iostream>
#include <filesystem>
#include "iostream_handler.h"

std::filesystem::path get_file_name() {
    std::filesystem::path path = "source.pdf";
    std::string input;

    std::cout << "Enter the file path (default: source.pdf): " << '\n';
    std::getline(std::cin, input);

    if (input != "") {
        path = std::filesystem::path(input);
    }

    return path;
}

