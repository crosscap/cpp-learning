#include <iostream>
using namespace std;

class Matrix
{
public:
    Matrix(int elem0, int elem1, int elem2, int elem3,
           int elem4, int elem5, int elem6, int elem7,
           int elem8, int elem9, int elemA, int elemB,
           int elemC, int elemD, int elemE, int elemF);
    Matrix(const int *array);

    ostream &print(ostream &os = cout) const;

    Matrix& operator=(const Matrix &rhs);
    Matrix& operator+(const Matrix &rhs) const;
    Matrix& operator*(const Matrix &rhs) const;

    int & operator()(int row, int col) { return _matrix[row][col]; };
    int operator()(int row, int col) const { return _matrix[row][col]; };

    void operator+=(const Matrix &rhs);

private:
    int _row, _col;
    int _matrix[4][4];
};

Matrix::Matrix(const int *array)
{
    for (int ix = 0; ix < 4; ++ix) {
        for (int jx = 0; jx < 4; ++jx, ++array)
            _matrix[ix][jx] = *array;
    }
}
Matrix::Matrix(int elem0, int elem1, int elem2, int elem3,
               int elem4, int elem5, int elem6, int elem7,
               int elem8, int elem9, int elemA, int elemB,
               int elemC, int elemD, int elemE, int elemF)
{
    _matrix[0][0] = elem0;
    _matrix[0][1] = elem1;
    _matrix[0][2] = elem2;
    _matrix[0][3] = elem3;
    _matrix[1][0] = elem4;
    _matrix[1][1] = elem5;
    _matrix[1][2] = elem6;
    _matrix[1][3] = elem7;
    _matrix[2][0] = elem8;
    _matrix[2][1] = elem9;
    _matrix[2][2] = elemA;
    _matrix[2][3] = elemB;
    _matrix[3][0] = elemC;
    _matrix[3][1] = elemD;
    _matrix[3][2] = elemE;
    _matrix[3][3] = elemF;
}

ostream &Matrix::print(ostream &os) const
{
    for (int ix = 0; ix < 4; ++ix) {
        for (int jx = 0; jx < 4; ++jx) {
            os << _matrix[ix][jx] << ' ';
        }
        os << endl;
    }
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
    for (int ix = 0; ix < 4; ++ix) {
        for (int jx = 0; jx < 4; ++jx)
            this->_matrix[ix][jx] = rhs._matrix[ix][jx];
    }

    return *this;
}

Matrix& Matrix::operator+(const Matrix &rhs) const
{
    Matrix result(*this);
    for (int ix = 0; ix < 4; ++ix) {
        for (int jx = 0; jx < 4; ++jx)
            result._matrix[ix][jx] += rhs._matrix[ix][jx];
    }
    return result;
}

Matrix& Matrix::operator*(const Matrix &rhs) const
{
    Matrix result(*this);
    for (int ix = 0, sum = 0; ix < 4; ++ix, sum = 0) {
        for (int jx = 0; jx < 4; ++jx) {
            for (int kx = 0; kx < 4; ++kx)
                 sum += _matrix[ix][kx] * rhs._matrix[kx][jx];
            result._matrix[ix][jx] = sum;
        }
    }
    return result;
}

void Matrix::operator+=(const Matrix &rhs)
{
    for (int ix = 0; ix < 4; ++ix) {
        for (int jx = 0; jx < 4; ++jx)
            _matrix[ix][jx] += rhs._matrix[ix][jx];
    }
}

inline ostream & operator<<(ostream &os, Matrix &rhs)
{ return rhs.print(os); }