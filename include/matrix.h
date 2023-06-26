#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <compare>
#include <exception>
#include <iomanip>
#include <iostream>

class Matrix {
public:
    // Constructors
    Matrix(size_t, size_t);
    Matrix(size_t);
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<double>>);
    Matrix(const Matrix&);
    // ~Matrix() {};

    // Member Functions
    const Matrix& append(const Matrix&, int axis = 0);
    void display() const;

private:
    // Member Variables
    size_t _row {};
    size_t _column {};
    size_t _rowcap {};
    size_t _colcap {};
    double** matrix;
};

#endif // !MATRIX_H