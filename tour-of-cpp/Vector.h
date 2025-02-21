#ifndef MYVECTOR
#define MYVECTOR
class Vector
{
public:
	Vector(int s);
    double& operator[](int i);
	int size();

private:
	double* elem;
	int sz;
};
#endif
