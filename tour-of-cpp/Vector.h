#ifndef MYVECTOR
#define MYVECTOR
class Vector
{
public:
    Vector(int s);
    ~Vector() { delete[] elem; }

    Vector(const Vector& orig);
    Vector& operator=(const Vector rhs);

    Vector(Vector&& orig);
    Vector& operator=(Vector&& rhs);

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const { return sz; }

private:
    double* elem;
    int sz;
};

Vector operator+(const Vector& lsh, const Vector& rhs);
#endif
