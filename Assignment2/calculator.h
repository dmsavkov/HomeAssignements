// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Header file for the calculator 

#ifndef CALCULATOR_H
#define CALCULATOR_H

bool is_operator(char element);

bool validate_operation(int stack_size);

int calculate();

#endif
