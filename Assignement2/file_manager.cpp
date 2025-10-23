// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Implementation of file content inversion functionality

#include "file_manager.h"
#include "iostream_handler.h"
#include <fstream>
#include <filesystem>

char* get_array_from_file(const std::filesystem::path& path, int size) {
    std::ifstream filein;
    filein.open(path, std::ios::in|std::ios::binary);
    char* buffer = new char[size];
    filein.read(buffer, size);
    filein.close();
    return buffer;
}

void invert_file_content() {
    std::filesystem::path path = get_file_name();
    std::ofstream fileout;

    fileout.open("output.bin", std::ios::out | std::ios::binary);

    int file_size = std::filesystem::file_size(path);
    char* buffer = get_array_from_file(path, file_size);

    int buffer_length = file_size; // Should be the same. 
    for (int i = 0; i < buffer_length / 2; ++i) {
        int j = buffer_length - i - 1;
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    fileout.write(buffer, file_size);
    fileout.close();

    delete[] buffer;
}
