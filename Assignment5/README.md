# Assignment 5

## Author

Савков Дмитрий 25.Б81-мм

## Contacts

st140851@student.spbu.ru

## Description

Implemented **Numpy inspired** class for convenient usage by overloading operators. However, the cost is creating copies what results in unnecessary temporaries, but doesn't affect asymptotic speed.

This project contains:

- A header-only templated [`Matrix<T>`](Matrix.hpp) class with:

  - row-major storage
  - bounds and dimension validation via exceptions
  - transpose (`T()`), addition (`operator+`), scalar multiply (`operator* (scalar)`), and matrix multiply (`operator* (matrix)`)

- A simple exact-arithmetic [`Rational`](Rational.hpp) type used as an example of a custom scalar for `Matrix<T>`.

- A demo entry point in [main.cpp](main.cpp).

- Unit tests using Google Test:
  - [test_matrix.cpp](test_matrix.cpp)
  - [test_rational.cpp](test_rational.cpp)

## Project Structure

- [Matrix.hpp](Matrix.hpp) — `Matrix<T>` template implementation (header-only)
- [Rational.hpp](Rational.hpp) — `Rational` number type
- [main.cpp](main.cpp) — demo program using `Matrix<int>` and `Matrix<Rational>`
- [test_matrix.cpp](test_matrix.cpp) — GoogleTest tests for matrices
- [test_rational.cpp](test_rational.cpp) — GoogleTest tests for rationals
- [Makefile](Makefile) — build rules for demo and tests
- [run_tests](run_tests) — test binary output (built by Makefile target)

## Build

```bash
make
```

This produces:

- `matrix` — demo executable
- `run_tests` — unit test executable

## Run

```bash
./matrix
./run_tests
```
