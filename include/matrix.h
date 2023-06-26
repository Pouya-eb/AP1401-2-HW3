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

    // Getter Functions
    size_t getRowSize() const;
    size_t getColSize() const;
    size_t getRowCapacity() const;
    size_t getColCapacity() const;
    double** getMatrix() const;

    // Operators
    Matrix operator*(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix& operator+=(Matrix);
    Matrix operator-(const Matrix&);
    // operator|
    const Matrix& operator++();
    Matrix operator++(int);

private:
    // Member Variables
    size_t _row {};
    size_t _column {};
    size_t _rowcap {};
    size_t _colcap {};
    double** matrix;
};

#endif // !MATRIX_H