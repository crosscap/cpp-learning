#include "Vector.h"
#include <stdexcept>

Vector::Vector(int s)
{
    if (s < 0) {
        throw std::length_error{"Vector::Vector"};
    }
    elem = new double[s];
    sz = s;
}

Vector::Vector(const Vector& orig)
    : elem{new double[orig.sz]}, sz{orig.sz}
{
    for (int i = 0; i != sz; ++i)
        elem[i] = orig.elem[i];
}

Vector& Vector::operator=(const Vector rhs)
{
    double* p = new double[rhs.sz];
    for (int i = 0; i != sz; ++i)
        elem[i] = rhs.elem[i];
    delete[] elem;
    elem = p;
    sz = rhs.sz;
    return *this;
}

Vector::Vector(Vector&& orig)
    : elem{orig.elem}, sz{orig.sz}
{
    orig.elem = nullptr;
    orig.sz = 0;
}

Vector& Vector::operator=(Vector&& rhs)
{
    if (this != &rhs) {
        delete[] elem;
        elem = rhs.elem;
        sz = rhs.sz;
        rhs.elem = nullptr;
        rhs.sz = 0;
    }
    return *this;
}

double& Vector::operator[](int i)
{
    if (i < 0 || i >= sz) {
        throw std::out_of_range{"Vector::operator[]"};
    }
    return elem[i];
}

const double& Vector::operator[](int i) const
{
    return operator[](i);
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    if (lhs.size() != rhs.size())
        throw std::runtime_error{"Vector operator+"};
    Vector res(lhs.size());
    for (int i = 0; i != res.size(); ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}
