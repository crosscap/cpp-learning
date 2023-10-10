class Matrix {
public:
    Matrix (int row, int col)
        : _row(row), _col(col)
    {
        _pmat = new double[row * col];
    }

    Matrix::Matrix(const Matrix &rhs)
        : _row(rhs._row), _col(rhs._col)
    {
        int elem_cnt = _row * _col;
        _pmat = new double[elem_cnt];

        for (int ix = 0; ix < elem_cnt; ++ix) {
            _pmat[ix] = rhs._pmat[ix];
        }
    }

    ~Matrix()
    {
        delete [] _pmat;
    }

private:
    int _row, _col;
    double *_pmat;
};