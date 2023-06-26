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
const Matrix& Matrix::append(const Matrix& m, int axis)
{
    if (axis == 1) {
        if (_column != m._column) {
            std::logic_error e { "Incompatible dimentions" };
            throw e;
        }
        size_t tmp_row { _row + m._row };
        size_t tmp_rowcap { tmp_row > 2 ? static_cast<size_t>(pow(2, static_cast<int>(log(tmp_row) / log(2)) + 1)) : 2 };
        double** tmp { new double*[tmp_rowcap] };
        for (size_t i {}; i < tmp_rowcap; i++)
            tmp[i] = new double[_colcap];
        for (size_t i {}; i < _row; i++)
            for (size_t j {}; j < _column; j++)
                tmp[i][j] = matrix[i][j];
        for (size_t i { _row }; i < tmp_row; i++)
            for (size_t j {}; j < _column; j++)
                tmp[i][j] = m.matrix[i - m._row][j];
        _row = tmp_row;
        _rowcap = tmp_rowcap;
        delete[] matrix;
        matrix = tmp;
        return *this;
    }

    if (_row != m._row) {
        std::logic_error e { "Incompatible dimentions" };
        throw e;
    }
    double** tmp { new double*[_rowcap] };
    size_t tmp_column { _column + m._column };
    size_t tmp_colcap { tmp_column > 2 ? static_cast<size_t>(pow(2, static_cast<int>(log(tmp_column) / log(2)) + 1)) : 2 };
    for (size_t i {}; i < _rowcap; i++)
        tmp[i] = new double[tmp_colcap];
    for (size_t i {}; i < _row; i++) {
        for (size_t j {}; j < _column; j++)
            tmp[i][j] = matrix[i][j];
        for (size_t j { _column }; j < tmp_column; j++)
            tmp[i][j] = m.matrix[i][j - _column];
    }
    _column = tmp_column;
    _colcap = tmp_colcap;
    delete[] matrix;
    matrix = tmp;
    return *this;
}
void Matrix::display() const
{
    for (size_t i {}; i < _row; i++) {
        for (size_t j {}; j < _column; j++)
            std::cout << std::setw(3) << matrix[i][j];
        std::cout << std::endl;
    }
}
size_t Matrix::getRowSize() const
{
    return _row;
}
size_t Matrix::getColSize() const
{
    return _column;
}
size_t Matrix::getRowCapacity() const
{
    return _rowcap;
}
size_t Matrix::getColCapacity() const
{
    return _colcap;
}
double** Matrix::getMatrix() const
{
    return matrix;
}