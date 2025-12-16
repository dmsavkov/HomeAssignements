// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: GoogleTest suite for Matrix<T> behavior: bounds checks, dimension checks, transpose,
//              addition, scalar multiply, and matrix multiply for selected element types.


#include <gtest/gtest.h>
#include "Matrix.hpp"
#include "Rational.hpp"

TEST(TestMatrix, MatrixInitializationDimensions) {
    Matrix<int> M(2, 3); 
    EXPECT_EQ(M.getWidth(), 2);
    EXPECT_EQ(M.getHeight(), 3);
}

TEST(TestMatrix, MatrixSetGetInt) {
    Matrix<int> M(3, 2);

    M.setCell(42, 0, 0);
    M.setCell(-7, 2, 1);

    EXPECT_EQ(M.getCell(0, 0), 42);
    EXPECT_EQ(M.getCell(2, 1), -7);
}

TEST(TestMatrix, MatrixTransposeInt) {
    Matrix<int> A(2, 3);
    A.setCell(1, 0, 0);
    A.setCell(2, 1, 0);
    A.setCell(3, 0, 1);
    A.setCell(4, 1, 1);
    A.setCell(5, 0, 2);
    A.setCell(6, 1, 2);

    Matrix<int> AT = A.T();

    EXPECT_EQ(AT.getWidth(), 3);
    EXPECT_EQ(AT.getHeight(), 2);

    EXPECT_EQ(AT.getCell(0, 0), 1);
    EXPECT_EQ(AT.getCell(1, 0), 3);
    EXPECT_EQ(AT.getCell(2, 0), 5);

    EXPECT_EQ(AT.getCell(0, 1), 2);
    EXPECT_EQ(AT.getCell(1, 1), 4);
    EXPECT_EQ(AT.getCell(2, 1), 6);
}

TEST(TestMatrix, MatrixScalarMultiplyDouble) {
    Matrix<double> A(2, 2);
    A.setCell(1.5, 0, 0);
    A.setCell(-2.0, 1, 0);
    A.setCell(0.25, 0, 1);
    A.setCell(4.0, 1, 1);

    Matrix<double> B = A * 2.0;

    EXPECT_DOUBLE_EQ(B.getCell(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(B.getCell(1, 0), -4.0);
    EXPECT_DOUBLE_EQ(B.getCell(0, 1), 0.5);
    EXPECT_DOUBLE_EQ(B.getCell(1, 1), 8.0);
}

TEST(TestMatrix, MatrixAddRational) {
    Matrix<Rational> A(2, 2);
    Matrix<Rational> B(2, 2);

    A.setCell(Rational(1, 2), 0, 0);
    A.setCell(Rational(1, 3), 1, 0);
    A.setCell(Rational(1, 4), 0, 1);
    A.setCell(Rational(1, 5), 1, 1);

    B.setCell(Rational(1, 2), 0, 0);
    B.setCell(Rational(2, 3), 1, 0);
    B.setCell(Rational(3, 4), 0, 1);
    B.setCell(Rational(4, 5), 1, 1);

    Matrix<Rational> C = A + B;

    // 4/4 and so one because Raional class isn't normalized 
    EXPECT_EQ(C.getCell(0, 0), Rational(4, 4));           
    EXPECT_EQ(C.getCell(1, 0), Rational(9, 9));          
    EXPECT_EQ(C.getCell(0, 1), Rational(16, 16));        
    EXPECT_EQ(C.getCell(1, 1), Rational(25, 25));        
}

TEST(TestMatrix, MatrixMultiplyInt) {
    Matrix<int> A(2, 2);
    A.setCell(1, 0, 0);
    A.setCell(2, 1, 0);
    A.setCell(3, 0, 1);
    A.setCell(4, 1, 1);

    Matrix<int> B(2, 2);
    B.setCell(5, 0, 0);
    B.setCell(6, 1, 0);
    B.setCell(7, 0, 1);
    B.setCell(8, 1, 1);

    Matrix<int> C = A * B;

    EXPECT_EQ(C.getWidth(), 2);
    EXPECT_EQ(C.getHeight(), 2);

    EXPECT_EQ(C.getCell(0, 0), 19);
    EXPECT_EQ(C.getCell(1, 0), 22);
    EXPECT_EQ(C.getCell(0, 1), 43);
    EXPECT_EQ(C.getCell(1, 1), 50);
}