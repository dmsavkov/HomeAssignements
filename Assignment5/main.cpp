// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Simple entry point demonstrating basic functionality of the Matrix and some Rational.

#include <iostream>
#include "Matrix.hpp"
#include "Rational.hpp"

void printMatrixInt(const Matrix<int>& M) {
    for (int y = 0; y < M.getHeight(); ++y) {
        for (int x = 0; x < M.getWidth(); ++x) {
            std::cout << M.getCell(x, y) << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    Matrix<int> M(2, 3);
    for (int y = 0; y < M.getHeight(); ++y) {
        for (int x = 0; x < M.getWidth(); ++x) {
            M.setCell(x * y, x, y);
        }
    }

    Matrix<int> scaled = M * 7;
    Matrix<int> transposed = M.T();

    std::cout << "M(2x3):\n";
    printMatrixInt(M);

    std::cout << "\nscaled = M * 7:\n";
    printMatrixInt(scaled);

    std::cout << "\ntransposed = M.T() (3x2):\n";
    printMatrixInt(transposed);

    Matrix<Rational> R(2, 2);
    R.setCell(Rational(1, 2), 0, 0);
    R.setCell(Rational(1, 3), 1, 0);
    R.setCell(Rational(1, 4), 0, 1);
    R.setCell(Rational(1, 5), 1, 1);

    Matrix<Rational> RR = R + R; // doesn't fail

    return 0;
}