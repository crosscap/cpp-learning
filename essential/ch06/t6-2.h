#include <iostream>
using namespace std;

template <typename elemType>
class Matrix
{
    friend Matrix operator+(const Matrix<elemType> &, const Matrix<elemType> &);
    friend Matrix operator*(const Matrix<elemType> &, const Matrix<elemType> &);
public:
    Matrix(int, int);
    Matrix(const elemType *array, int row, int col);
    Matrix(const Matrix<elemType> &rhs);
    ~Matrix();

    ostream &print(ostream &os = cout) const;

    Matrix& operator=(const Matrix &rhs);
    void operator+=(const Matrix &rhs);

    elemType & operator()(int row, int col) { return _matrix[row][col]; }
    elemType operator()(int row, int col) const { return _matrix[row][col]; }

    int row() { return _row; }
    int col() { return _col; }

private:


    int _row, _col;
    elemType _matrix*;
};

template <typename elemType>
Matrix<elemType>::Matrix(int row, int col)
    : _row(row), _col(col)
{
    _matrix = new elemType[row][col];
    for (int ix = 0; ix < row; ++ix) {
        for (int jx = 0; jx < col; ++jx)
            _matrix[ix][jx] = elemType();
    }
}

template <typename elemType>
Matrix<elemType>::Matrix(const elemType *array, int row, int col)
    : _row(row), _col(col)
{
    _matrix = new elemType[row][col];
    for (int ix = 0; ix < row; ++ix) {
        for (int jx = 0; jx < col; ++jx, ++array)
            _matrix[ix][jx] = *array;
    }
}

template <typename elemType>
Matrix<elemType>::Matrix(const Matrix<elemType> &rhs)
{
    elemType *pt;
    _matrix = new elemType[rhs._row][rhs._col];
    pt = rhs._matrix;
    for (int ix = 0; ix < rhs._row; ++ix) {
        for (int jx = 0; jx < rhs._col; ++jx, ++pt)
            _matrix[ix][jx] = *pt;
    }
}

template <typename elemType>
Matrix<elemType>::~Matrix()
{
    delete _matrix;
}

template <typename elemType>
ostream &Matrix<elemType>::print(ostream &os) const
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx) {
            os << _matrix[ix][jx] << ' ';
        }
        os << endl;
    }
}

template <typename elemType>
Matrix<elemType>& Matrix<elemType>::operator=(const Matrix<elemType> &rhs)
{
    if (this != &rhs) {
        delete _matrix;
        _matrix = new elemType[rhs._row][rhs._col];
        for (int ix = 0; ix < _row; ++ix) {
            for (int jx = 0; jx < _col; ++jx)
                _matrix[ix][jx] = rhs._matrix[ix][jx];
        }
    }
    return *this;
}

template <typename elemType>
void Matrix<elemType>::
operator+=(const Matrix<elemType> &rhs)
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx)
            _matrix[ix][jx] += rhs._matrix[ix][jx];
    }
}

template <typename elemType>
inline ostream & operator<<(ostream &os, Matrix<elemType> &rhs)
{ return rhs.print(os); }


template <typename elemType>
Matrix<elemType>
operator+(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{
    Matrix<elemType> result(m1);
    result += m2;
    return result;
}

template <typename elemType>
Matrix<elemType>
operator*(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{
    int sum;
    Matrix<elemType> result(m1.row(), m2.col());
    for (int ix = 0, sum = 0; ix < m1._row; ++ix) {
        for (int jx = 0; jx < m2._col; ++jx) {
            sum = 0;
            for (int kx = 0; kx < m1._col; ++kx)
                 sum += m1(ix, kx) * m2(kx, jx);
            result._matrix[ix][jx] = sum;
        }
    }
    return result;
}
