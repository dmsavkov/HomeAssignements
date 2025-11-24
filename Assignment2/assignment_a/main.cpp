// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Main entry point for Assignment 2a - binary file content reversal

#include "../common/file_manager.h"
#include <iostream>

int main() {
    std::cout << "File inversion." << std::endl;
    invert_file_content();
    return 0;
}