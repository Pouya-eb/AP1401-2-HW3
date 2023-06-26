#include "../include/matrix.h"

Matrix::Matrix(size_t row, size_t column)
    : _row { row }
    , _column { column }
    , _rowcap { _row }
    , _colcap { column }
{
    _rowcap = _row > 2 ? pow(2, static_cast<int>(log(_row) / log(2)) + 1) : 2;
    _colcap = _column > 2 ? pow(2, static_cast<int>(log(_column) / log(2)) + 1) : 2;
    matrix = new double*[_rowcap];
    for (size_t i {}; i < _rowcap; i++)
        matrix[i] = new double[_colcap];
}
Matrix::Matrix(size_t size)
    : Matrix(size, size)
{
}
Matrix::Matrix()
    : Matrix(0)
{
}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> a)
    : Matrix(a.size(), a.begin()->size())
{
    for (size_t i {}; i < _row; i++)
        for (size_t j {}; j < _column; j++)
            matrix[i][j] = static_cast<double>(*((a.begin() + i)->begin() + j));
}
Matrix::Matrix(const Matrix& m1)
    : _row { m1._row }
    , _column { m1._column }
    , _rowcap { m1._rowcap }
    , _colcap { m1._colcap }
    , matrix { new double*[_row] }
{
    for (size_t i {}; i < _rowcap; i++)
        matrix[i] = new double[_colcap];
    for (size_t i {}; i < _row; i++)
        for (size_t j {}; j < _column; j++)
            matrix[i][j] = m1.matrix[i][j];
}
// Matrix::~Matrix()
// {
//     for (size_t i {}; i < _row; i++)
//         delete[] matrix[i];
//     delete[] matrix;
// }