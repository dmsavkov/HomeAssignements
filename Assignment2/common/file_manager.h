// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Header file for file management operations

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>

char* get_array_from_file(const std::filesystem::path& path, int size);

void invert_file_content();

#endif
