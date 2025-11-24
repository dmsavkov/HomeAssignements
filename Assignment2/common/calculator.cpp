// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Implementation of Reverse Polish Notation calculator

#include "calculator.h"
#include "file_manager.h"
#include <iostream>
#include "iostream_handler.h"
#include <filesystem>
#include <string>
#include <cmath>

bool validate_operation(int stack_size) {
    return stack_size >= 2;
}

bool is_operator(char element) {
    std::string operators = "+-*/";
    if (operators.find(element) == std::string::npos) {
        return false;
    }
    return true;
}

int calculate() {
    int ERROR_RETURN = -99999;
    std::filesystem::path path = get_file_name();
    int file_size = std::filesystem::file_size(path);

    // Expects a binary input file. 
    char* array = get_array_from_file(path, file_size);

    if (!array) {
        std::cerr << "Error reading file." << std::endl;
        return ERROR_RETURN;
    }

    int array_size = file_size;
    double* stack = new double[array_size];
    int stack_size = 0;

    for (int i = 0; i < array_size; ++i) {
        char element = array[i];
        std::cout << "Processing element: " << element << std::endl;
        bool is_op = is_operator(element);

        if (is_op) {
            if (!validate_operation(stack_size)) {
                std::cerr << "Invalid operation." << std::endl;
                delete[] array;  // Fixed: delete array on error
                delete[] stack;
                return ERROR_RETURN;
            }
            double b = stack[--stack_size];
            double a = stack[--stack_size];
            double result;
            char op = element;

            std::cout << "Performing: " << a << " " << op << " " << b << std::endl;

            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) {
                        std::cerr << "Division by zero." << std::endl;
                        delete[] array;  // Fixed: delete array on error
                        delete[] stack;
                        return ERROR_RETURN;
                    }
                    result = a / b; 
                    break;
                default:
                    std::cerr << "Unknown operator: " << op << std::endl;
                    delete[] array;  // Fixed: delete array on error
                    delete[] stack;
                    return ERROR_RETURN;
            }

            stack[stack_size++] = result;
            std::cout << "Pushed result: " << result << std::endl;
        } else if (element >= '0' && element <= '9') {
            double number = 0;
            bool is_floating = false;
            int j = 0;
            
            while (i < file_size && ((array[i] >= '0' && array[i] <= '9') || array[i] == '.')) {
                if (array[i] == '.') {
                    is_floating = true;
                } else if (!is_floating) {
                    number = number * 10 + (array[i] - '0');
                } else {
                    j++;
                    number += (array[i] - '0') * pow(10, -j);
                }
                i++;
            }
            i--; 
            
            stack[stack_size++] = number;
            std::cout << "Pushed number: " << number << std::endl;
        }
    }

    delete[] array;

    if (stack_size < 1) {
        std::cerr << "Error: Invalid expression." << std::endl;
        delete[] stack;
        return ERROR_RETURN;
    }

    double result = stack[stack_size - 1];
    delete[] stack;

    std::cout << "Calculation result: " << result << std::endl;
    return result;
}