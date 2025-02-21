#ifndef MYCOMPLEX
#define MYCOMPLEX

class Complex
{
    double re = 0;
    double im = 0;

public:
    Complex(double r, double i)
        : re{r}, im{i} { }
    Complex(double r)
        : re{r} { }
    double real() { return re; }
    double imag() { return im; }
    Complex& operator+=(Complex z);
    Complex& operator-=(Complex z);
    Complex& operator*=(Complex z);
    Complex& operator/=(Complex z);
};
#endif
