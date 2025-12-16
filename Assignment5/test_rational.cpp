// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: GoogleTest suite for Rational: construction, arithmetic operators (+, *), and equality.

#include <gtest/gtest.h>
#include "Rational.hpp"

TEST(TestRational, RationalInitialization) {
    Rational k(1, 3);

    EXPECT_EQ(1, k.getNumerator());
    EXPECT_EQ(3, k.getDenumerator());
}

TEST(TestRational, RationalDefaultIsZero) {
    Rational z;
    EXPECT_EQ(0, z.getNumerator());
    EXPECT_EQ(1, z.getDenumerator());
}

TEST(TestRational, RationalBasicOperations) {
    Rational k(1, 3);
    Rational l(2, 7);

    EXPECT_EQ(k * l, Rational(2, 21));
    EXPECT_EQ(l * k, Rational(2, 21));

    EXPECT_EQ(k + l, Rational(13, 21));
    EXPECT_EQ(l + k, Rational(13, 21));
}