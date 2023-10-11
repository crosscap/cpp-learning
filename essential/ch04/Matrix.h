class Matrix
{
public:
    Matrix(int row, int col)
        : _row(row), _col(col)
    {
        _pmat = new double[row * col];
    }

    Matrix(const Matrix &rhs);

    ~Matrix()
    {
        delete[] _pmat;
    }

    Matrix& operator=(const Matrix &rhs);

private:
    int _row, _col;
    double *_pmat;
};