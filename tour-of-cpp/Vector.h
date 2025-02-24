#ifndef MYVECTOR
#define MYVECTOR

#include <stdexcept>

template <typename T>
class Vector
{
public:
    explicit Vector(int s);
    Vector(std::initializer_list<T> lst)
        : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    ~Vector() { delete[] elem; }

    Vector(const Vector& orig);
    Vector& operator=(const Vector rhs);

    Vector(Vector&& orig);
    Vector& operator=(Vector&& rhs);

    T& operator[](int i);
    const T& operator[](int i) const;

    int size() const { return sz; }

    T* begin() { return &elem[0]; }
    const T* begin() const { return &elem[0]; }
    T* end() { return &elem[0] + size(); }
    const T* end() const { return &elem[0] + size(); }

private:
    T* elem;
    int sz;
};

template <typename T>
Vector<T> operator+(const Vector<T>& lsh, const Vector<T>& rhs);

template <typename T>
Vector<T>::Vector(int s)
{
    if (s < 0) {
        throw std::length_error{"Vector::Vector"};
    }
    elem = new double[s];
    sz = s;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& orig)
    : elem{new double[orig.sz]}, sz{orig.sz}
{
    for (int i = 0; i != sz; ++i)
        elem[i] = orig.elem[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> rhs)
{
    double* p = new double[rhs.sz];
    for (int i = 0; i != sz; ++i)
        elem[i] = rhs.elem[i];
    delete[] elem;
    elem = p;
    sz = rhs.sz;
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& orig)
    : elem{orig.elem}, sz{orig.sz}
{
    orig.elem = nullptr;
    orig.sz = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
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

template <typename T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || i >= sz) {
        throw std::out_of_range{"Vector::operator[]"};
    }
    return elem[i];
}

template <typename T>
const T& Vector<T>::operator[](int i) const
{
    return operator[](i);
}

template <typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        throw std::runtime_error{"Vector operator+"};
    Vector<T> res(lhs.size());
    for (int i = 0; i != res.size(); ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}

#endif
