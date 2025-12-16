// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Header-only templated Matrix class (row-major storage). Provides basic linear-algebra style
//              operations (transpose, addition, scalar multiplication, matrix multiplication) with
//              dimension/bounds validation via exceptions.

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>

template<typename Type>
class Matrix {
private:
    int m; // width  (number of columns)
    int n; // height (number of rows)
    std::vector<Type> matrix; // row-major: index = y * m + x

    void verifyCoordinateCompatibility(int x, int y) const {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            throw std::out_of_range("Matrix coordinate out of range");
        }
    }

    void verifyDimensionCompatibility(int newM, int newN) const {
        if (m != newM || n != newN) {
            throw std::invalid_argument("Matrix dimension mismatch");
        }
    }

public:
    Matrix(int m, int n)
        : m(m), n(n), matrix(m * n) {
        if (m <= 0 || n <= 0) {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
    }

    // indicates compiler: "default behaviour is desired"
    ~Matrix() = default;

    int getWidth() const { return m; }
    int getHeight() const { return n; }

    Type getCell(int x, int y) const {
        verifyCoordinateCompatibility(x, y);
        return matrix[y * m + x];
    }

    void setCell(const Type& value, int x, int y) {
        verifyCoordinateCompatibility(x, y);
        matrix[y * m + x] = value;
    }

    Matrix<Type> T() const {
        // this initialization is more efficient than =
        // because it doens't creat a copy to assign, but does it directly
        // it's true for all C++ initializations! E.g. x(5) instead of x = 5;
        Matrix<Type> result(n, m);

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                result.setCell(getCell(x, y), y, x);
            }
        }

        return result;
    }

    Matrix<Type> operator*(const Matrix<Type>& other) const {
        if (m != other.getHeight()) {
            throw std::invalid_argument("Matrix multiply dimension mismatch");
        }

        Matrix<Type> result(other.getWidth(), n); 

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < other.getWidth(); ++x) {
                Type sum{}; 
                for (int k = 0; k < m; ++k) {
                    sum = sum + (getCell(k, y) * other.getCell(x, k));
                }
                result.setCell(sum, x, y);
            }
        }

        return result;
    }

    Matrix<Type> operator*(const Type& scalar) const {
        Matrix<Type> result(m, n);

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                result.setCell(getCell(x, y) * scalar, x, y);
            }
        }

        return result;
    }

    Matrix<Type> operator+(const Matrix<Type>& other) const {
        verifyDimensionCompatibility(other.getWidth(), other.getHeight());

        Matrix<Type> result(m, n);

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                result.setCell(getCell(x, y) + other.getCell(x, y), x, y);
            }
        }

        return result;
    }
};

#endif