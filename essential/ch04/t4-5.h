#include <iostream>
using namespace std;

class Matrix
{
    friend Matrix operator+(const Matrix&, const Matrix &);
    friend Matrix operator*(const Matrix&, const Matrix &);
public:
    Matrix(int elem0, int elem1, int elem2, int elem3,
           int elem4, int elem5, int elem6, int elem7,
           int elem8, int elem9, int elemA, int elemB,
           int elemC, int elemD, int elemE, int elemF);
    Matrix(const int *array);
    Matrix();

    ostream &print(ostream &os = cout) const;

    Matrix& operator=(const Matrix &rhs);

    int & operator()(int row, int col) { return _matrix[row][col]; };
    int operator()(int row, int col) const { return _matrix[row][col]; };

    void operator+=(const Matrix &rhs);

private:
    int _row = 4, _col = 4;
    int _matrix[4][4];
};

Matrix::Matrix(const int *array)
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx, ++array)
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

Matrix::Matrix()
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx)
            _matrix[ix][jx] = 0;
    }
}

ostream &Matrix::print(ostream &os) const
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx) {
            os << _matrix[ix][jx] << ' ';
        }
        os << endl;
    }
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx)
            _matrix[ix][jx] = rhs._matrix[ix][jx];
    }

    return *this;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix result(m1);
    result += m2;
    return result;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    int sum;
    Matrix result;
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

void Matrix::operator+=(const Matrix &rhs)
{
    for (int ix = 0; ix < _row; ++ix) {
        for (int jx = 0; jx < _col; ++jx)
            _matrix[ix][jx] += rhs._matrix[ix][jx];
    }
}

inline ostream & operator<<(ostream &os, Matrix &rhs)
{ return rhs.print(os); }