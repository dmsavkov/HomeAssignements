// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Main entry point for Assignment 2 - binary file content reversal

#include "file_manager.h"
#include "calculator.h"
#include <iostream>

int main() {
    std::cout << "File inversion." << std::endl;
    invert_file_content();

    std::cout << "Poland calculator." << std::endl;
    calculate();
    return 0;
}